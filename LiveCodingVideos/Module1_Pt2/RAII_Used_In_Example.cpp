#include<iostream>
#include<fstream>
#include<string>

// We want to manage access to the log.txt file

// Class implementation of the writing to log.txt file

class Log{
private:

    std::fstream* log_; // Handles the log

public:

    Log(std::string filename){
        log_ = new std::fstream(filename, std::ios::out | std::ios::app); // Reads the contents of the file
        std::cout << "Constructor Called." << '\n';
    }
    // fstream is a unique resource, we don't want other instances of log to have access to it.
    // By making the copying functions delete, we ensure that there is only a single point of access
    // to the file, and nothing else is allowed to access it.
    
    Log(const Log &other) = delete;
    Log& operator = (const Log& other) = delete;

    
    // Update the destructor to close the filestream and release the resources
    ~Log(){
        if (log_ && log_ -> is_open()){
            log_ -> close();
        }

        if(log_ != nullptr){
            delete log_;
            log_ = nullptr;
        }

        std::cout << "Destructor Called." << '\n';
    }

    void write(std::string message){
        if (log_ && log_ -> is_open()){
            *log_ << message; 
            // Write the message at the memory address that represents log, AKA
            // Write message into the log.txt file
        }
    }
};


// Procedural approach
/*
int main(){
    auto file_handle = new std::fstream("log.txt", std::ios::out | std::ios::app);

    if (file_handle && file_handle -> is_open()){
        *file_handle << "Hello World!\n";
        file_handle -> close();
    }

    if (file_handle != nullptr){
        delete file_handle;
        file_handle = nullptr;
    }
}
*/

int main(){
    {
        Log log("log.txt");
        log.write("HELLO, RAII!!!!\n");

        
        // The code below doesn't work because the log was already deleted, meaning we can't copy
        // It was specified in the class creation, it deletes full stop
        /*Log log2("another_log.txt");
        log2 = log;*/
    }
    return 0;
}