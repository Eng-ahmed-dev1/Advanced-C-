#include <iostream>
#include <string>
using namespace std;

// Enum لتمثيل حالة الطالب
enum class StudentStatus {
    Active,     // الطالب مازال بيدرس
    Graduated,  // الطالب اتخرج
    Suspended   // الطالب موقوف
};

// Struct لتمثيل بيانات الطالب
struct Student {
    string name;           // اسم الطالب
    int age;               // عمر الطالب
    double gpa;            // المعدل التراكمي
    StudentStatus status;  // حالة الطالب
};

// دالة لطباعة معلومات الطالب
void printStudent(const Student& s) {
    cout << "Name: " << s.name << endl;
    cout << "Age: " << s.age << endl;
    cout << "GPA: " << s.gpa << endl;

    cout << "Status: ";
    switch (s.status) {
    case StudentStatus::Active:
        cout << "Active";
        break;
    case StudentStatus::Graduated:
        cout << "Graduated";
        break;
    case StudentStatus::Suspended:
        cout << "Suspended";
        break;
    }
    cout << endl << "-----------------" << endl;
}

struct Point {
    int x;
    int y;

    void print() {
        cout << "(" << x << ", " << y << ")" << endl;
    }
};

// main
int main() {
    // إنشاء بعض الطلاب
    Student s1 = { "Ahmed", 20, 3.5, StudentStatus::Active };
    Student s2 = { "Mona", 22, 3.9, StudentStatus::Graduated };
    Student s3 = { "Omar", 19, 2.0, StudentStatus::Suspended };

    // طباعة بيانات الطلاب
    printStudent(s1);
    printStudent(s2);
    printStudent(s3);

    return 0;
    //=========================================
    enum class Color {
        Red,
        Green,
        Blue
    };

    Color c = Color::Red;   // لازم تكتب اسم الـ enum
    // int x = Color::Red;  // خطأ! مش بيتحول تلقائي لـ int
    //===========================================
    Point p1;        // إنشاء كائن من الـ struct
    p1.x = 10;
    p1.y = 20;

    p1.print();      // استدعاء دالة عضو
}
