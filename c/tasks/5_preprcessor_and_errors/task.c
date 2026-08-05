#include <stdio.h>
#define MAX_NAME 50

typedef struct {
    int id;
    char name[MAX_NAME];
    float salary;
} Employee;

Employee* create_employee(int id, char* name, float salary) {
    
}

int main() {
    Employee e = {1, "Igor", 15000.0};
    printf("%ld\n", sizeof(Employee));
}