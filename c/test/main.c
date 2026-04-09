#include <stdio.h>

int main() {
    int number1, number2, sum;
    
    printf("Введите первое число: ");
    scanf("%d", &number1);
    
    printf("Введите второе число: ");
    scanf("%d", &number2);
    
    sum = number1 + number2;
    
    printf("Сумма двух чисел равна: %d\n", sum);
    
    return 0;
}