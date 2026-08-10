#include <iostream>

int main() {
    int size = 5;

    // Dynamically allocate an array of integers
    int* arr = new int[size];

    // Initialize the array with values
    for (int i = 0; i < size; i++) {
        arr[i] = i * 10;
    }

    // Print the array contents
    std::cout << "Array contents: ";
    for (int i = 0; i < size; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    // Properly deallocate the array
    delete[] arr;
    arr = nullptr; // avoid dangling pointer

    return 0;
}