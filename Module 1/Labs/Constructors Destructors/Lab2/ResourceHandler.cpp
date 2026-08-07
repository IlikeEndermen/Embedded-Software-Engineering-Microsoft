#include<iostream>
#include<string>

class ResourceHandler{
private:
    std::string resourceName; // human readable label (fileName)
    std::string resourceType; // category (memory, file, socket, mutex)
    static int totalResources; // counter to use for all of the resources
    bool isAllocated;
    bool isValid;

    bool hasValidName(std::string name){
        return name.length() > 0;
    }

    bool hasValidType(std::string type){
        return type == "file" || type == "memory" || type == "socket" || type == "mutex";
    }

public:

    // Default constructor
    ResourceHandler() : resourceName("defaultResource"), resourceType("file"), isAllocated(true), isValid(true){
        totalResources++;
        std::cout << "Generic resource " << resourceName << " was created with ID: (" << totalResources << ")." << '\n';
    }

    // Parametrized constructor
    ResourceHandler(std::string name, std::string type) : resourceName(name), resourceType(type), isAllocated(true),
    isValid(hasValidName(name) == true && hasValidType(type) == true){
        if (isValid) {
        totalResources++;
        std::cout << "Resource " << resourceName << " of type " << resourceType
                   << " was created with ID: (" << totalResources << ")." << '\n';
        }
         else if (!hasValidName(name) && !hasValidType(type)) {
        std::cout << "Error: resource has both an invalid name and an invalid type" << '\n';
    } else if (!hasValidName(name)) {
        std::cout << "Error: the resource was not declared with a name" << '\n';
    } else {
        std::cout << "Error: the resource was declared with an illegal type" << '\n';
    }
    }

    // Copy constructor
    ResourceHandler(const ResourceHandler& other) : resourceName(other.resourceName + "_copy"), resourceType(other.resourceType), isAllocated(other.isAllocated),
    isValid(other.isValid){
         if (isValid) {
            totalResources++;
            std::cout << "A copy of " << resourceName << " was created, of type " << resourceType << " with ID: (" << totalResources << ")." << '\n';
        } else {
            std::cout << "Cannot properly copy invalid resource " << resourceName << '\n';
        }
    }

    // Destructor
    ~ResourceHandler(){
        if(isValid){
        totalResources--;
        std::cout << "Destroyed " << resourceName << "| Remaining resources" << totalResources << '\n';
        }
    }
};

    
int ResourceHandler::totalResources = 0;

int main(){
    std::cout << "=== Resource Handler Test Suite ===" << std::endl << std::endl;

    // 1. Default constructor
    std::cout << "1. Creating default resource:" << std::endl;
    ResourceHandler defaultRes;
    std::cout << std::endl;

    // 2. Valid parameterized constructor
    std::cout << "2. Creating valid resources:" << std::endl;
    ResourceHandler dbConn("db_connection_1", "socket");
    ResourceHandler memBlock("heap_block_A", "memory");
    std::cout << std::endl;

    // 3. Invalid: empty name
    std::cout << "3. Attempting resource with no name:" << std::endl;
    ResourceHandler noName("", "file");
    std::cout << std::endl;

    // 4. Invalid: bad type
    std::cout << "4. Attempting resource with illegal type:" << std::endl;
    ResourceHandler badType("weird_resource", "printer");
    std::cout << std::endl;

    // 5. Invalid: both wrong
    std::cout << "5. Attempting resource with no name AND illegal type:" << std::endl;
    ResourceHandler bothWrong("", "printer");
    std::cout << std::endl;

    // 6. Copying a valid resource
    std::cout << "6. Copying a valid resource:" << std::endl;
    ResourceHandler dbConnCopy = dbConn;
    std::cout << std::endl;

    // 7. Copying an INVALID resource — checks the copy-constructor edge case
    std::cout << "7. Copying an invalid resource:" << std::endl;
    ResourceHandler badTypeCopy = badType;
    std::cout << std::endl;

    // 8. Scoped destruction test
    std::cout << "8. Testing destruction inside a limited scope:" << std::endl;
    {
        ResourceHandler tempRes("temp_mutex", "mutex");
        std::cout << "--- tempRes going out of scope ---" << std::endl;
    } // tempRes destructor fires here
    std::cout << std::endl;

    std::cout << "=== Program ending - remaining resources will be destroyed ===" << std::endl;
    return 0;
}