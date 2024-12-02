#pragma once
#include"identity.h"
class Student:public Identity {//son
public:
	Student() {}
	Student(int num, string name):Identity(num,name){}
	virtual void Menu();
	virtual void Save();
	void Take_Book();
	void Return_Book();
	void All_books();
	Student* s;
};