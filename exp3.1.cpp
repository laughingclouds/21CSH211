#include <iostream>

struct node {
  int data;
  struct node *next;
};
struct node *front = NULL;
struct node *rear = NULL;
struct node *temp;
void Insert() {
  int val;
  std::cout << "Insert the element in queue : " << '\n';
  std::cin >> val;
  if (rear == NULL) {
    rear = (struct node *)malloc(sizeof(struct node));
    rear->next = NULL;
    rear->data = val;
    front = rear;
  } else {
    temp = (struct node *)malloc(sizeof(struct node));
    rear->next = temp;
    temp->data = val;
    temp->next = NULL;
    rear = temp;
  }
}
void Delete() {
  temp = front;
  if (front == NULL) {
    std::cout << "Underflow Occured" << '\n';
    return;
  } else if (temp->next != NULL) {
    temp = temp->next;
    std::cout << "Element deleted from queue is : " << front->data << '\n';
    free(front);
    front = temp;
  } else {
    std::cout << "Element deleted from queue is : " << front->data << '\n';
    free(front);
    front = NULL;
    rear = NULL;
  }
}
void Display() {
  temp = front;
  if ((front == NULL) && (rear == NULL)) {
    std::cout << "Queue is empty" << '\n';
    return;
  }
  std::cout << "Queue elements are : \n";
  while (temp != NULL) {
    std::cout << temp->data << " ";
    temp = temp->next;
  }
  std::cout << '\n';
}
int main() {
  int ch;
  std::cout << "1) To Insert an element into linked queue" << '\n';
  std::cout << "2) To Delete an element from linked queue" << '\n';
  std::cout << "3) To Display all the elements present in linked queue" << '\n';
  std::cout << "4) Exit" << '\n';
  do {
    std::cout << "\nEnter your choice : " << '\n';
    std::cin >> ch;
    switch (ch) {
    case 1:
      Insert();
      break;
    case 2:
      Delete();
      break;
    case 3:
      Display();
      break;
    case 4:
      std::cout << "Exit" << '\n';
      break;
    default:
      std::cout << "!! Invalid choice !! Please enter a valid one" << '\n';
    }
  } while (ch != 4);
  return 0;
}