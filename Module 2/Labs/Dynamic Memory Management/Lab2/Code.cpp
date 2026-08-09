#include <iostream>
#include <map>
#include <ctime>
#include <fstream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

// ========================================
// STEP 1: Memory Manager Class Definition
// ========================================

class MemoryManager {
private:
    // TODO: Define data structures to track memory allocations
    // Hint: Consider using a map to store address -> allocation info
    
    struct AllocationInfo {
        size_t size;
        time_t timestamp;
        int* uuid;
        bool isArrayAlloc; // Tracks which allocator/deallocator pair to use

        AllocationInfo(size_t& s, bool isArray = false) : size(s) {
           uuid = nullptr; 
           timestamp = time(nullptr);
           isArrayAlloc = isArray;
        }

    };


    // KEY = allocated address (UUID)
    // VALUE = metadata (stored by value, not pointer)
    unordered_map<void*, AllocationInfo> allocations;


    int totalAllocations;
    int totalDeallocations;
    int currentBytes;
    int peakBytes;

public:
    MemoryManager() : totalAllocations(0), totalDeallocations(0), currentBytes(0), peakBytes(0) {
        cout << "Memory management started" << endl;
    }
    
    ~MemoryManager() {
        cout << "\nMemory Manager destructor called - deallocating the memory..." << endl;
        for (auto& entry : allocations){
            void* address = entry.first;
            cout << "Deallocated the memory with UUID: " << address << endl;
            free(address);
        }

        reportLeaks();
        allocations.clear();
    }
    
    // Method to allocate memory and track it
    // A single object allocation (malloc/new)
    void* allocateMemory(size_t size) {

        if(size == 0){
            cout << "Error: Can't allocate memory of " << size << " KB..." << endl;
            return nullptr;
        }

        int* ptr = static_cast<int*>(malloc(size * sizeof(int)));

        if (ptr == nullptr){
            cout << "✗ Allocation failed for dataset of " << size << " KB." << endl;
            return nullptr;
        }

            for (size_t i = 0; i < size; i++){
                ptr[i] = (((19 + i) + 133) * ((size * 5) / 7)) * 52;
            }

            AllocationInfo info(size);
            info.uuid = ptr;
            allocations.emplace(ptr, info); // Insert into the map, keyed by address
            totalAllocations++;

            cout << "✓ Allocated memory with UUID: " << ptr << "' with " << size << " KB." << endl;
            currentBytes = (int)(size * 1024);
            peakBytes = max(peakBytes, (int)(size*1024));

            return ptr;

    }
    
    // Method to deallocate memory and update tracking
    void deallocateMemory(void* ptr) {

        auto it = allocations.find(ptr);

        if (it == allocations.end()){
            cout << "✗ Error: Memory at pointer '" << ptr << "' not found for deallocation!" << endl;
            return;
        }

        cout << "Deallocation at pointer " << ptr << " started..." << endl;

        size_t freedSize = it->second.size; // grab size before erasing it
        free(ptr);
        
        // This is to remove the listing from the allocations map as well, so there 
        // can't be any repeated deletions by accident at all.
        // There is no double deletion possible
        allocations.erase(it);

        totalDeallocations++;
        currentBytes -= (int)(freedSize * 1024); 

         cout << "✓ Memory at " << ptr << " has been deallocated successfully!" << endl;
    }
    
    // Method to allocate array and track it
    // new[] needed for extra metadata
    // When we do new T[10], a "size cookie" is stored, 
    // to use delete[] on the array, and also carves out
    //  10 * sizeof(T) bytes

    // So, we have new[] for allocate and
    // delete[] for deallocate.

