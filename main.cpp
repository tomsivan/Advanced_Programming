#include <iostream>
#include "PersonArray_t.h"
#include "Person_t.h"
#include "Test_t.h"

using namespace std;

bool is_digits(const std::string &str)
{
    return str.find_first_not_of("0123456789") == std::string::npos;
}

int getDecimal(std::string &str)
{
    while (!is_digits(str))
    {
        cout << "Enter decimal value: ";
        cin >> str;
        cout << endl;
    }
    
    return atoi(str.c_str());
}

Person_t* takePersonDetails()
{
    int age;
    string name, str;
    
    cout << "Enter name: ";
    cin >> name;
    cout << "Enter age: ";
    cin >> str;
    cout << endl;
    age = getDecimal(str);
    
    return new Person_t(name, age);
}
/*
int main(){
	bool cont = true;
	Test_t* test;
	int initialValue;
	string str;
	int expand;
	int indx;

	cout << "Init array. Enter initial array size ('0' = default - expand value): ";
	cin >> str;
	cout << endl;

	initialValue = getDecimal(str);

	cout << "Enter expand value ('0' = default - 16): ";
	cin >> str;
	cout << endl;

	expand = getDecimal(str);

	if (expand == 0)
		expand = 16;

	if (initialValue == 0)
		test = new Test_t(expand);
	else
		test = new Test_t(initialValue, expand);

	while (cont){
		string c;
		int choise;

		cout << "Enter your choise:" << endl
			<< "1 - get number of elements" << endl
			<< "2 - get m_capacity of array" << endl
			<< "3 - insert new element" << endl
			<< "4 - get first element" << endl
			<< "5 - get last element" << endl
			<< "6 - find element" << endl
			<< "7 - remove element" << endl
			<< "8 - remove and delete element" << endl
			<< "9 - remove all elements" << endl
			<< "10 - remove and delete all elements" << endl
			<< "11 - append new element" << endl
			<< "12 - prepend new element" << endl
			<< "13 - print array" << endl
			<< "0 - quit" << endl
			<< "So What would you like to do? ";
		cin >> c;

		choise = getDecimal(c);

		switch (choise) {
		case 1:
			cout << "Number of elements is: " << test->getNumofElem() << endl;
			break;
		case 2:
			cout << "m_capacity is: " << test->getm_capacity() << endl;
			break;
		case 3:
			test->insert(takePersonDetails());
			break;
		case 4:
			test->getFirstElement();
			break;
		case 5:
			test->getLastElement();
			break;
		case 6:
			test->findElement(takePersonDetails());
			break;
		case 7:
			test->removeElement(takePersonDetails());
			break;
		case 8:
			test->removeAndDeleteElement(takePersonDetails());
			break;
		case 9:
			test->removeAllElements();
			break;
		case 10:
			test->removeAndDeleteAllElements();
			break;
		case 11:
			cout << "Enter indx in which you want to append: ";
			cin >> indx;
			cout << endl;
			test->append(indx, takePersonDetails());
			break;
		case 12:
			cout << "Enter indx in which you want to prepend: ";
			cin >> indx;
			cout << endl;
			test->prepend(indx, takePersonDetails());
			break;
		case 13:
			test->printArr();
			break;
		default:
			cont = false;
			break;
		}
		cout << "----------------------------------------------" << endl;
	}
}*/

int main(){
    Person_t* rony = new Person_t("rony",25);
    Person_t* tom = new Person_t("tom",27);
    Person_t* eliraz = new Person_t("eliraz",27);
    Person_t* guy = new Person_t("guy",26);
    Person_t* sharon = new Person_t("sharon",28);
    
    PersonArray_t* arr = new PersonArray_t(2);
    PersonArray_t* arr2 = new PersonArray_t(3);
    
    arr->insert(tom);
    arr->insert(rony);
    arr2->insert(tom);
    arr2->insert(rony);
    arr->insert(eliraz);
    arr2->insert(eliraz);
    cout<<"---------------------------------------------------------"<<endl;
    cout<< "arrays suppose to be the same but with different m_capacity"<<endl;
    arr->printArr();
    arr2->printArr();
    
    cout<<"---------------------------------------------------------"<<endl;
    cout<< "rony removed from array 1"<<endl;
    arr->removeElement(rony);
    arr->printArr();
    arr2->printArr();
    
    cout<<"---------------------------------------------------------"<<endl;
    cout<< "guy append after index 1"<<endl;
    arr->append(1, guy);
    arr2->append(1, guy);
    arr->printArr();
    arr2->printArr();
    
    cout<<"---------------------------------------------------------"<<endl;
    cout<< "sharon prepend before index 1"<<endl;
    arr->prepend(1, sharon);
    arr2->prepend(1, sharon);
    arr->printArr();
    arr2->printArr();
    
   /* cout<<"---------------------------------------------------------"<<endl;
    cout<< "guy removed and deleted from array 2"<<endl;
    arr2->removeAndDeleteElement(guy);
    arr->printArr();
	cout << "got here";
    arr2->printArr();
    
    cout<<"------"<<endl;
    cout<<guy->toString()<<endl;*/
    
	cout << "tom is the king" << endl;
    
}