#include <iostream>
#include <vector>

void printArr(std::vector<int> arr) {
    for (int val: arr)
        std::cout << val << ' ';
    std::cout << '\n';
}

void insertionSort(std::vector<int> &arr) {
    for (int step = 1; step < arr.size(); step++) {
        int key = arr[step];
        int j = step - 1;
        
        while (key < arr[j] && j >= 0) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
        printArr(arr);
    }
}

int main() {
    std::vector<int> arr{9, 5, 1, 4, 3};
    insertionSort(arr);
    printArr(arr);
    return 0;
}