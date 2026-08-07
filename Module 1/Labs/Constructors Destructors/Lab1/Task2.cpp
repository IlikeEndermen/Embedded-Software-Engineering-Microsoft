#include <iostream>
#include <string>
#include <memory>
class DatabaseConnection {
private:
    std::string connectionString;
    std::string databaseName;
    bool isConnected;
    int connectionId;
    static int nextId;    
    // Simulate connection establishment
    bool establishConnection() {
        std::cout << "Establishing connection to " << databaseName << "..." << std::endl;
        // Simulate connection logic
        isConnected = true;
        return true;
    }    
    // Simulate connection cleanup
    void closeConnection() {
        if (isConnected) {
            std::cout << "Closing database connection [ID: " << connectionId << "]" << std::endl;
            isConnected = false;
        }
    }
public:
    // Default constructor
    DatabaseConnection() : connectionString("localhost:5432"), databaseName("default_db"),
                        isConnected(false), connectionId(++nextId) {
        std::cout << "Creating default database connection [ID: " << connectionId << "]" << std::endl;
        establishConnection();
    }    
    // Parameterized constructor
    DatabaseConnection(const std::string& connStr, const std::string& dbName)
        : connectionString(connStr), databaseName(dbName), isConnected(false), connectionId(++nextId) {
        std::cout << "Creating database connection [ID: " << connectionId << "] to " << databaseName << std::endl;
        establishConnection();
    }    
    // Copy constructor (creates new connection)
    DatabaseConnection(const DatabaseConnection& other)
        : connectionString(other.connectionString), databaseName(other.databaseName + "_copy"),
        isConnected(false), connectionId(++nextId) {
        std::cout << "Creating copied database connection [ID: " << connectionId
                << "] based on connection " << other.connectionId << std::endl;
        establishConnection();
    }    
    // Destructor
    ~DatabaseConnection() {
        std::cout << "Destroying database connection [ID: " << connectionId << "]" << std::endl;
        closeConnection();
    }    
    // Member functions
    void executeQuery(const std::string& query) {
        if (isConnected) {
            std::cout << "Executing on " << databaseName << ": " << query << std::endl;
        } else {
            std::cout << "Cannot execute - connection not established" << std::endl;
        }
    }    
    bool getConnectionStatus() const {
        return isConnected;
    }    
    int getId() const {
        return connectionId;
    }
};
// Initialize static member
int DatabaseConnection::nextId = 0;
// Complete the main function
int main() {
    std::cout << "=== Database Connection Manager ===" << std::endl << std::endl;

    // Step 1: default connection
    std::cout << "1. Spinning up a default connection:" << std::endl;
    DatabaseConnection basicDatabase;
    std::cout << std::endl;

    // Step 2: custom connections
    std::cout << "2. Establishing custom connections:" << std::endl;
    DatabaseConnection customDatabase1("localhost:6969", "Brother");
    DatabaseConnection customDatabase2("localhost:1475", "Executioner");
    std::cout << std::endl;

    // Step 3: running a query
    std::cout << "3. Sending a query through customDatabase2:" << std::endl;
    customDatabase2.executeQuery("Bullshit");
    std::cout << std::endl;

    // Step 4: checking status
    std::cout << "4. Checking status of customDatabase1:" << std::endl;
    customDatabase1.getConnectionStatus();
    std::cout << std::endl;

    // Step 5: scoped copy/assignment test
    std::cout << "5. Testing assignment inside a limited scope:" << std::endl;
    {
        DatabaseConnection testing;
        std::cout << "--- Assigning basicDatabase to testing ---" << std::endl;
        testing = basicDatabase;
        std::cout << "--- testing going out of scope ---" << std::endl;
    } // testing's destructor fires here

    std::cout << std::endl << "=== Program ending - remaining connections will be closed ===" << std::endl;
    return 0;
}