    // So we do new[T] instead of malloc
    void* allocateArray(size_t size) {

        if(size == 0){
            cout << "Error: Can't allocate memory of " << size << " KB..." << endl;
            return nullptr;
        }

        int* ptr = nullptr;

        try{
            ptr = new int[size];
        } catch (const bad_alloc& e){
            cout << "✗ Allocation failed for dataset of " << size << " KB: " << e.what() << endl;
            return nullptr;
        }

            for (size_t i = 0; i < size; i++){
                ptr[i] = (((19 + i) + 133) * ((size * 5) / 7)) * 52;
            }

            AllocationInfo info(size, true);
            info.uuid = ptr;
            allocations.emplace(ptr, info); // Insert into the map, keyed by address
            totalAllocations++;

            cout << "✓ Allocated memory with UUID: " << ptr << "' with " << size << " KB." << endl;
            currentBytes = (int)(size * 1024);
            peakBytes = max(peakBytes, (int)(size*1024));

            return ptr;

    }
    
    // Method to deallocate array
    void deallocateArray(void* ptr) {
        // TODO: Similar to deallocateMemory but for arrays

        auto it = allocations.find(ptr);

        if (it == allocations.end()){
            cout << "✗ Error: Memory at pointer '" << ptr << "' not found for deallocation!" << endl;
            return;
        }

        cout << "Deallocation at pointer " << ptr << " started..." << endl;

        size_t freedSize = it->second.size; // grab size before erasing it
        free(ptr);
        
        // This is to remove the listing from the allocations map as well, so there 
        // can't be any repeated deletions by accident at all.
        // There is no double deletion possible
        allocations.erase(it);

        totalDeallocations++;
        currentBytes -= (int)(freedSize * 1024); 

         cout << "✓ Memory at " << ptr << " has been deallocated successfully!" << endl;

    }
    
    // ========================================
    // STEP 3: Leak Detection and Reporting
    // ========================================
    
    // TODO: Method to report memory leaks
    void reportLeaks() {
        // TODO: Check tracked allocations for unreleased memory
        // TODO: Display detailed leak information
        // TODO: Show total leaked bytes, number of leaks
        // TODO: Optionally write to log file
    }
    
    // TODO: Method to get current statistics
    void printStatistics() {
        // TODO: Display current memory usage statistics
        // TODO: Show total allocations, deallocations, current usage
    }
    
    // ========================================
    // STEP 4: Enhanced Debugging Information
    // ========================================
    
    // TODO: Method to log operations to file
    void logToFile(const string& message) {
        // TODO: Write memory operations to a log file with timestamps
    }
    
    // TODO: Method to validate memory integrity
    bool validateMemory() {
        // TODO: Check for corruption or inconsistencies
        // TODO: Return true if all memory is valid
    }
};

// Global instance of MemoryManager
// TODO: Create global instance
// MemoryManager* globalMemoryManager = nullptr;

// ========================================
// STEP 2: Override Global New and Delete Operators
// ========================================

// TODO: Override global new operator
void* operator new(size_t size) {
    // TODO: Use globalMemoryManager->allocateMemory(size)
    // TODO: Handle case where globalMemoryManager is null
}

// TODO: Override global delete operator
void operator delete(void* ptr) noexcept {
    // TODO: Use globalMemoryManager->deallocateMemory(ptr)
    // TODO: Handle case where globalMemoryManager is null
}

// TODO: Override global new[] operator for arrays
void* operator new[](size_t size) {
    // TODO: Use globalMemoryManager->allocateArray(size)
}

// TODO: Override global delete[] operator for arrays
void operator delete[](void* ptr) noexcept {
    // TODO: Use globalMemoryManager->deallocateArray(ptr)
}

// ========================================
// STEP 5: Testing Framework
// ========================================

class MemoryManagerTester {
public:
    // TODO: Test basic allocation and deallocation
    static void testBasicOperations() {
        cout << "\n--- Testing Basic Operations ---" << endl;
        // TODO: Allocate some memory
        // TODO: Deallocate it
        // TODO: Check that no leaks are reported
    }
    
    // TODO: Test memory leak detection
    static void testLeakDetection() {
        cout << "\n--- Testing Leak Detection ---" << endl;
        // TODO: Intentionally create memory leaks
        // TODO: Call reportLeaks() to verify detection
    }
    
    // TODO: Test array operations
    static void testArrayOperations() {
        cout << "\n--- Testing Array Operations ---" << endl;
        // TODO: Test new[] and delete[] operations
    }
    
