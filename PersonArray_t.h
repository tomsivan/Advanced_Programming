#pragma once
//
//  PersonArray_t.h
//  Adv_Ex1
//
//  Created by tom sivan on 3/26/15.
//  Copyright (c) 2015 tomsivan. All rights reserved.
//

#include <stdio.h>
#include "Person_t.h"
#include <string>
#include <iostream>
using namespace std;

#ifndef __Adv_Ex1__PersonArray_t__
#define __Adv_Ex1__PersonArray_t__

class PersonArray_t {
public:
	// Constructors
	PersonArray_t(); // default constructor
	PersonArray_t(const int initialSize); // constructor from int
	PersonArray_t(const int initialSize, const int expand_value); // constructor from int
	// Destructor
	~PersonArray_t(); // destructor
	
	// Getters
	int getNumberOfElements() const { return m_numOfElements; }
	int getCapacity() const { return m_capacity; }

	// desired functions
	Person_t* getFirstElement();
	Person_t* getLastElement();
	void insert(Person_t* p);
	Person_t* findElement(const Person_t* p);
	Person_t* removeElement(const Person_t* p);
	void removeAllElements();
	void  removeAndDeleteElement(Person_t* p);
	void  removeAndDeleteAllElements();
	int append(int indx, Person_t* p);
	int prepend(int indx, Person_t* p);

	// added functions
	void printArr();

private:
	// type members
	const int	m_expandValue;
	int         m_numOfElements;
	int			m_capacity;
	Person_t**  m_personArr;

	// So won't be able to copy them
	PersonArray_t(const PersonArray_t& p);				// copy constructor
	PersonArray_t& operator= (const PersonArray_t& p);	// Asignment operator

	// added functions
	bool isFull() { return m_numOfElements == m_capacity; }
	bool isEmpty() { return m_numOfElements == 0; }
	void addCapacity();
	void reAllocatePeople(Person_t** newArray);
	void deAllocatePeople(Person_t** newArray);
	int findElementIndx(const Person_t* p);
	void moveRight(int indx);
};

#endif /* defined(__Adv_Ex1__PersonArray_t__) */