#include <stdio.h>
#include <stdlib.h>
#define MAX 5

int front = -1;
int rear = -1;
int q[MAX];

void insert();
void pop();
void display();

int main() {
  int ch;
  while (1) {
    printf("\n\nMenu\n1.Insert\n2.Delete\n3.Display\n4.exit");
    printf("\nEnter your choice:\t");
    scanf("%d", &ch);
    switch (ch) {
    case 1:
      insert();
      display();
      break;
    case 2:
      pop();
      display();
      break;
    case 3:
      display();
      break;
    case 4:
      exit(0);
    default:
      printf("\nInvalid Choice\n");
    }
  }
}

void insert() {
  int item;
  if (rear == MAX - 1) {
    printf("\n~~~Queue Overflow~~~");
    return;
  }

  printf("\nEnter the item to to be inserted:");
  scanf("%d", &item);

  rear = rear + 1;
  q[rear] = item;
}

void pop() {
  int item;
  if (front == rear) {
    printf("\n~~~Queue Underflow~~~");
    return;
  }
  front = front + 1;
  item = q[front];
  printf("\nThe item that got deleted is: %d", item);
}

void display() {
  int i;
  printf("\nfront = %d, rear = %d", front, rear);
  if (front == rear) {
    printf("\nQueue is empty\n");
    return;
  } else {

    printf("\nElements of the queue are: ");
    for (i = front + 1; i <= rear; i++)
      printf("%d\t", q[i]);
  }
}