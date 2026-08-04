// For this lab, I am given the code, and I need to modify the code to add some bullshit

// Description can be found below:

/* You're building a digital library system that needs to track book information.
   Create a Book class that stores essential book data and provides controlled access to that information.


🔍 Practice

Run the code and observe how objects are created and manipulated. Think about:

    How does the constructor ensure proper object initialization?

    What happens when you try to access private data members directly?

Modify the code to experiment with:

    Adding validation to the setPages method (reject negative values)

    Creating additional book objects with different data

Test your changes and observe the encapsulation in action. */

#include <iostream>
#include <string>

class Book {
private:

    // Private variables that we want to use and we use to describe a book
    std::string title;
    std::string author;
    int pages;
    bool isAvailable;
    int yearOfPublishing;

public:
    // Parameterized constructor to allow a book to be created
    Book(std::string bookTitle, std::string bookAuthor, int pageCount, int year) {
        title = bookTitle;
        author = bookAuthor;
        pages = pageCount;
        isAvailable = true;
        yearOfPublishing = year;
    }

    // Getter methods
    // Read only access to the variables that are written below, no modification access allowed
    std::string getTitle() const { return title; }
    std::string getAuthor() const { return author; }
    int getPages() const { return pages; }
    bool getAvailability() const { return isAvailable; }

    // Setter methods
    // Specific functions made in order to ensure that the values of the object are modified
    // in a specific and controlled way.
    void setPages(int newPages) {
        if (newPages > 0) {
            pages = newPages;
        }
    }

    void setAvailability(bool status) {
        isAvailable = status;
    }

    // Display book information
    // Generic read only function to read all information at once from the object
    void displayInfo() const {
        std::cout << "Title: " << title << std::endl;
        std::cout << "Author: " << author << std::endl;
        std::cout << "Pages: " << pages << std::endl;
        std::cout << "Available: " << (isAvailable ? "Yes" : "No") << std::endl;
        std::cout << "Year Of Release: " << yearOfPublishing << std::endl;
        std::cout << "------------------------" << std::endl;
    }
};

int main() {
    // Create book objects
    Book book1("The C++ Programming Language", "Bjarne Stroustrup", 1376, 1984);
    Book book2("Clean Code", "Robert C. Martin", 464, 2004);

    // Display book information
    book1.displayInfo();
    book2.displayInfo();

    // Demonstrate object interaction
    std::cout << "Checking out: " << book1.getTitle() << std::endl;
    book1.setAvailability(false);
    book1.displayInfo();

    return 0;
}
