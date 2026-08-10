#include<iostream>
#include<memory>


class Example{

public:
    ~Example(){
        std::cout << "Destructor called!" << std::endl;
    }
};

/*
int main(){
    // Shared pointers are copiable smart pointers
    std::shared_ptr<int> shared = std::make_shared<int>(1);

    // Real copy that can be created, it shares the resources
    auto copy = shared;

    // Resources are not freed until all the pointers were dereferenced
    std::cout << *shared << " " << *copy << std::endl;

    {
        // Smart pointers call the destructor when they leave this scope
        auto shared = std::make_shared<Example>();
    }

    return 0;
}*/

int main(){

    {
        auto shared = std::shared_ptr<int[]>{new int[100]()};

        // use_count = reference counter, sees how many times it was referenced
        // Also, it's the number of times shared pointer has been constructed/copied
        // When ref count = 0 and all pointers leaves scope => pointer is cleaned up
        std::cout << shared.use_count() << std::endl;

        auto copy = shared;
        std::cout << shared.use_count() << " " << copy.use_count() << std::endl;
    }

}