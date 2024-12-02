#pragma once
#include<iostream>
#include<string>
#include<windows.h>
#include<iomanip>
#include<string>
#include<vector>
#include<fstream>
#define n 1
using namespace std;
class Identity {//base class
public:
	Identity() {
		Num = 0;
		Name = " ";
	}
	Identity(int num,string name):Num(num),Name(name) {}
	virtual void Menu() = 0;//menu
	virtual void Save() = 0;//save txt
	virtual ~Identity() {}
	int Num;//num
	string Name;//name
};