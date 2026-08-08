#include<iostream>

class Array{
private:
    int* array;
    
public:
    Array(){
        array = new int[5];
        for (int i = 0; i < 5; i++){
            array[i] = 0;
        }
    }

    Array(const Array& other){
        array = new int[5];
        for (int i = 0; i < 5; i++){
            array[i] = other.array[i];
        }
    }

    Array& operator = (const Array& other) {
        if(this != &other){
            int* new_array = new int[5];

            for (int i = 0; i < 5; i++){
            array[i] = other.array[i];
            }

            delete[] array;
            array = new_array;
        }

        return *this;
    }

    ~Array(){
        delete[] array;
        array = nullptr;
    }

};