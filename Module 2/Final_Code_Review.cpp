#include<iostream>
#include<memory>

int main()
{

    // References and Pointers

    // References: Like a second name of an existing variable, meaning we can operate on the object
    // with no data duplication from the original.
    // They are immutable, so they simplify parameter passing a lot.

    int number = 10;
    int &ref = number; // ref is a reference to number
    ref += 5; // number = 15


    // Pointers: Enable direct control over memory addresses, allowing dynamic manipulation
    // and traversal of complex structures like arrays and linked lists.

    int number = 20;
    int *ptr = &number; // Pointer 'ptr' pointing to 'number'
    *ptr += 2; // changes 'number' to 22
    // Pointer Arithmetic Example:

    int arr[] = {10, 20, 30};
    int *p = arr;
    std::cout << *(p + 1); // Outputs 20
    
    // Dynamic Memory Management
    // C++ offers powerful mechanisms, creating flexible and scalable apps

    int *numPtr = new int(5); // Allocates memory for an int
    delete numPtr; // Deallocated memory

    // Smart Pointers
    // Unique_ptr: Ensures exclusive ownership of a resource,
    // ensuring no other controller can interfere. It automatically
    // handles resource deallocation when scope ends.
    std::unique_ptr<int> uptr(new int(100));

    // Shared_ptr and Weak_ptr:

    // Shared_ptr: Allows multiple ownerships by maintaining a reference count.
    auto sptr = std::make_shared<int>(200);

    // Weak_ptr: Avoids reference cycles that
    // can cause memory leaks by allowing reference without owning.
    std::weak_ptr<int> wptr(sptr);


    // Practical Applications and Best Practices

    // References: Streamline function design by passing arguments by reference to enhance performance without sacrificing the ability to alter original data.

    // Pointers: Optimize data handling in complex data structures by using pointers judiciously, ensuring stability and integrity.

    // Smart Pointers: Modernize legacy codebases by adopting smart pointers over raw pointers, simplifying memory management and reducing bugs.

    // Common Pitfalls and Prevention Strategies

    // Memory Leaks: Tools like Valgrind help identify leaks, stressing the importance of pairing each new with a delete.

    // Dangling Pointers: Occur when pointers access deleted memory. Prevent this by resetting pointers to nullptr post-deletion:

        delete ptr;
        ptr = nullptr;

    // Avoiding Uninitialized Pointers: Initialize pointers with a valid address or nullptr to circumvent access violations.

    return 0;
}