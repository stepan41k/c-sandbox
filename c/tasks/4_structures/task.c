#include <stdio.h>

typedef struct {
    int id;
    char name[32];
    long long int rows;
} Table;

void print_table(Table *t) {
    printf("ID: %d, Name: %s, Rows: %lld\n", t->id, t->name, t->rows);
    
    return;
}

int main() {
    Table tables[3] = {{1, "users", 123}, {2, "credentials", 124}, {3, "messages", 125}};

    for (int i = 0; i < 3; i++) {
        print_table(&tables[i]);
    }

    return 0;
}
