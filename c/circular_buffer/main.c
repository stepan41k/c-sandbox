#include <stdbool.h>
#include <stdio.h>

#define SIZE 5

typedef struct {
  int data[SIZE];
  int head;
  int tail;
  int count;
} CircularBuffer;

bool push(CircularBuffer *cb, int value) {
  if (cb->count == SIZE) {
    printf("Буфер переполнен\n");
    return false;
  }
  cb->data[cb->tail] = value;
  cb->tail = (cb->tail + 1) % SIZE;
  cb->count++;
  return true;
}

bool pop(CircularBuffer *cb, int *value) {
  if (cb->count == 0) {
    printf("Буфер пуст\n");
    return false;
  }
  *value = cb->data[cb->head];
  cb->head = (cb->head + 1) % SIZE;
  cb->count--;
  return true;
}

int main() {
  CircularBuffer myBuf = {.head = 0, .tail = 0, .count = 0};
  int val;

  push(&myBuf, 10);
  push(&myBuf, 20);
  push(&myBuf, 30);
  push(&myBuf, 40);
  push(&myBuf, 50);

  push(&myBuf, 60);

  pop(&myBuf, &val);
  printf("Извлечено: %d\n", val);
  pop(&myBuf, &val);
  printf("Извлечено: %d\n", val);

  printf("Добавляем 60 и 70\n");
  push(&myBuf, 60);
  push(&myBuf, 70);

  printf("Текущее количество элементов: %d\n", myBuf.count);

  return 0;
}
