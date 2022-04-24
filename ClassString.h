#pragma once
#include<iostream>

using namespace std;

class classString
{
protected:
	int len;
	char* str;
public:
	classString();
	classString(int _length, char s);
	classString(const classString& p);
	~classString();

	int GetLength();
	void SetLength(int _length);
	void SetString(char* _string);
	void SetConstString(const char* _string);

	bool operator < (const classString& p);
	bool operator > (const classString& p);
	bool operator ==(const classString& p);
	classString& operator = (const classString& p);
	classString operator + (const classString& p);
	char& operator [](int i);
	friend std::istream& operator >> (std::istream& stream, classString& p);
	friend std::ostream& operator << (std::ostream& stream, const classString& p);

	int FindFirstSymb(char symbol);
	int FindFirstWord(char* _string);
	void FindSub(char symbol);
	classString& duplication(int count);



	char* GetString();


};