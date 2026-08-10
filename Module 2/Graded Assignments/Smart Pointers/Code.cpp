#include<iostream>
#include<memory>

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
    // std::cout << *unique_int(42) << std::endl;

    return 0;
}