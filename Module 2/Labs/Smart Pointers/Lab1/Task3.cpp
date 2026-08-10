#include <iostream>
#include <memory>
#include <string>
#include <fstream>
#include <chrono>
#include <ctime>
#include <iomanip>
#include <vector>
using namespace std;
// Custom resource classes
class NetworkConnection {
private:
    string endpoint;
    int connectionId;
    bool isConnected;    
public:
    NetworkConnection(const string& ep, int id)
        : endpoint(ep), connectionId(id), isConnected(true) {
        cout << "Network connection established to " << endpoint
            << " (ID: " << connectionId << ")" << endl;
    }    
    void disconnect() {
        if (isConnected) {
            cout << "Disconnecting from " << endpoint << " (ID: " << connectionId << ")" << endl;
            isConnected = false;
        }
    }    
    void sendData(const string& data) {
        if (isConnected) {
            cout << "Sending data to " << endpoint << ": " << data << endl;
        } else {
            cout << "Cannot send data - connection closed" << endl;
        }
    }    
    string getEndpoint() const { return endpoint; }
    int getId() const { return connectionId; }
    bool connected() const { return isConnected; }
};
class DatabaseHandle {
private:
    string dbName;
    string connectionString;
    bool transactionActive;    
public:
    DatabaseHandle(const string& name, const string& connStr) 
        : dbName(name), connectionString(connStr), transactionActive(false) {
        cout << "Database handle opened for " << dbName << endl;
    }    
    void beginTransaction() {
        transactionActive = true;
        cout << "Transaction started on " << dbName << endl;
    }    
    void commitTransaction() {
        if (transactionActive) {
            cout << "Transaction committed on " << dbName << endl;
            transactionActive = false;
        }
    }    
    void rollbackTransaction() {
        if (transactionActive) {
            cout << "Transaction rolled back on " << dbName << endl;
            transactionActive = false;
        }
    }    
    void close() {
        if (transactionActive) {
            cout << "Warning: Closing database with active transaction - rolling back" << endl;
            rollbackTransaction();
        }
        cout << "Database handle closed for " << dbName << endl;
    }    
    string getName() const { return dbName; }
    bool hasActiveTransaction() const { return transactionActive; }
};
// Custom deleter classes
class NetworkConnectionDeleter {
private:
    string context;    
public:
    NetworkConnectionDeleter(const string& ctx = "Default") : context(ctx) {}    
    void operator()(NetworkConnection* conn) {
        if (conn) {
            cout << "[" << context << " Deleter] Cleaning up network connection..." << endl;
            conn->disconnect();            
            // Log cleanup time
            auto now = chrono::system_clock::now();
            auto time_t = chrono::system_clock::to_time_t(now);
            cout << "  Cleanup timestamp: " << put_time(localtime(&time_t), "%H:%M:%S") << endl;            
            delete conn;
        }
    }
};
class DatabaseHandleDeleter {
private:
    bool logActivity;    
public:
    DatabaseHandleDeleter(bool log = true) : logActivity(log) {}    
    void operator()(DatabaseHandle* handle) {
        if (handle) {
            if (logActivity) {
                cout << "[Database Deleter] Safely closing database handle..." << endl;
                cout << "  Database: " << handle->getName() << endl;
                cout << "  Active transaction: " << (handle->hasActiveTransaction() ? "Yes" : "No") << endl;
            }            
            handle->close();
            delete handle;            
            if (logActivity) {
                cout << "[Database Deleter] Database handle cleanup complete" << endl;
            }
        }
    }
};
// Resource manager class
class ResourceManager {
private:
    vector<shared_ptr<NetworkConnection>> connections;
    vector<shared_ptr<DatabaseHandle>> databases;    
public:
    void createNetworkConnection(const string& endpoint, int id, const string& context = "Default") {
        cout << "\nCreating network connection with custom deleter..." << endl;        
        NetworkConnectionDeleter deleter(context);
        auto conn = shared_ptr<NetworkConnection>(
            new NetworkConnection(endpoint, id),
            deleter
        );        
        connections.push_back(conn);
        cout << "Network connection added to manager (total: " << connections.size() << ")" << endl;
    }    
    void createDatabaseHandle(const string& dbName, const string& connStr, bool enableLogging = true) {
        cout << "\nCreating database handle with custom deleter..." << endl;        
        auto db = shared_ptr<DatabaseHandle>(
            new DatabaseHandle(dbName, connStr),
            DatabaseHandleDeleter(enableLogging)
        );        
        databases.push_back(db);
        cout << "Database handle added to manager (total: " << databases.size() << ")" << endl;
    }    
    void useNetworkConnections() {
        cout << "\n--- Using Network Connections ---" << endl;
        for (size_t i = 0; i < connections.size(); i++) {
            if (connections[i] && connections[i]->connected()) {
                connections[i]->sendData("Test data " + to_string(i));
            }
        }
    }    
    void useDatabaseHandles() {
        cout << "\n--- Using Database Handles ---" << endl;
        for (size_t i = 0; i < databases.size(); i++) {
            if (databases[i]) {
                databases[i]->beginTransaction();
                // Simulate some database work
                cout << "Performing database operations on " << databases[i]->getName() << endl;                
                if (i % 2 == 0) {
                    databases[i]->commitTransaction();
                } else {
                    // Leave transaction active for cleanup demonstration
                    cout << "Leaving transaction active for cleanup demo" << endl;
                }
            }
        }
    }    
    void displayResourceStatus() {
        cout << "\n--- Resource Status ---" << endl;
        cout << "Active network connections: " << connections.size() << endl;
        for (const auto& conn : connections) {
            if (conn) {
                cout << "  " << conn->getEndpoint() << " (ID: " << conn->getId() 
                     << ") - " << (conn->connected() ? "Connected" : "Disconnected") << endl;
            }
        }        
        cout << "Active database handles: " << databases.size() << endl;
        for (const auto& db : databases) {
            if (db) {
                cout << "  " << db->getName() << " - " 
                     << (db->hasActiveTransaction() ? "Transaction Active" : "Idle") << endl;
            }
        }
    }    
    void cleanupResources() {
        cout << "\n--- Manual Resource Cleanup ---" << endl;        
        // Clear connections (triggers custom deleters)
        cout << "Clearing network connections..." << endl;
        connections.clear();        
        cout << "Clearing database handles..." << endl;
        databases.clear();        
        cout << "Manual cleanup complete" << endl;
    }    
    ~ResourceManager() {
        cout << "\nResourceManager destructor - automatic cleanup of remaining resources" << endl;
        cleanupResources();
    }
};
// File management with custom deleter
class FileManager {
public:
    static void demonstrateFileHandling() {
        cout << "\n=== File Management with Custom Deleters ===" << endl;        
        // Custom deleter for FILE* using lambda
        auto fileDeleter = [](FILE* file) {
            if (file) {
                cout << "Custom file deleter: Closing file handle" << endl;
                if (fclose(file) == 0) {
                    cout << "  File closed successfully" << endl;
                } else {
                    cout << "  Error closing file" << endl;
                }
            }
        };        
        // Create file with custom deleter
        {
            shared_ptr<FILE> logFile(fopen("cloud_system.log", "w"), fileDeleter);            
            if (logFile) {
                fprintf(logFile.get(), "Cloud system startup log\n");
                fprintf(logFile.get(), "Timestamp: %ld\n", time(nullptr));
                fprintf(logFile.get(), "System initialization complete\n");
                cout << "Log entries written to file" << endl;
            } else {
                cout << "Failed to create log file" << endl;
            }
        } // File automatically closed by custom deleter here        
        cout << "File handling demonstration complete" << endl;
    }
};
int main() {
    cout << "=== Custom Deleter Resource Management System ===" << endl;    
    ResourceManager manager;    
    // Create various resources with custom deleters
    cout << "\n--- Creating Resources with Custom Deleters ---" << endl;    
    manager.createNetworkConnection("api.cloudservice.com:443", 1001, "API Gateway");
    manager.createNetworkConnection("db.cloudservice.com:5432", 1002, "Database Cluster");
    manager.createNetworkConnection("cache.cloudservice.com:6379", 1003, "Redis Cache");    
    manager.createDatabaseHandle("UserDatabase", "postgresql://localhost/users", true);
    manager.createDatabaseHandle("LogDatabase", "postgresql://localhost/logs", false);    
    // Use the resources
    manager.displayResourceStatus();
    manager.useNetworkConnections();
    manager.useDatabaseHandles();    
    // Demonstrate file management
    FileManager::demonstrateFileHandling();    
    // Show resource status before cleanup
    manager.displayResourceStatus();    
    // Trigger custom deleters manually
    cout << "\n--- Triggering Custom Deleters ---" << endl;
    manager.cleanupResources();    
    cout << "\n--- Program Ending (ResourceManager destructor will handle any remaining cleanup) ---" << endl;    
    return 0;
}