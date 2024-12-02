#pragma once
#include "identity.h"
class Manager:public Identity {//son
public:
	Manager() {}
	Manager(int num, string name):Identity(num,name){}
	virtual void Menu();
	virtual void Save();
	void Add();
	void Delete();
	void Modify();
	Manager* m;
};