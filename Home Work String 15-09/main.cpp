#include <iostream>
#include <cstring>
#include "MyString.h"
using namespace std;

int MyString::count = 0;

MyString operator+(const MyString& obj, const int a)
{
    MyString rez;
    rez.SetLength(obj.GetLength() + a);
    const char* origStr = obj.GetStr();
    char* nStr = new char[rez.GetLength() + 1];
    strcpy_s(nStr, rez.GetLength() + 1, origStr);
    for (int i = obj.GetLength(); i < rez.GetLength(); i++) {
        nStr[i] = 'a';
    }
    nStr[rez.GetLength()] = '\0';
    rez.SetStr(nStr);
    delete[] nStr;
    return rez;
}

MyString operator+(const int a, const MyString& obj)
{
    MyString rez;
    const char* origStr = obj.GetStr();
    int newLength = obj.GetLength() + a;
    char* nStr = new char[newLength + 1];
    strcpy_s(nStr, newLength + 1, origStr);
    for (int i = obj.GetLength(); i < newLength; i++) {
        nStr[i] = 'a';
    }
    nStr[newLength] = '\0';
    rez.SetStr(nStr);
    rez.SetLength(newLength);
    delete[] nStr;
    return rez;
}

MyString& operator+=(MyString& obj, int a)
{
    obj.SetLength(obj.GetLength() + a);
    return obj;
}

MyString& operator++(MyString& obj)
{
    const int SIZE = strlen(obj.GetStr());
    char* newStr = new char[SIZE + 2];

    strcpy_s(newStr, SIZE + 2, obj.GetStr());

    newStr[SIZE] = '$';
    newStr[SIZE + 1] = '\0';

    delete[] obj.GetStr();
    obj.SetStr(newStr);

    return obj;
}

MyString operator++(MyString& obj, int)
{
    MyString temp(obj);
    const int SIZE = strlen(obj.GetStr());
    char* newStr = new char[SIZE + 2];

    newStr[0] = '$';
    strcpy_s(newStr + 1, SIZE + 1, obj.GetStr());

    delete[] obj.GetStr();
    obj.SetStr(newStr);

    return temp;
}

ostream& operator<<(ostream& os, const MyString& obj)
{
    os << "String: " << obj.GetStr() << endl;
    os << "Length: " << obj.GetLength() << endl;
    return os;
}

istream& operator>>(istream& is, MyString& obj)
{
    char* a = new char[obj.GetLength() + 1];
    int b;
    is >> a;
    obj.SetStr(a);
    is >> b;
    obj.SetLength(b);
    return is;
}

int main() {
    MyString example_1;
    example_1.Print();
    cout << endl;

    MyString example_2(12);
    example_2.Print();
    cout << endl;

    MyString example_3("Hi, How are You?");
    example_3.Print();
    cout << endl;

    example_1.Input();
    example_1.Print();
    cout << endl;

    example_2.MyStrcpy(example_3);
    example_3.Print();
    cout << endl;

    MyString example_4("Hi! Lets check string!");
    example_4.Print();
    cout << endl;

    const char* substr = "string";
    if (example_4.MyStrStr(substr)) {
        cout << substr << " - found in the string." << endl;
    }
    else {
        cout << substr << " isn't found in the string." << endl;
    }
    cout << endl;

    MyString example_5;
    example_5.operator[](12);
    example_5.operator()();
    cout << endl;

    MyString example_6("Welcome to IT-Step!");
    char value = 'i';
    example_6.MyChr(value);
    cout << "Value is " << value << endl << endl;

    MyString str("qwerty");
    int size = str.GetLength();
    cout << "Size: " << size << endl << endl;

    MyString example_7("Audi ");
    MyString example_8("Q8 Quatro");
    example_7.MyStrCat(example_8);
    example_7.Print();
    cout << endl;

    MyString example_9("friend");
    example_9.MyDelChr('a');
    example_9.Print();
    cout << endl;

    MyString example_10("apple");
    MyString example_11("pineapple");
    int result = example_10.MyStrCmp(example_11);
    cout << "Result: " << result << endl;

    cout << endl;

    MyString example_12("Mercedes");
    MyString example_13("Benz");

    MyString example_14 = example_13 + 10;
    example_14.Print();
    MyString example_15 = 5 + example_12;
    example_15.Print();
    example_12 += 10;
    example_12.Print();

    MyString str1 = "Good morning Tom";
    MyString str2 = "sadaddasdasda";
    str1.Print();
    cout << endl;
    str2 = str1;
    str2.Print();

    MyString obj1("beautiful");
    MyString obj2("handsome");
    MyString obj3("funny");
    MyString obj4("relax");
    MyString obj5("day");
    MyString obj6(move(obj5));
    cout << obj1;
    cout << obj2 << obj1;
    cin >> obj3;
    cout << obj3;

    obj3 = move(obj4);
    obj3.Print();

    obj6.Print();

    MyString ob{ 'I', 'T', 'S', 't', 'e','p' , '\0' };
    ob.Print();

    cout << "Count MyString: " << MyString::count << endl;
}