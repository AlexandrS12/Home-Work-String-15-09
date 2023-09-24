#include "MyString.h"
#include <iostream>
using namespace std;

MyString::MyString() : length(90)
{
	str = new char[length + 1];
	for (int i = 0; i < length; i++)
	{
		str[i] = 'a';
	}
	str[length] = '\0';
	count++;
	cout << "Constructor by default"<<endl;
}

MyString::MyString(int l)
{
	if (l <= 1)
	{
		l = 1;
	}
	length = l;
	str = new char[length + 1];

	for (int i = 0; i < length; i++)
	{
		str[i] = 'e';
	}
	str[length] = '\0';
	count++;
	cout << "Constructor with params"<<endl;
}

MyString::MyString(const char* n)
{
	str = new char[strlen(n) + 1];
	strcpy_s(str, strlen(n) + 1, n);
	length = strlen(n);
	count++;
	cout << "Constructor with input params"<<endl;
}

MyString::~MyString()
{
	delete[] str;
	cout << "Destructor"<<endl;
}

void MyString::Input()
{
	if (str != nullptr) {
		cout << "Delete str..." << str << endl;
		delete[] str;
		length = 0;
	}
	cout << "Enter string: ";
	char buff[255];
	cin.getline(buff, sizeof(buff));
	length = strlen(buff);
	str = new char[length + 1];
	strcpy_s(str, length + 1, buff);
	count++;
}

void MyString::Print()
{
	cout << "String: [" << str << "]\nLength: " << length << endl;
}

void MyString::MyStrcpy(MyString& obj)
{
	if (str != nullptr)
	{
		delete[] str;
		length = obj.length;
		str = new char[length + 1];
		strcpy_s(str, strlen(obj.str) + 1, obj.str);
	}
	count++;
}

bool MyString::MyStrStr(const char* str1)
{
	const char* rez = strstr(str, str1);
	if (rez != nullptr) {
		count++;
		return true;
	}
	else {
		return false;
	}
}


int MyString::MyChr(char c)
{
	count++;
	int index = 0;
	while (str[index] != '\0') {
		if (str[index] == c) {
			return index;
		}
		index++;
	}
	return -1;
}

int MyString::MyStrLen()
{
	int length = 0;
	while (str[length] != '\0') {
		length++;
	}
	return length;
}

void MyString::MyStrCat(MyString& b)
{
	count++;
	char* nStr = new char[length + b.length + 1];
	strcpy_s(nStr, length + b.length + 1, str);
	strcat_s(nStr, length + b.length + 1, b.str);
	delete[] str;
	str = nStr;
	length = length + b.length;
}

void MyString::MyDelChr(char c)
{
	count++;
	char* start = str;
	char* end = str;
	while (*start) {
		if (*start != c) {
			*end = *start;
			end++;
		}
		start++;
	}
	*end = '\0';
	length = strlen(str);
}

int MyString::MyStrCmp(MyString& b)
{
	count++;
	int a1 = strlen(str);
	int b1 = strlen(b.str);

	if (a1 > b1) {
		return 1;
	}
	else if (a1 < b1) {
		return -1;
	}
	else {
		return 0;
	}
}

void MyString::operator[](int ind)
{
	count++;
	if (ind >= 0)
	{
		MyString m("ITStep-Best!");
		m.Print();
	}
	else {
		cout << "Bye!" << endl;
	}
}

void MyString::operator()()
{
	count++;
	MyString myString("Random string");
	myString.Print();
}

char* MyString::GetStr() const
{
	return str;
}

void MyString::SetStr(const char* d)
{
	if (str != nullptr) {
		delete[] str;
	}
	length = strlen(d);
	str = new char[length + 1];
	strcpy_s(str, length + 1, d);
}

int MyString::GetLength() const
{
	return length;
}

void MyString::SetLength(int d)
{
	if (d >= 0) {
		length = d;
	}
	else {
		length = 0;
	}
}

MyString& MyString::operator=(const MyString& right)
{
	if (this != &right)
	{
		delete[] str;
		str = new char[right.length + 1];
		length = right.length;

		for (int i = 0; i < length; ++i)
		{
			str[i] = right.str[i];
		}
		str[length] = '\0';
	}
	return *this;
}

MyString::MyString(const MyString& obj)
{
	str = new char[obj.length + 1];
	length = obj.length + 1;

	for (int i = 0; i < length + 1; ++i)
	{
		str[i] = obj.str[i];
	}
	str[length] = '\0';
}

MyString::MyString(MyString&& obj6)
{
	length = obj6.length;
	str = obj6.str;
	obj6.length = 0;
	obj6.str = nullptr;
	count++;
	cout << "Move constructor"<<endl;
}

MyString& MyString::operator=(MyString&& right)
{
	if (this == &right)
	{
		return *this;
	}
	delete[]str;

	length = right.length;
	right.length = 0;
	str = right.str;
	right.str = nullptr;
	cout << "Move constructor"<<endl;
	count++;
	return *this;
}

MyString::MyString(initializer_list<char> param) {
	length = param.size();
	str = new char[length];
	for (auto pt = param.begin(); pt != param.end(); pt++) {
		*str = *pt;
		str++;
	}
	str -= length;
}