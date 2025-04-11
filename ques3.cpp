#include <iostream>
#include <cstring>
using namespace std;

class Student {
private:
    char name[100];
    int roll_number;
    double cgpa;
    static const int MAX_COURSES = 5;
    char courses[MAX_COURSES][50];
    int course_count;

public:
    Student() : name(""), roll_number(0), cgpa(0.0), course_count(0) {}

    Student(const char *name, int roll_number, double cgpa, const char courses[][50], int course_count) 
        : roll_number(roll_number), cgpa(cgpa), course_count(course_count) {
        strcpy(this->name, name);
        for (int i = 0; i < course_count; ++i) {
            strcpy(this->courses[i], courses[i]);
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

    int getRollNumber() const {
        return roll_number;
    }

    void setCourse(const char *new_course) {
        if (course_count < MAX_COURSES) {
            strcpy(courses[course_count++], new_course);
        } else {
            cout << "Cannot add more courses. Maximum limit reached." << endl;
        }
    }
};

class StudentManagementSystem {
private:
    static const int MAX_STUDENTS = 10;
    Student students[MAX_STUDENTS];
    int student_count;

public:
    StudentManagementSystem() : student_count(0) {}

    bool addStudent(const Student &new_student) {
        if (student_count < MAX_STUDENTS) {
            students[student_count++] = new_student;
            cout << "Student added successfully!" << endl;
            return true;
        } else {
            cout << "Cannot add more students. Maximum limit reached." << endl;
            return false;
        }
    }

    Student* searchStudentByRollNumber(int roll_number) {
        for (int i = 0; i < student_count; ++i) {
            if (students[i].getRollNumber() == roll_number) {
                return &students[i];
            }
        }
        cout << "Student with roll number " << roll_number << " not found." << endl;
        return nullptr;
    }

    void displayAllStudents() const {
        if (student_count == 0) {
            cout << "No students in the system." << endl;
            return;
        }
        for (int i = 0; i < student_count; ++i) {
            students[i].display();
        }
    }
};

int main() {
    StudentManagementSystem sms;

    const char courses1[][50] = {"Math", "Physics", "Computer Science"};
    Student student1("Saksham", 157, 3.9, courses1, 3);
    sms.addStudent(student1);

    const char courses2[][50] = {"Chemistry", "Biology"};
    Student student2("Dev", 187, 3.7, courses2, 2);
    sms.addStudent(student2);

    sms.displayAllStudents();

    int roll_number_to_search = 12345;
    Student *searched_student = sms.searchStudentByRollNumber(roll_number_to_search);
    if (searched_student != nullptr) {
        cout << "Student found with roll number " << roll_number_to_search << ":" << endl;
        searched_student->display();
    }

    return 0;
}
