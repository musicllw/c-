#include "manager.h"


void Manager::Menu() {
	system("cls");
	cout << "\t\t\t\t----------------------------------" << endl;
	cout << "\t\t\t\t**********************************" << endl;
	cout << "\t\t\t\t--------Manager:"<<Name<<"--------" << endl;
	cout << "\t\t\t\t----------------------------------" << endl;
	cout << "\t\t\t\t-------- a.   ADD_BOOKS   --------" << endl;
	cout << "\t\t\t\t----------------------------------" << endl;
	cout << "\t\t\t\t-------- b.  DELETE_BOOKS --------" << endl;
	cout << "\t\t\t\t----------------------------------" << endl;
	cout << "\t\t\t\t-------- c.  MODIFY_BOOKS --------" << endl;
	cout << "\t\t\t\t----------------------------------" << endl;
	cout << "\t\t\t\t-------- d.     exit      --------" << endl;
	cout << "\t\t\t\t----------------------------------" << endl;
	cout << "\t\t\t\t**********************************" << endl;
	cout << "\t\t\t\t----------------------------------" << endl;
}

void Manager::Save() {
	string file = "book_file.txt";//identify_manager_txt
	ifstream ifs;
	ifs.open(file,ios::in);//read
	if (!ifs.is_open()) {//if not open
		cout << "file open is error" << endl;
	}
	int no=0;
	string s=" ";
	while (ifs>>no,ifs>>s) {
		if (Num == no && Name == s) {
			cout<<"SUCCESS" << endl;
			cout <<"Manager_no: " << no <<" Manager_name: " << s << endl;
			break;
		}
		cout<<"ERROR"<< endl;
		exit(0);
	}
	ifs.close();
}

void Manager::Add() {
	vector<string> v;
	string a = " ";
	int b = 0;
	string file = "ALL_Book.txt";
	ofstream ofs;
	ofs.open(file,ios::app);
	if (!ofs.is_open()) {
		cout<<"Error Opening the file" << endl;
		return;
	}
	cout << "Please input add number:";
	cin >> b;
	
	cin.ignore();
	for (int i = 0; i < b;i++) {
		cout << "Please add the book:";
		getline(cin, a);
		v.push_back(a);
	}
	cout << endl;
	
	for (vector<string>::iterator it = v.begin(); it != v.end();it++) {
		ofs << *it <<" ";
	}
	ofs.close();
	ifstream ifs;
	ifs.open(file,ios::in);
	if (!ifs.is_open()) {
		cout << "Error Opening the file" << endl;
		return;
	}
	string s = " ";
	while (getline(ifs,s)) {
		cout << s <<" ";
		cout << endl;
	}
	ifs.close();
	system("pause");
}
 
void Manager::Delete() {
	vector<string> v;
	
	ifstream ifs("ALL_Book.txt", ios::in);
	if (!ifs.is_open()) {
		cout << "Error opening file" << endl;
	}

	string s1 = " ";
	while (ifs>>ws>>s1) {
		cout << s1 << " ";
		v.push_back(s1);
	}

	string s = " ";
	cin.ignore();
	cout << endl;
	cout<<"please input delete_book: ";
	getline(cin,s);
	
	for (int i = 0; i < v.size();i++) {
		if (v[i]==s) {
			v.erase(v.begin()+i);
			cout << "Delete Success" << endl;
		}
	}
	ifs.close();

	ofstream ofs("ALL_Book.txt", ios::trunc);
	if (!ofs.is_open()) {
		cout << "Error opening file" << endl;
	}
	for (vector<string>::iterator it = v.begin(); it != v.end(); it++) {
		cout<<*it<<" ";
		ofs << *it << " ";
	}
	ofs.close();
	system("pause");
}

void Manager::Modify() {
	vector<string> v;

	ifstream ifs("ALL_Book.txt", ios::in);
	if (!ifs.is_open()) {
		cout << "Error opening file" << endl;
	}

	string s1 = " ";
	while (ifs >> ws >> s1) {
		cout << s1 << " ";
		v.push_back(s1);
	}

	string s = " ";
	cin.ignore();
	cout << endl;
	cout << "please input modify_book: ";
	getline(cin, s);
	string s2 = " ";
	for (int i = 0; i < v.size(); i++) {
		if (v[i] == s) {
			cout<<"Please input the new book_name: " << endl;
			getline(cin,s2);
			v[i] = s2;
			cout << "Modify Success" << endl;
		}
	}
	ifs.close();

	ofstream ofs("ALL_Book.txt", ios::trunc);
	if (!ofs.is_open()) {
		cout << "Error opening file" << endl;
	}
	for (vector<string>::iterator it = v.begin(); it != v.end(); it++) {
		cout << *it << " ";
		ofs << *it <<" ";
	}
	ofs.close();
	system("pause");
}