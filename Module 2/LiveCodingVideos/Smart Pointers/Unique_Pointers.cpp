#include<iostream>
#include<memory>

// We can turn this class into just 2 lines of code
/*
class Array{
private:
    int* array_;
    unsigned int size_;

public:
    Array(unsigned int size) : size_(size){
        array_ = new int[size]();
    }

    Array(const Array& other) = delete;
    Array& operator = (const Array& other) = delete;

    ~Array(){
        delete[] array_;
        array_ = nullptr;
    }

    void set(unsigned int index, int value){
        if(index < size_ && array_ != nullptr){
            array_[index] = value;
        }
    }

    int get(unsigned int& index){
        if (index < size_ && array_ != nullptr){
            return array_[index];
        }
        return 0;
    }
    
};
*/

std::unique_ptr<int> unique_int(int i){
    return std::make_unique<int>(i);
}


int main(){

    // We create a unique pointer here
    // Manages an integer array

    // std::unique_ptr<int[]> unique  = std::make_unique<int[]>(10); <-> Set the integer array to 10 items
    // We use auto to not copy the unique_ptr syntax all the time

    auto unique  = std::make_unique<int>(10);

    // copy_attempt = unique; // Can't copy a unique pointer, since only one pointer gets the resources

    auto moved = std::move(unique); // Move all the resources of unique into moved, making unique dead?
    // unique can't be referenced anymore

    // This gives an error now, since unique can't be referenced
    // std::cout << *unique << std::endl; // This is the syntax of dereferencing the unique ptr
    
    std::cout << *moved << std::endl;
    std::cout << *unique_int(42) << std::endl;

    return 0;
}