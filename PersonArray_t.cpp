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

PersonArray_t::PersonArray_t() :  // default constructor
m_expandValue(4), m_numOfElements(0)
{
	m_personArr = new Person_t*[m_expandValue];
	m_capacity = m_expandValue;
}

PersonArray_t::PersonArray_t(const int initialValue) : // constructor from int
m_expandValue(16), m_numOfElements(0)
{
	m_personArr = new Person_t*[initialValue];
	m_capacity = initialValue;
}

PersonArray_t::PersonArray_t(const PersonArray_t& arr) : // copy constructor
m_expandValue(16)
{
	m_capacity = arr.getCapacity();
	m_numOfElements = arr.getNumberOfElements();
	m_personArr = new Person_t*[m_capacity];
	for (int i = 0; i < m_numOfElements; i++)
	{
		m_personArr[i] = arr.m_personArr[i];
	}
}

PersonArray_t:: ~PersonArray_t() // destructor
{
	for (int i = 0; i < m_numOfElements; i++)
	{
		delete m_personArr[i];
	}

	delete[] m_personArr; // TODO - check
}

PersonArray_t& PersonArray_t:: operator= (const PersonArray_t& arr)
{
	if (this != &arr){
		m_numOfElements = arr.m_numOfElements;
		m_capacity = arr.m_capacity;
		// to update
		m_personArr = arr.m_personArr;
	}

	return *this;
}

void PersonArray_t::insert(Person_t* p)
{
	if (!isEmpty())
	{
		prepend(0, p);
	}
	else
	{
		prepend(m_numOfElements, p);
	}
}

Person_t* PersonArray_t::getFirstElement()
{
	if (!isEmpty())
	{
		return m_personArr[0];
	}		
	return NULL;
}

Person_t* PersonArray_t::getLastElement()
{
	if (!isEmpty())
	{
		return m_personArr[m_numOfElements - 1];
	}	
	return NULL;
}

Person_t* PersonArray_t::findElement(const Person_t* p)
{
	int p_indx = findElementIndx(p);
	if (p_indx != -1)
	{
		return m_personArr[p_indx];
	}
	return 0;
}

Person_t* PersonArray_t::removeElement(const Person_t* p)
{
	int p_indx = findElementIndx(p); // we need the index in order to fix the array after remove
	if (p_indx == -1) // no such person
	{
		return 0;
	}
	Person_t* pr = m_personArr[p_indx];

	for (int i = p_indx; i < m_numOfElements; i++) // shift left from that indx forward
	{
		m_personArr[i] = m_personArr[i + 1];
	}
	m_personArr[m_numOfElements-1] = NULL; 
	m_numOfElements--;

	// TODO: deallocate??

	return pr;
}

void PersonArray_t::removeAllElements()
{
	for (int i = 0; i < m_numOfElements; i++)
	{
		m_personArr[i] = NULL;
	}
	m_numOfElements = 0;

	// TODO: deallocate??
}

void  PersonArray_t::removeAndDeleteElement(Person_t* p)
{
	for (int k = 0; k < m_numOfElements; k++)
	{
		int p_indx = findElementIndx(p); // we need the index in order to fix the array after remove
		if (p_indx == -1) // no such person
		{
			return;
		}
		else
		{
			delete m_personArr[p_indx];

			for (int i = p_indx; i < m_numOfElements; i++) // shift left from that indx forward
			{
				m_personArr[i] = m_personArr[i + 1];
			}
			m_personArr[m_numOfElements - 1] = NULL;
			m_numOfElements--;
		}
	}

	// TODO: deallocate??
}

void  PersonArray_t::removeAndDeleteAllElements()
{
	while (m_numOfElements > 0)
	{
		removeAndDeleteElement(m_personArr[0]);
	}

	if (m_numOfElements == 0)
		cout << "removed and deleted all Elements" << endl;
	else
		cout << "There's a problem!!" << endl;

	// TODO: deallocate??
}

int PersonArray_t::append(int indx, Person_t* p)
{
	return prepend(indx + 1, p);
}

int PersonArray_t::prepend(int indx, Person_t* p)
{
	if ((indx < 0) || (indx > m_numOfElements) || (p == NULL))
		return 0;

	moveRight(indx + 1);
	m_personArr[indx] = p;
	m_numOfElements++;
	return 1;
}

// added functions
int PersonArray_t::findElementIndx(const Person_t* p)
{
	bool found = false;
	int i = 0;
	while ((!found) && (i < m_numOfElements))
	{
		if (*m_personArr[i] == *p)
			found = true;
		else
			i++;
	}

	if (i < m_numOfElements)
		return i;
	return -1;
}

void PersonArray_t::addCapacity()
{
	//allocate new memory
	Person_t** newArr = new Person_t*[m_capacity + m_expandValue];
	reAllocatePeople(newArr);
	m_capacity += m_expandValue;
}

void PersonArray_t::reAllocatePeople(Person_t** newArr)
{
	//copy the elements to the new array
	for (int i = 0; i < m_numOfElements; i++)
	{
		newArr[i] = m_personArr[i];
	}
	//delete old array and update the pointer to the new one
	delete[] m_personArr;
	m_personArr = newArr;
}

void PersonArray_t::moveRight(int indx)
{
	if (isFull())
	{
		addCapacity();
	}	
	for (int i = m_numOfElements; i >= indx; i--)
	{
		m_personArr[i] = m_personArr[i - 1];
	}
}

/*void PersonArray_t::deAllocate()
{
	int newSize = ((int)(m_numOfElements / m_expandValue) + 1) * m_expandValue;
	Person_t** newArray = new Person_t*[newSize];
	reAllocatePeople(newArray);
	m_capacity = newSize;
}*/

void PersonArray_t::printArr()
{
	cout << "Array capccity: " << m_capacity << endl;
	cout << "Number of Elements: " << m_numOfElements << endl;
	cout << "Elements: " << endl;
	//cout << "       Name" << "      Age" << endl;
	for (int i = 0; i < m_numOfElements; i++)
	{
		try
		{
			cout << "array[" << i << "]: " << m_personArr[i]->toString() << endl;
		}
		catch (exception e)
		{
			cout << "the element was removed somewhere in the code!!" << endl;
		}
	}
}