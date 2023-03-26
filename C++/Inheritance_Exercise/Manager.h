#ifndef MANAGER_HH
#define MANAGER_HH


#include<iostream>
#include<string>
#include<set>
#include"Employee.h"

using namespace std;

class Manager : public Employee {
public:
	//Constructor
	Manager(const char* name,double salary): Employee(name,salary),subordinates(){}
	/*We choose to use set because in this type of container does not allow duplicates
	which helps in the case of two employees having the same name.*/
	
	void addSubordinate(Employee& empl) {
		subordinates.insert(&empl);
	}
	
     const set<Employee*>& listOfSubordinates() const { return subordinates; }

	 void businessCard(ostream& os = cout) const {

		 Employee::businessCard();
		 set<Employee*>::iterator iter = subordinates.begin();
		 os << " Manages: " << endl;
		 while (iter != subordinates.end()) {
			 os << (*iter)->name() << endl;
			 ++iter;
		 }
	 }

private:
	
	set<Employee*> subordinates;


};



#endif
