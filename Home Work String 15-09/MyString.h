#pragma once
#include <iostream>
using namespace std;
class MyString
{
	char* str;
	int length;
public:
	static int count;
	MyString();
	MyString(int l);
	MyString(const char* n);
	~MyString();
	void Input();
	void Print();

	void MyStrcpy(MyString& obj);
	bool MyStrStr(const char* str1);
	int  MyChr(char c);
	int MyStrLen();
	void MyStrCat(MyString& b);
	void MyDelChr(char c);
	int MyStrCmp(MyString& b);

	void operator[](int ind);
	void operator()();
	char* GetStr() const;
	void SetStr(const char* d);
	int GetLength() const;
	void SetLength(int d);

	MyString& operator=(const MyString& right);

//class work list
	MyString(const MyString& obj);
	MyString(MyString&& obj6);
	MyString& operator=(MyString&& right);
	MyString(initializer_list<char> param);
};