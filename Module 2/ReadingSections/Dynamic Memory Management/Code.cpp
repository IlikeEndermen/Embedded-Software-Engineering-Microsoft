// Basics of Allocation
// The new operator creates a dynamic memory allocation, giving access to memory on
// the heap at runtime. Static memory is limited in scope/flexibility

#include <iostream>

int main()
{
	int* arr = new int[5]; // Allocate an array of 5 integers
    int val = 3;
    int* ptr = &val;

	// Use the array (example initialization)
	for (int i = 0; i < 5; ++i)
		arr[i] = i * 10;

	// When finished with the allocated memory, deallocation is needed so no memory leaks
	// happen. delete and delete[] operators are used.
	delete[] arr; // Deallocate the array

    // 3 common issues with dynamic memory allocation:

    // 1. Memory Leaks: Allocated memory is not deallocated. 
    // Same number of allocations and deletions must exist.

    // 2. Dangling Pointers: Pointers that refer to memory that was freed/deleted.
    // This leads to undefined behaviour/crashes

    // 3. Double Deletion: Release memory that was already freed => memory corruption
    // leading to runtime errors.

    // Solutions to the issues:
    
    // 1. Ballanced Alloc/Dealloc: Same number of new and delete types

    // 2. Avoid Null Dereferencing: Always check if a pointer is not null before deletion

    if(ptr != nullptr){
        delete ptr;
    }

    // 3. Smart Pointers: unique_ptr and shared_ptr in modern C++. They automatically manage
    // memory, reduces the previous issues a lot.

    // 4. RAII: With Constructors and Deconstructors.

	return 0;
}

