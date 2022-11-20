/*demonstrate the use of linear and binary search to search a given element
in an array*/
#include <iostream>
#include <string>
#include <vector>

/*Check if given vector is sorted in ascending order*/
bool isAscSorted(std::vector<int> arr) {
  for (int i = 0; i < arr.size() - 1; i++) {
    if (arr[i] > arr[i + 1])
      return false;
  }
  return true;
}

/*Linearly traverse array and return index of 'x' if found.
Else return -1*/
int linear_search(std::vector<int> arr, int x) {
  for (int i = 0; i < arr.size(); i++) {
    if (arr[i] == x) {
      return i;
    }
  }
  return -1;
}

/* Search for element x using binary search algorithm.
Return -1 if not found.
Assume given vector/array is sorted.*/
int binary_search(std::vector<int> arr, int x) {
  // left most and right most indices
  int left = 0, right = arr.size() - 1;

  while (left <= right) {
    // to prevent integer overflow
    int mid = left + (right - left) / 2;

    if (arr[mid] == x)
      return mid;

    if (arr[mid] > x)
      right = mid - 1;
    else
      left = mid + 1;
  }
  return -1;
}

int main() {
  int len;
  int x;
  int position;
  std::cout << "Enter array length: ";
  std::cin >> len;

  std::vector<int> arr(len);

  std::cout << "Enter array: ";
  for (int i = 0; i < len; i++) {
    std::cin >> arr[i];
  }

  std::cout << "Enter element to search: ";
  std::cin >> x;

  char choice;
  std::cout
      << "Use\na) Linear Search \t b) Binary Search (array must be sorted)\n";
  std::cout << "Your choice: ";
  std::cin >> choice;

  switch (choice) {
  case 'a':
  case 'A':
    position = linear_search(arr, x);
    break;

  case 'b':
  case 'B':
    if (!isAscSorted(arr)) {
      std::cout << "Given array is not sorted. Using linear search\n";
      position = linear_search(arr, x);
      break;
    }
    position = binary_search(arr, x);
    break;
  default:
    std::cout << "Invalid Input. Using linear search\n";
    position = linear_search(arr, x);
  }

  std::cout << (position == -1
                    ? "Element doesn't exist in array"
                    : "Element is in position: " + std::to_string(position));
  std::cout << '\n';
}