/*menu driven program to implement various operations on a linear array*/
#include <iostream>
#define MAX_CAPACITY 10

int arr[MAX_CAPACITY];
unsigned int len = 0;

/**
1) shift elements to the right
2) insert element at position
*/
void insert(int position, int element) {
  if (len == MAX_CAPACITY) {
    std::cout << "Array is full\n";
    return;

  } else if (position >= MAX_CAPACITY || position > len) {
    std::cout << "Invalid value for position\n";
    return;
  }

  if (len != 0) {
    // shift to the right
    for (int k = len - 1; k >= position; k--) {
      arr[k + 1] = arr[k];
    }
  }

  arr[position] = element;
  len++;
}

/**
shift all elements to the left by one step
*/
void delete_at(int position) {
  if (len == 0) {
    std::cout << "Array is empty\n";
    return;

  } else if (position >= len) {
    std::cout << "Invalid value for position\n";
    return;
  }

  for (int k = position; k < len; k++) {
    arr[k] = arr[k + 1];
  }

  len--;
}

void insert_at_start() {
  int element;
  std::cout << "Enter element: ";
  std::cin >> element;

  insert(0, element);
}

void insert_at_position() {
  int position, element;

  std::cout << "Enter position: ";
  std::cin >> position;

  std::cout << "Enter element: ";
  std::cin >> element;

  insert(position, element);
}

void delete_by_position() {
  int position;
  std::cout << "Enter position: ";
  std::cin >> position;

  delete_at(position);
}

void delete_by_value() {
  int position = -1, value;
  std::cout << "Enter value: ";
  std::cin >> value;

  for (int k = 0; k < len; k++) {
    if (arr[k] == value) {
      position = k;
      break;
    }
  }

  if (position != -1) {
    delete_at(position);
  }
}

void display_elements() {
  if (len == 0) {
    std::cout << "No elements in array\n";
    return;
  }

  std::cout << "Elements: ";
  for (int i = 0; i < len; i++) {
    std::cout << arr[i] << ' ';
  }

  std::cout << '\n';
}

int main() {
  // print menu
  std::cout << "Select one of the following\n"
               "1) Add new element\n\t a) At the beginning\t b) At a position\n"
               "2) Delete using\n\t a) Value\t b) Position\n"
               "3) Display elements\n"
               "4) Exit\n";

  while (true) {
    char choice;

    std::cout << "\nEnter your choice: ";
    std::cin >> choice;

    switch (choice) {
    case '1':
      std::cout << "(a)At the beginning/(b)At a position? ";
      std::cin >> choice;

      switch (choice) {
      case 'a':
        insert_at_start();
        break;
      case 'b':
        insert_at_position();
        break;
      }

      break;
    case '2':
      std::cout << "(a)Value/(b)Position? ";
      std::cin >> choice;

      switch (choice) {
      case 'a':
        delete_by_value();
        break;
      case 'b':
        delete_by_position();
        break;
      }

      break;
    case '3':
      display_elements();
      break;
    case '4':
      return 0;
    default:
      std::cout << "Invalid Input\n";
    }
  }
}