    // TODO: Test error conditions
    static void testErrorConditions() {
        cout << "\n--- Testing Error Conditions ---" << endl;
        // TODO: Test double deletion
        // TODO: Test deletion of untracked memory
        // TODO: Test null pointer deletion
    }
    
    // TODO: Run all tests
    static void runAllTests() {
        cout << "=== Memory Manager Test Suite ===" << endl;
        // TODO: Initialize global memory manager
        // TODO: Run each test method
        // TODO: Report final results
        // TODO: Clean up
    }
};

// ========================================
// IMAGE PROCESSING SIMULATION (Scenario Context)
// ========================================

class ImageProcessor {
private:
    int width, height;
    unsigned char* imageData;
    
public:
    // TODO: Constructor that allocates image data
    ImageProcessor(int w, int h) {
        // TODO: Set width and height
        // TODO: Allocate memory for imageData (width * height * 3 for RGB)
    }
    
    // TODO: Destructor that cleans up image data
    ~ImageProcessor() {
        // TODO: Delete imageData if allocated
    }
    
    // TODO: Method to process image (simulate work)
    void processImage() {
        // TODO: Simulate image processing work
        // TODO: Maybe allocate temporary buffers
        // TODO: Don't forget to clean up temporary allocations!
    }
    
    // TODO: Method to resize image (demonstrates reallocation)
    void resize(int newWidth, int newHeight) {
        // TODO: Allocate new buffer
        // TODO: Copy data if needed (simulate)
        // TODO: Delete old buffer
        // TODO: Update dimensions
    }
};

// ========================================
// MAIN FUNCTION
// ========================================

int main() {
    cout << "=== Memory Tracking and Management System ===" << endl;
    cout << "Image Processing Application Scenario" << endl;
    
    // TODO: Initialize global memory manager
    // globalMemoryManager = new MemoryManager();
    
    cout << "\n--- Phase 1: Basic Memory Manager Testing ---" << endl;
    // TODO: Run basic tests
    
    cout << "\n--- Phase 2: Image Processing Simulation ---" << endl;
    // TODO: Create ImageProcessor instances
    // TODO: Perform various operations
    // TODO: Demonstrate memory tracking in action
    
    cout << "\n--- Phase 3: Comprehensive Testing ---" << endl;
    // TODO: Run full test suite
    
    cout << "\n--- Phase 4: Final Memory Report ---" << endl;
    // TODO: Generate final memory usage report
    // TODO: Check for any remaining leaks
    
    // TODO: Clean up global memory manager
    // delete globalMemoryManager;
    
    cout << "\n=== Program Complete ===" << endl;
    return 0;
}

/*
IMPLEMENTATION GUIDE:

STEP 1 - Memory Manager Class:
□ Define AllocationInfo struct with size, timestamp, and other metadata
□ Use std::map<void*, AllocationInfo> to track allocations
□ Add counters for total allocations, deallocations, bytes used
□ Implement allocateMemory() and deallocateMemory() methods

STEP 2 - Global Operator Overrides:
□ Override operator new to use MemoryManager
□ Override operator delete to use MemoryManager  
□ Override operator new[] and delete[] for arrays
□ Handle null pointer cases gracefully

STEP 3 - Leak Detection:
□ Implement reportLeaks() to show unfreed memory
□ Display useful information: address, size, allocation time
□ Count total leaked blocks and bytes
□ Optionally write detailed reports to log file

STEP 4 - Enhanced Debugging:
□ Add timestamps to track allocation timing
□ Implement file logging for persistent debugging
□ Add memory validation checks
□ Include stack trace information if possible

STEP 5 - Testing Framework:
□ Test basic allocation/deallocation cycles
□ Intentionally create leaks to verify detection
□ Test edge cases: double deletion, null pointers
□ Test array operations separately
□ Stress test with many allocations

SAFETY CONSIDERATIONS:
- Handle null pointers gracefully
- Prevent double deletion crashes
- Ensure thread safety if needed
- Validate memory before operations
- Clean up tracking data structures

SUCCESS CRITERIA:
- All allocations are properly tracked
- Leaks are accurately detected and reported
- No crashes from memory errors
- Clear, useful debugging information
- Comprehensive test coverage
*/