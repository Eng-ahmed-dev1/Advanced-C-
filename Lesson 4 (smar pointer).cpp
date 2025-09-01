#include <iostream>
#include <memory>
#include <vector>
#include <algorithm> // for find_if
using namespace std;

class Student {
private:
    string name;
    int age;

public:
    Student(string n, int a) : name(n), age(a) {
        cout << "Created student: " << name << endl; // إنشاء الطالب
    }

    ~Student() {
        cout << "Deleted student: " << name << endl; // حذف الطالب
    }

    void displayInfo() {
        cout << "Student: " << name << ", Age: " << age << endl; // عرض معلومات الطالب
    }

    string getName() const { return name; }
    int getAge() const { return age; }
};

void smartPointerExample() {
    cout << "=== Smart Pointers Example ===" << endl;

    // unique_ptr - ملكية حصرية
    cout << "\n--- unique_ptr ---" << endl;
    {
        unique_ptr<Student> student1 = make_unique<Student>("Ahmed", 20);
        student1->displayInfo();

        // نقل الملكية
        unique_ptr<Student> student2 = move(student1);
        // student1 أصبح فارغ بعد النقل
        if (student1 == nullptr) {
            cout << "student1 is now nullptr after move" << endl;
        }

        student2->displayInfo();

        // حذف الكائن يدوياً
        student2.reset();
        cout << "student2 manually deleted" << endl;

        // إنشاء unique_ptr جديد
        unique_ptr<Student> student3 = make_unique<Student>("Fatima", 22);
        student3->displayInfo();

        // unique_ptr سيتم حذفه تلقائياً عند الخروج من النطاق
    }
    cout << "Scope ended - all unique_ptr deleted automatically" << endl;

    // shared_ptr - ملكية مشتركة
    cout << "\n--- shared_ptr ---" << endl;
    {
        shared_ptr<Student> student1 = make_shared<Student>("Mohamed", 21);
        cout << "Reference count of student1: " << student1.use_count() << endl;

        {
            shared_ptr<Student> student2 = student1; // مشاركة الملكية
            cout << "Reference count after sharing: " << student1.use_count() << endl;

            student1->displayInfo();
            student2->displayInfo();

            shared_ptr<Student> student3 = student1; // مرجع ثالث
            cout << "Reference count after adding third reference: " << student1.use_count() << endl;
        }
        cout << "Reference count after inner scope ended: " << student1.use_count() << endl;

        student1.reset(); // إعادة تعيين
        cout << "student1 reset" << endl;
    }

    // weak_ptr - مرجع ضعيف
    cout << "\n--- weak_ptr ---" << endl;
    {
        shared_ptr<Student> sharedStudent = make_shared<Student>("Aisha", 19);
        weak_ptr<Student> weakStudent = sharedStudent;

        cout << "Strong reference count: " << sharedStudent.use_count() << endl;
        cout << "Is weak_ptr valid? " << (!weakStudent.expired() ? "Yes" : "No") << endl;

        // استخدام weak_ptr بأمان
        if (auto lockedStudent = weakStudent.lock()) {
            lockedStudent->displayInfo();
            cout << "Accessed safely via weak_ptr" << endl;
        }

        sharedStudent.reset();
        cout << "shared_ptr deleted" << endl;
        cout << "Is weak_ptr valid now? " << (!weakStudent.expired() ? "Yes" : "No") << endl;

        if (auto lockedStudent = weakStudent.lock()) {
            lockedStudent->displayInfo();
        }
        else {
            cout << "Cannot access - weak_ptr expired" << endl;
        }
    }

    // استخدام smart pointers في containers
    cout << "\n--- Smart Pointers in Containers ---" << endl;
    {
        vector<unique_ptr<Student>> students;

        students.push_back(make_unique<Student>("Ali", 23));
        students.push_back(make_unique<Student>("Maryam", 20));
        students.push_back(make_unique<Student>("Youssef", 24));

        cout << "Student list using unique_ptr:" << endl;
        for (const auto& student : students) {
            student->displayInfo();
        }

        // البحث عن طالب بالاسم
        string searchName = "Maryam";
        auto it = find_if(students.begin(), students.end(),
            [&searchName](const unique_ptr<Student>& s) {
                return s->getName() == searchName;
            });

        if (it != students.end()) {
            cout << "Found student: ";
            (*it)->displayInfo();
        }

        // إزالة طالب
        students.erase(students.begin() + 1); // Remove second student
        cout << "After removing a student:" << endl;
        for (const auto& student : students) {
            student->displayInfo();
        }

        // جميع الطلاب سيتم حذفهم تلقائياً عند خروج vector من النطاق
    }
    cout << "All students in vector automatically deleted" << endl;

    // Custom deleter
    cout << "\n--- Custom Deleter ---" << endl;
    {
        auto customDeleter = [](Student* s) {
            cout << "Custom deletion for student: " << s->getName() << endl;
            delete s;
            };

        unique_ptr<Student, decltype(customDeleter)> student(
            new Student("Khaled", 25), customDeleter);

        student->displayInfo();
        // سيتم استخدام الحذف المخصص عند خروج pointer من النطاق
    }
}

int main() {
    smartPointerExample(); // تشغيل كل الأمثلة على Smart Pointers
    return 0;
}

