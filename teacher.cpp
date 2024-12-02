#include"teacher.h"

void Teacher::Menu() {

	cout << "\t\t\t\t----------------------------------" << endl;
	cout << "\t\t\t\t**********************************" << endl;
	cout << "\t\t\t\t----Teacher:" << Name << "--------" << endl;
	cout << "\t\t\t\t----------------------------------" << endl;
	cout << "\t\t\t\t-------- a.   Take_BOOKS   --------" << endl;
	cout << "\t\t\t\t----------------------------------" << endl;
	cout << "\t\t\t\t-------- b.  RETURN_BOOKS --------" << endl;
	cout << "\t\t\t\t----------------------------------" << endl;
	cout << "\t\t\t\t-------- c.     Books     --------" << endl;
	cout << "\t\t\t\t----------------------------------" << endl;
	cout << "\t\t\t\t-------- d.     exit      --------" << endl;
	cout << "\t\t\t\t**********************************" << endl;
	cout << "\t\t\t\t----------------------------------" << endl;
}

void Teacher::Save() {
	string file = "Teacher_file.txt";
	ifstream ifs;
	ifs.open(file, ios::in);
	if (!ifs.is_open()) {
		cout << "Error opening file" << endl;
	}
	int no = 0;
	string name = " ";
	while (ifs >> no, ifs >> name) {
		if (no == Num && name == Name) {
			cout << "Success" << endl;
			return;
		}
	}
	cout << "Error not found this teacher!!!" << endl;
	exit(0);
}

void Teacher::Take_Book() {
	vector<string>v;
	ifstream ifs;
	ifs.open("ALL_Book.txt", ios::in);
	if (!ifs.is_open()) {
		cout << "Error opening file" << endl;
	}

	string s1 = " ";
	while (ifs >> ws >> s1) {
		cout << s1 << " ";
		v.push_back(s1);
	}

	string b = " ";
	cin.ignore();
	cout << endl;
	cout << "Please input book name: ";
	getline(cin, b);

	for (int i = 0; i < v.size(); i++) {
		if (v[i] == b) {
			v.erase(v.begin() + i);
		}
	}

	string a = " ";
	while (getline(ifs, a)) {
		if (b == a) {
			cout << "U get book is " << a << endl;

			return;
		}
	}
	ifs.close();
	ofstream ofs("ALL_Book.txt", ios::trunc);
	cout << "The Books : ";
	for (vector<string>::iterator it = v.begin(); it != v.end(); it++) {
		cout << *it << " ";
		ofs << *it << endl;
	}
}


void Teacher::Return_Book() {
	vector<string> v;
	ifstream ifs;
	ifs.open("ALL_Book.txt", ios::in);
	if (!ifs.is_open()) {
		cout << "Error opening file" << endl;
	}
	string b = " ";
	cin.ignore();
	cout << "Please input return_book name: ";
	getline(cin, b);
	string a = " ";
	while (getline(ifs, a)) {
		if (b == a) {
			cout << "The book has been return" << a << endl;
			return;
		}
	}
	ifs.close();
	ofstream ofs("ALL_Book.txt", ios::app);
	ofs << b << endl;
	ofs.close();
}

void Teacher::All_books() {
	ifstream ifs("ALL_Book.txt", ios::in);
	string s = " ";
	while (getline(ifs,s)) {
		cout <<s<<endl;
	}
	ifs.close();
}