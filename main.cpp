#include<iostream>
#include"ClassString.h"
#include <clocale>


int main()
{
setlocale(LC_ALL, "Russian");

	char* str1 = nullptr;
	char str2;
	char str3;
	classString t1, t2, t3, t4,t5;

	t1.SetConstString("World");
	str1 = t1.GetString();
	t2.SetConstString("Hello World");
	cout << str1 << " - под слово для вхождения в строку: "<< t2 << endl;

	cout << t2.FindFirstWord(str1) << "-й символ: первое вхождение под слова " << endl;

	cin >> str2;
	t3.SetConstString("Hello World");
	cout << t3.FindFirstSymb(str2)<< "-й первый символ вхождения в строке" << endl;

	t4.SetConstString("Hello_World_My Friend"); 
	cin >> str3;
	t4.FindSub(str3);

	t5.SetConstString("Hi");
	t5.duplication(3);
	cout << t5;

	return 0;
}
