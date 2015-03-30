#include <string>
#include <ostream>
#include "PersonArray_t.h"
#include "Person_t.h"

class Test_t
{
public:
	Test_t();
	Test_t(int initialValue);
	Test_t(int initialValue, int expand_value);
	~Test_t();

	PersonArray_t* arr;

	int getNumofElem();
	int getCapacity();
	void insert(Person_t* p);
	void getFirstElement();
	void getLastElement();
	void findElement(const Person_t* p);
	void removeElement(const Person_t* p);
	void removeAllElements();
	void  removeAndDeleteElement(Person_t* p);
	void  removeAndDeleteAllElements();
	void append(int indx, Person_t* p);
	void prepend(int indx, Person_t* p);
	void printArr();
};

