#include <iostream>
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
};

int main() {
    string courses[] = {"Math", "Physics", "Computer Science"};
    Student student1("Saksham", 12345, 3.9, courses, 3);
    student1.display();

    Student student2 = student1;
    student2.display();

    return 0;
}