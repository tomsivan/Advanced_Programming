#include <string>
#include <ostream>
#include "PersonArray_t.h"
#include "Test_t.h"
using namespace std;

Test_t::Test_t()
{
	arr = new PersonArray_t();
}

Test_t:: Test_t(int initialValue)
{
	arr = new PersonArray_t(initialValue);
}

Test_t:: Test_t(int initialValue, int expand_value)
{
	arr = new PersonArray_t(initialValue, expand_value);
}

Test_t::~Test_t()
{
	delete(arr);
}

int Test_t::getNumofElem()
{
	return arr->getNumberOfElements();
}

int Test_t::getCapacity()
{
	return arr->getCapacity();
}

void Test_t::insert(Person_t* p)
{
	arr->insert(p);
}

void Test_t::getFirstElement()
{
	Person_t* pr = arr->getFirstElement();
	if (pr != NULL)
		cout << "First element is: " << (*pr).toString() << endl;
	else
		cout << "Didn't get the first element!" << endl;
}

void Test_t::getLastElement()
{
	Person_t* pr = arr->getLastElement();
	if (pr != NULL)
		cout << "Last element is: " << (*pr).toString() << endl;
	else
		cout << "Didn't get the last element!" << endl;
}

void Test_t::findElement(const Person_t* p)
{
	Person_t* pr = arr->findElement(p);
	if (pr != 0)
		cout << "Element found: " << (*pr).toString() << endl;
	else
		cout << "Didn't find element!" << endl;
}

void Test_t::removeElement(const Person_t* p)
{
	Person_t* pr = arr->removeElement(p);
	if (pr != 0)
		cout << "Element removed: " << (*pr).toString() << endl;
	else
		cout << "Didn't find element in the array!" << endl;
}

void Test_t::removeAllElements()
{
	arr->removeAllElements();
	cout << "All elements removed" << endl;
}
void  Test_t::removeAndDeleteElement(Person_t* p)
{
	arr->removeAndDeleteElement(p);
	cout << "Element removed and deleted!" << endl;
}

void  Test_t::removeAndDeleteAllElements()
{
	arr->removeAndDeleteAllElements();
	cout << "All elements Removed and deleted!" << endl;
}

void Test_t::append(int indx, Person_t* p)
{
	if(arr->append(indx, p))
		cout << "Element appended at index: " << indx << endl;
	else
		cout << "Element not appended" << endl;
}

void Test_t::prepend(int indx, Person_t* p)
{
	if (arr->prepend(indx, p))
		cout << "Element prepended at index: " << indx << endl;
	else
		cout << "Element not prepended" << endl;
}

void Test_t::printArr()
{
	arr-> printArr();
}