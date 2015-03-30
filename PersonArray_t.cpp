//
//  PersonArray_t.cpp
//  Adv_Ex1
//
//  Created by tom sivan on 3/26/15.
//  Copyright (c) 2015 tomsivan. All rights reserved.
//

#include "PersonArray_t.h"
#include <stdio.h>
#include <stdlib.h>
#include <string>
using namespace std;

PersonArray_t::PersonArray_t() // default constructor
{
	P_arr = new Person_t*[defualtExpandValue];
	numOfElements = 0;
	expandValue = defualtExpandValue;
	capacity = expandValue;
}

PersonArray_t::PersonArray_t(const int initialValue) // constructor from int
{
	P_arr = new Person_t*[initialValue];
	numOfElements = 0;
	expandValue = defualtExpandValue;
	capacity = initialValue;
}

PersonArray_t::PersonArray_t(const int initialValue, const int expand_value) // constructor from int,int
{
	P_arr = new Person_t*[initialValue];
	numOfElements = 0;
	expandValue = expand_value;
	capacity = initialValue;
}

PersonArray_t::PersonArray_t(const PersonArray_t& arr) // TODO: copy constructor
{

}

PersonArray_t:: ~PersonArray_t() // destructor
{
	for (int i = 0; i < numOfElements; i++)
	{
		delete P_arr[i];
	}
}

PersonArray_t& PersonArray_t:: operator= (const PersonArray_t& arr)
{
	if (this == &arr){
		return *this;
	}
	numOfElements = arr.numOfElements;
	capacity = arr.capacity;
	P_arr = arr.P_arr;

	return *this;
}

int PersonArray_t::getNumberOfElements()
{ 
	return numOfElements; 
}

int PersonArray_t::getCapacity()
{ 
	return capacity; 
}

void PersonArray_t::insert(Person_t* p)
{
	if (is_Full())
	{
		addCapacity();
	}			
	P_arr[numOfElements] = p;
	numOfElements++;
}

Person_t* PersonArray_t::getFirstElement()
{
	if (!is_Empty())
		return P_arr[0];
	return NULL;
}

Person_t* PersonArray_t::getLastElement()
{
	if (!is_Empty())
		return P_arr[numOfElements-1];
	return NULL;
}

Person_t* PersonArray_t::findElement(const Person_t* p)
{
	int p_indx = findElementIndx(p);
	if (p_indx != -1)
		return P_arr[p_indx];
	return 0;
}

Person_t* PersonArray_t::removeElement(const Person_t* p)
{
	int p_indx = findElementIndx(p); // we need the index in order to fix the array after remove
	if (p_indx == -1) // no such person
	{
		return 0;
	}
	Person_t* pr = P_arr[p_indx];

	for (int i = p_indx; i < numOfElements; i++) // shift left from that indx forward
	{
		P_arr[i] = P_arr[i + 1];
	}
	P_arr[numOfElements-1] = NULL; 
	numOfElements--;

	// TODO: deallocate??

	return pr;
}

void PersonArray_t::removeAllElements()
{
	for (int i = 0; i < numOfElements; i++)
	{
		P_arr[i] = NULL;
	}
	numOfElements = 0;

	// TODO: deallocate??
}

void  PersonArray_t::removeAndDeleteElement(Person_t* p)
{
	removeElement(p);
	delete(p);

	// TODO: deallocate??
}

void  PersonArray_t::removeAndDeleteAllElements()
{
	while (numOfElements > 0)
	{
		removeAndDeleteElement(P_arr[0]);
	}

	if (numOfElements == 0)
		cout << "removed and deleted all Elements" << endl;
	else
		cout << "There's a problem!!" << endl;

	// TODO: deallocate??
}

int PersonArray_t::append(int indx, Person_t* p)
{
	if ((indx < 0) || (indx > numOfElements - 1) || (p == NULL))
		return 0;

	moveRight(indx + 2);
	P_arr[indx + 1] = p;
	numOfElements++;
	return 1;
}

int PersonArray_t::prepend(int indx, Person_t* p)
{
	if ((indx < 0) || (indx > numOfElements) || (p == NULL))
		return 0;

	moveRight(indx + 1);
	P_arr[indx] = p;
	numOfElements++;
	return 1;
}

// added functions
int PersonArray_t::findElementIndx(const Person_t* p)
{
	bool found = false;
	int i = 0;
	while ((!found) && (i < numOfElements))
	{
		if (*P_arr[i] == *p)
			found = true;
		else
			i++;
	}

	if (i < numOfElements)
		return i;
	return -1;
}

bool PersonArray_t::is_Full()
{
	return capacity == numOfElements;
}

bool PersonArray_t::is_Empty()
{
	return numOfElements == 0;
}

void PersonArray_t::addCapacity()
{
	//allocate new memory
	Person_t** newArr = new Person_t*[capacity + expandValue];
	reAllocatePeople(newArr);
	capacity += expandValue;
}

void PersonArray_t::reAllocatePeople(Person_t** newArr)
{
	//copy the elements to the new array
	for (int i = 0; i < numOfElements; i++)
	{
		newArr[i] = P_arr[i];
	}
	//delete old array and update the pointer to the new one
	delete[] P_arr;
	P_arr = newArr;
}

void PersonArray_t::moveRight(int indx)
{
	if (is_Full())
		addCapacity();
	for (int i = numOfElements; i >= indx; i--)
	{
		P_arr[i] = P_arr[i - 1];
	}
}

/*void PersonArray_t::deAllocate()
{
	int newSize = ((int)(numOfElements / expandValue) + 1) * expandValue;
	Person_t** newArray = new Person_t*[newSize];
	reAllocatePeople(newArray);
	capacity = newSize;
}*/

void PersonArray_t::printArr()
{
	cout << "Array capccity: " << capacity << endl;
	cout << "Number of Elements: " << numOfElements << endl;
	cout << "Elements: " << endl;
	//cout << "       Name" << "      Age" << endl;
	for (int i = 0; i < numOfElements; i++)
	{
		cout << "array[" << i << "]: " << P_arr[i]->toString() << endl;
	}
}