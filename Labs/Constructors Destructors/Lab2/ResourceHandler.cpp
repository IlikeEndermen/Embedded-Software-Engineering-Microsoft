#include<iostream>
#include<string>

class ResourceHandler{
private:
    std::string resourceName; // human readable label (fileName)
    std::string resourceType; // category (memory, file, socket, mutex)
    static int totalResources; // counter to use for all of the resources
    bool isAllocated;

public:

    // Default constructor
    ResourceHandler() : resourceName("defaultResource"), resourceType("file"), isAllocated(true){
        totalResources++;
        std::cout << "Generic resource " << resourceName << " was created with ID: (" << totalResources << ")." << '\n';
    }

    // Parametrized constructor
    ResourceHandler(std::string name, std::string type) : resourceName(name), resourceType(type), isAllocated(true){
        totalResources++;
        std::cout << "Resource " << resourceName << " of type " << resourceType << " was created with ID: (" << totalResources << ")." << '\n';
    }

    // Copy constructor
    ResourceHandler(const ResourceHandler& other) : resourceName(other.resourceName + "_copy"), resourceType(other.resourceType), isAllocated(other.isAllocated){
        totalResources++;
        std::cout << "A copy of " << resourceName << " was created, of type " << resourceType << " with ID: (" << totalResources << ")." << '\n';
    }

    // Destructor
    ~ResourceHandler(){
        totalResources--;
        std::cout << "Destroyed " << resourceName << "| Remaining resources" << totalResources << '\n';
    }
};

int main(){
    return 0;
}