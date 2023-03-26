#include<iostream>
#include"Employee.h"
#include"Manager.h"
using namespace std;

int main() {
	Employee emp1("Wouter", 1000);
	cout <<emp1.name()<<" buisness card is printed bellow." << endl;
	emp1.businessCard();
	cout << emp1.name()<<" salary is : " << emp1.salary() << " Unit of money." << endl;

	Employee emp2("Ivo", 1200);
	cout << emp2.name() << " buisness card is printed bellow." << endl;
	emp2.businessCard();
	cout << emp2.name() << " salary is : " << emp2.salary() << " Unit of money." << endl;

	Manager mngr1("Stan", 2000);
	mngr1.addSubordinate(emp1);
	mngr1.addSubordinate(emp2);
	cout << mngr1.name() << " buisness card is printed bellow." << endl;
	mngr1.businessCard();
	cout << mngr1.name()<< " salary is : " << mngr1.salary() << " Unit of money." << endl;

	Manager mngr2("Jo", 2200);
	cout << mngr2.name() << " buisness card is printed bellow." << endl;
	mngr2.businessCard();
	cout << mngr2.name() << " salary is : " << mngr2.salary() << " Unit of money." << endl;

	Manager mngr3("Frank", 3000);
	mngr3.addSubordinate(mngr1);
	mngr3.addSubordinate(mngr2);
	cout << mngr3.name() << " buisness card is printed bellow." << endl;
	mngr3.businessCard();
	cout << mngr3.name() << " salary is : " << mngr3.salary() << " Unit of money." << endl;

	return 0;
}