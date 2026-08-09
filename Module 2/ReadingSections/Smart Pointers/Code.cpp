#include<memory>
#include<iostream>
#include<cstdio>

using namespace std;

// Smart pointers simplify and secure memory handlingby automating allocation/deallocation
// Enhances code safety + performance


// Unique_ptr:
// Needed for exclusive ownership. Only 1 pointer can point to a resource at any time
// Automatically releases the resource when unique_ptr is destroyed
void processResource(){
    unique_ptr<int> uniquePtr(new int(42));
    cout << "Resource Value: " << *uniquePtr << endl;
}
// unique_ptr ensures that the resource is safely and automatically deallocated
// the moment it falls out of scope, as per RAII


// Shared_ptr:
// Multiple stakeholders need simultaneous access to the same resource
// With reference counting, it ensures the resource is released <=> last process finishes

void shareResource(){
    auto sharedPtr1 = std::make_shared<int>(42);
    {
        auto sharedPtr2 = sharedPtr1; // Shared ownership
        cout << "Resource Value in Inner Scope: " << sharedPtr2 << endl;
        // sharedPtr2 goes out of scope, resource is not deleted
    }
    cout << "Resource Value in Outer Scope: " << sharedPtr1 << endl;
    // Resource is deleted here, sharedPtr1 goes out of scope, AKA all of them finished
}
// shared_ptr allows for simultaneous references, enhancing safe shared access and
// it automates cleanup with no references remaining.


// Weak_ptr:
// Safeguard against circular dependencies that can occur with shared_ptr. Observes without
// owning any resources, so no ownership loops for resources.

void observeResource(){
    shared_ptr<int> sharedPtr = make_shared<int>(42);
    weak_ptr<int> weakPtr(sharedPtr);
    if(auto lockedPtr = weakPtr.lock()){
        cout << "Resource accessed through weak_ptr: " << *lockedPtr << endl;
    } else {
        cout << "Resource no longer exists." << endl;
    }
}

// Implementing RAII with Smart Pointers

// RAII (Resource Acquisition Is Initialization) leverages object lifetimes for automatic
// memory management. Coupled with smart pointers, RAII can greatly enhance code reliability
// by linking resource management with object scope.
// Automatic Cleanup and Safety

// Smart pointers inherently embody RAII, allowing memory to be automatically released
// once the pointer goes out of scope. This automation removes the burden from developers,
// preventing memory leaks and dangling pointers with ease.
// Custom Deleters: Tailoring Resource Cleanup

// Smart pointers aren't restrained to default deletion.
// Custom deleters give you control to specify how resources are released,
// making them invaluable for managing non-standard resources like files or sockets.

void deleteFile(FILE* f) {
    if (f) fclose(f);
}
int main() {
    std::unique_ptr<FILE, decltype(&deleteFile)> filePtr(fopen("file.txt", "w"), &deleteFile);
    if(filePtr) {
        fprintf(filePtr.get(), "Writing to file.\n");
    }
} // The file is closed automatically when 'filePtr' goes out of scope




// Transforming Legacy Code: A Smart Pointer Initiative

// Migrating from raw pointers to smart pointers modernizes and stabilizes your code.
// Here are strategies to refactor effectively:

//     Replace new/delete pairs with unique_ptr for exclusive ownership cases.

//     Use shared_ptr wherever shared resource access is required.

//     Adopt weak_ptr judiciously to avoid circular references.