/*
Extend your understanding by creating a Student class that manages 
academic information with more complex interactions.

🔍 Practice

Complete the main function to:

    Create at least two Student objects

    Add multiple grades to each student

    Display their information and averages

    Test the grade validation by trying to add invalid grades*/

#include <iostream>
#include <string>
#include <vector>
class Student {
private:
   std::string name;
   int studentId;
   std::vector<double> grades;
   
public:
   // Constructor
   Student(std::string studentName, int id){
    name = studentName;
    studentId = id;
   }
   
   // Add a grade
   void addGrade(double grade) {
      if (grade >= 0.0 && grade <= 100.0) {
         grades.push_back(grade);
         std::cout << "Grade " << grade << " added for " << name << std::endl;
      } else {
         std::cout << "Invalid grade. Must be between 0 and 100." << std::endl;
      }
   }
   
   // Calculate average grade
   double calculateAverage() const {
      if (grades.empty()) return 0.0;
      
      double sum = 0.0;
      for (double grade : grades) {
         sum += grade;
      }
      return sum / grades.size();
   }
   
   // Display student information
   void displayStudent() const {
      std::cout << "Student: " << name << " (ID: " << studentId << ")" << std::endl;
      std::cout << "Number of grades: " << grades.size() << std::endl;
      std::cout << "Average grade: " << calculateAverage() << std::endl;
   }
};
// Complete this implementation
int main() {
   // Your code here: Create student objects and demonstrate functionality
   Student student1("Alan", 12345);

   student1.displayStudent();
   student1.addGrade(98);
   student1.addGrade(91);
   student1.addGrade(22);
   student1.addGrade(2);
   student1.addGrade(57);
   student1.addGrade(82);
   student1.addGrade(30);
   student1.addGrade(-10);
   student1.displayStudent();

   return 0;
}