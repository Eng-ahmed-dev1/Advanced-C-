#include <iostream>
#include <vector>
#include <list>
#include <iterator>
using namespace std;

void iteratorExample() {
    cout << "=== أمثلة مختصرة على Iterators ===" << endl;

    vector<int> numbers = { 10, 20, 30, 40, 50 };

    // 1. Forward Iterator - التنقل للأمام
    cout << "\nForward Iterator: ";
    for (auto it = numbers.begin(); it != numbers.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;

    // 2. Reverse Iterator - التنقل للخلف
    cout << "Reverse Iterator: ";
    for (auto it = numbers.rbegin(); it != numbers.rend(); ++it) {
        cout << *it << " ";
    }
    cout << endl;

    // 3. Const Iterator - قراءة فقط
    cout << "Const Iterator: ";
    for (auto it = numbers.cbegin(); it != numbers.cend(); ++it) {
        cout << *it << " ";
        // *it = 100; // خطأ: لا يمكن تعديل العنصر
    }
    cout << endl;

    // 4. Random Access Iterator - العمليات الحسابية على الـ Iterator
    auto it = numbers.begin();
    it += 2; // الانتقال للعنصر الثالث
    cout << "Random Access (3rd element): " << *it << endl;

    // 5. Insert Iterator - النسخ والإدخال
    vector<int> destVec;
    copy(numbers.begin(), numbers.end(), back_inserter(destVec)); // النسخ في نهاية الـ vector
    cout << "Back inserter: ";
    for (int num : destVec) cout << num << " ";
    cout << endl;

    list<int> destList;
    copy(numbers.begin(), numbers.end(), front_inserter(destList)); // النسخ في بداية الـ list
    cout << "Front inserter: ";
    for (int num : destList) cout << num << " ";
    cout << endl;

    vector<int> destPos = { 1, 2, 3 };
    copy(numbers.begin(), numbers.begin() + 2, inserter(destPos, destPos.begin() + 1)); // إدخال في موضع محدد
    cout << "Insert at specific position: ";
    for (int num : destPos) cout << num << " ";
    cout << endl;

    // 6. Stream Iterator - قراءة من المستخدم
    cout << "Enter 3 numbers: ";
    vector<int> input;
    copy_n(istream_iterator<int>(cin), 3, back_inserter(input));
    cout << "Entered numbers: ";
    copy(input.begin(), input.end(), ostream_iterator<int>(cout, " "));
    cout << endl;
}
int main()
{
    iteratorExample();
}