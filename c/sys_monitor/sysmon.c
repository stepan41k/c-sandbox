#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/statvfs.h>
#include <unistd.h>

typedef struct {
    unsigned long long user, nice, system, idle, iowait, irq, softirq, steal;
} CPUData;

void get_cpu_data(CPUData *data) {
    FILE *fp = fopen("/proc/stat", "r");
    if (!fp)
        return;
    char buffer[256];
    if (fgets(buffer, sizeof(buffer), fp)) {
        sscanf(buffer, "cpu %llu %llu %llu %llu %llu %llu %llu %llu",
               &data->user, &data->nice, &data->system, &data->idle,
               &data->iowait, &data->irq, &data->softirq, &data->steal);
    }
    fclose(fp);
}

// CPU
double get_cpu_usage_fast() {
    static CPUData prev = {0};
    CPUData curr;
    get_cpu_data(&curr);

    if (prev.user == 0 && prev.idle == 0) {
        prev = curr;
        return 0.0;
    }

    unsigned long long total1 = prev.user + prev.nice + prev.system +
                                prev.idle + prev.iowait + prev.irq +
                                prev.softirq + prev.steal;
    unsigned long long total2 = curr.user + curr.nice + curr.system +
                                curr.idle + curr.iowait + curr.irq +
                                curr.softirq + curr.steal;

    unsigned long long idle1 = prev.idle + prev.iowait;
    unsigned long long idle2 = curr.idle + curr.iowait;

    double total_diff = (double)(total2 - total1);
    double idle_diff = (double)(idle2 - idle1);

    prev = curr;

    if (total_diff == 0)
        return 0.0;
    return ((total_diff - idle_diff) / total_diff) * 100.0;
}

// RAM
void print_ram_info() {
    FILE *fp = fopen("/proc/meminfo", "r");
    if (!fp)
        return;

    char line[256];
    unsigned long long total_kb = 0, avail_kb = 0;

    while (fgets(line, sizeof(line), fp)) {
        if (sscanf(line, "MemTotal: %llu kB", &total_kb) == 1)
            continue;
        if (sscanf(line, "MemAvailable: %llu kB", &avail_kb) == 1)
            continue;
    }
    fclose(fp);

    unsigned long long used_kb = total_kb - avail_kb;
    double total_gb = (double)total_kb / (1024 * 1024);
    double used_gb = (double)used_kb / (1024 * 1024);
    double usage_percent = ((double)used_kb / total_kb) * 100.0;

    printf("RAM:          %6.2f GB / %6.2f GB (Used: %4.1f%%)\n", used_gb,
           total_gb, usage_percent);
}

// DISK
void print_disk_info(const char *path) {
    struct statvfs stat;
    if (statvfs(path, &stat) != 0)
        return;

    unsigned long long total_bytes = stat.f_blocks * stat.f_frsize;
    unsigned long long free_bytes = stat.f_bavail * stat.f_frsize;
    unsigned long long used_bytes = total_bytes - free_bytes;

    double total_gb = (double)total_bytes / (1024 * 1024 * 1024);
    double used_gb = (double)used_bytes / (1024 * 1024 * 1024);
    double usage_percent = ((double)used_bytes / total_bytes) * 100.0;

    printf("Disk (%s):      %6.2f GB / %6.2f GB (Used: %4.1f%%)\n", path,
           used_gb, total_gb, usage_percent);
}

int main() {
    while (1) {
        printf("\033[H\033[J");

        printf(" -- SYSTEM MONITOR -- \n\n");

        print_ram_info();
        print_disk_info("/");

        double cpu_usage = get_cpu_usage_fast();
        printf("CPU usage:   %6.1f%%\n", cpu_usage);

        printf("\nPress Ctrl+C to exit...\n");

        fflush(stdout);

        sleep(1);
    }

    return 0;
}
