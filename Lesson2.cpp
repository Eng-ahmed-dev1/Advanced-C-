#include <iostream>
#include <string>
using namespace std;

struct Student {
    string name;
    int age;
    double gpa;
};

void studentDatabaseExample() {
    cout << "=== Dynamic Student Database ===" << endl;

    int numStudents;
    cout << "How many students: ";
    cin >> numStudents;

    // تخصيص مصفوفة ديناميكية من الطلاب في الـ Heap
    Student* students = new Student[numStudents];

    // إدخال بيانات الطلاب
    for (int i = 0; i < numStudents; i++) {
        cout << "Student " << (i + 1) << ":" << endl;
        cout << "Name: ";
        cin >> students[i].name;
        cout << "Age: ";
        cin >> students[i].age;
        cout << "GPA: ";
        cin >> students[i].gpa;
    }

    // عرض بيانات الطلاب
    cout << "\n=== Students Data ===" << endl;
    for (int i = 0; i < numStudents; i++) {
        cout << "Student " << (i + 1) << ": "
            << students[i].name << ", "
            << students[i].age << " years, "
            << "GPA: " << students[i].gpa << endl;
    }

    // البحث عن أعلى معدل
    double maxGPA = students[0].gpa;
    string topStudent = students[0].name;

    for (int i = 1; i < numStudents; i++) 
    {
        if (students[i].gpa > maxGPA)
        {
            maxGPA = students[i].gpa;
            topStudent = students[i].name;
        }
    }

    cout << "\nTop Student: " << topStudent
        << " with GPA " << maxGPA << endl;

    // تحرير الذاكرة المحجوزة في الـ Heap
    delete[] students;
    cout << "Memory freed successfully" << endl;
}

int main() {
    studentDatabaseExample(); // استدعاء الدالة الرئيسية
    return 0;
}
