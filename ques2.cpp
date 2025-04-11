#include <iostream>
#include <string>
using namespace std;
class Student {
private:
    string name;
    int roll_number;
    double cgpa;
    static const int MAX_COURSES = 5;
    string courses[MAX_COURSES];
    int course_count;
public:
    Student() : name(""), roll_number(0), cgpa(0.0), course_count(0) {}
    Student(string name, int roll_number, double cgpa, string courses[], int course_count) 
        : name(name), roll_number(roll_number), cgpa(cgpa), course_count(course_count) {
        for (int i = 0; i < course_count; ++i) {
            this->courses[i] = courses[i];
        }
    }
    Student(const Student &other) {
        name = other.name;
        roll_number = other.roll_number;
        cgpa = other.cgpa;
        course_count = other.course_count;
        for (int i = 0; i < course_count; ++i) {
            courses[i] = other.courses[i];
        }
    }
    void addCourse(string new_course) {
        if (course_count < MAX_COURSES) {
            courses[course_count++] = new_course;
            cout << "Course '" << new_course << "' added successfully." << endl;
        } else {
            cout << "Cannot add more courses. Maximum limit reached." << endl;
        }
    }
    bool updateCGPA(double new_cgpa) {
        if (new_cgpa >= 0.0 && new_cgpa <= 4.0) {
            cgpa = new_cgpa;
            cout << "CGPA updated successfully." << endl;
            return true;
        } else {
            cout << "Invalid CGPA. CGPA should be between 0.0 and 4.0." << endl;
            return false;
        }
    }
    void display() const {
        cout << "Student Name: " << name << endl;
        cout << "Roll Number: " << roll_number << endl;
        cout << "CGPA: " << cgpa << endl;
        cout << "Enrolled Courses: ";
        for (int i = 0; i < course_count; ++i) {
            cout << courses[i] << " ";
        }
        cout << endl;
    }
    bool validateCourse(string course) {
        for (int i = 0; i < course_count; ++i) {
            if (courses[i] == course) {
                cout << "Course '" << course << "' is already enrolled." << endl;
                return false;
            }
        }
        return true;
    }
};
int main() {
    string courses[] = {"Math", "Physics", "Computer Science"};
    Student student1("Saksham", 12345, 3.9, courses, 3);
    student1.display();
    student1.addCourse("Biology");
    student1.addCourse("Chemistry");  
    if (student1.updateCGPA(3.7)) {
        student1.display();
    }
    if (student1.updateCGPA(4.2)) {  
        student1.display();
    }
    return 0;
}