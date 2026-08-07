// RAII = Resource Acquisition Is Initialization

// Resource management is alligned with object lifecycles
// When object is created, resources get allocated
// When object is destroyed, resources get repurposed
// Needed for C++ to ensure no resource leaking happens, since the lang does not have
// built in object cleaners

#include<iostream>

class SoundBuffer{
    char* buffer; // Pointer representation in C++

public:

    // buffer(new char[size]) requests a fresh block of memory from the heap that is big
    // enough to hold characters of length/size of size_t size.
    // buffer points to the first element of an array of size characters on the heap

    SoundBuffer(size_t size) : buffer(new char[size]){
        std::cout << "Buffer of " << size << " bytes allocated." << '\n';
    }
    
    // new char[size] creates a new pointer and that pointer takes the resources and hogs them
    // therefore, they are never released
    // delete[] buffer is needed to allow the resources that are hogged by the pointer to be used
    // new char[size] (array of chars of length size) -> freed with delete[] buffer
    // new char (single object) -> freed with delete buffer


    ~SoundBuffer(){
        delete[] buffer;
        std::cout << "Buffer released." << '\n';
    }

};

// Modern C++ uses smart pointers to automate this process

int main(){
    //EXAMPLE:

    SoundBuffer sb(1024);

    // What happens:
    // 1. Triggers constructor => allocating 1024 bytes on the heap
    // 2. After finish, object is destroyed, calls delete[] buffer to delete the pointer
    // => freeing up the 1024 bytes that were occupied by the pointer
}