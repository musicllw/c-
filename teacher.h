#pragma once
#include"identity.h"
class Teacher :public Identity {//son
public:
	Teacher() {}
	Teacher(int num, string name):Identity(num, name) {}
	virtual void Menu();
	virtual void Save();
	void Take_Book();
	void Return_Book();
	void All_books();
	Teacher* s;
};