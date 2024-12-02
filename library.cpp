#include"identity.h"
#include"manager.h"
#include"student.h"
#include"teacher.h"


void menu() {//main menu
	system("cls");
	cout << "\t\t\t\t----------------------------------" << endl;
	cout << "\t\t\t\t**********************************" << endl;
	cout << "\t\t\t\t--------   Library_System --------" << endl;
	cout << "\t\t\t\t----------------------------------" << endl;
	cout << "\t\t\t\t--------    status_choose --------" << endl;
	cout << "\t\t\t\t----------------------------------" << endl;
	cout << "\t\t\t\t--------  1.   Student    --------" << endl;
	cout << "\t\t\t\t----------------------------------" << endl;
	cout << "\t\t\t\t--------  2.   Teacher    --------" << endl;
	cout << "\t\t\t\t----------------------------------" << endl;
	cout << "\t\t\t\t--------  3.   Manager    --------" << endl;
	cout << "\t\t\t\t----------------------------------" << endl;
	cout << "\t\t\t\t--------  4.   Menu       --------" << endl;
	cout << "\t\t\t\t----------------------------------" << endl;
	cout << "\t\t\t\t--------  5.   Exit       --------" << endl;
	cout << "\t\t\t\t**********************************" << endl;
	cout << "\t\t\t\t----------------------------------" << endl;

}

int main(){
	Manager m;
	Student s;
	Teacher t;
	int a = 0;
	char b = ' ';
	menu();
	while (true)
	{
		cout<<"Please Input Your Choice: ";
		cin >> a;
		switch (a) {
		case 1://choice student
			system("cls");
			cout << "Welcome to student system" << endl;
			cout << "Please input no: " << endl;//student_id
			cin >> s.Num;
			cout << "Please input your name: " << endl;//student_name
			cin >> s.Name;
			s.Save();//if exit continue
			while (true) {
				s.Menu();
				cout << "please input:";
				cin >> b;
				switch (b) {
				case 'a':
					cout << "Take_book" << endl;//borrow book
					s.Take_Book();
					break;
				case 'b':
					cout << "Return_book" << endl;//return book
					s.Return_Book();
					break;
				case 'c':
					s.All_books();//all_books
					break;
				case'd':
					return main();//return main
					break;
				default:
					cout<<"Error" << endl;
					return main();
				}
			}
			break;
		case 2://choice teacher
			system("cls");
			cout << "Welcome to teacher system" << endl;
			cout << "Please input no: " << endl;//teacher_id
			cin >> t.Num;
			cout << "Please input your name: " << endl;//teacher_name
			cin >> t.Name;
			t.Save();//if exit continue
			while (true) {
				t.Menu();
				cout << "please input:";
				cin >> b;
				switch (b) {
				case 'a':
					cout << "Take_book" << endl;//borrow book
					t.Take_Book();
					break;
				case 'b':
					cout << "Return_book" << endl;//return book
					t.Return_Book();
					break;
				case 'c'://all_books
					t.All_books();
					break;
				case'd':
					return main();//return main
					break;
				default:
					cout << "Error" << endl;
					return main();
				}
			}
			break;
		case 3://choice manager
			system("cls");
			cout<<"Welcome to manager system" << endl;
			cout<<"Please input no: " << endl;//manager_id
			cin >> m.Num;
			cout <<"Please input your name: " << endl;//manager_name
			cin >> m.Name;
			m.Save();
			while (true) {
				m.Menu();
				cout <<"please input:";
				cin >> b;
				switch (b) {
				case 'a':
					cout << "ADD" << endl;//add books
					m.Add();
					break;
				case 'b':
					cout << "Delete" << endl;//delete books
					m.Delete();
					break;
				case 'c':
					cout << "Modify" << endl;//modify books
					m.Modify();
					break;
				case 'd':
					return main();//return main
					break;
				default:
					cout << "Error" << endl;
					return main();
				}
			}
			break;
		case 4://choice menu
			menu();
			break;
		case 5://choice exit
			cout<<"THANK U FOR YOUR USE!" << endl;
			system("pause");
			return 0;
			break;
		default://error
			cout<<"Input error" << endl;
			break;
		}
	}
	system("pause>0");
	return 0;
}