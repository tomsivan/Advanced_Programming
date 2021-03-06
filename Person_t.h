#pragma once
//
//  Person_t.h
//  Adv_Ex1
//
//  Created by tom sivan on 3/26/15.
//  Copyright (c) 2015 tomsivan. All rights reserved.
//



#include <stdio.h>
#include <string>
using namespace std;

#ifndef __Adv_Ex1__Person_t__
#define __Adv_Ex1__Person_t__

class Person_t {
public:
	// constructrs
	Person_t();                              // default constructor
	Person_t(const string& name, int age);   // constructor
	Person_t(const Person_t& p);            // copy constructor

	// destructor
	~Person_t();

	//operators
	const Person_t& operator= (const Person_t& p); //TODO: check
	bool operator== (const Person_t& p) const;

	// getters
	string  getName() const { return m_name; };
	int     getAge() const { return m_age; };
	size_t  getId() const { return m_id; };

	//functions
	string toString();

private:
	const size_t    m_id;             // Unique for each Person_t object
	string          m_name;          // name
	int             m_age;          // age
	static size_t   m_globID;       // used to calculate m_id

};

#endif /* defined(__Adv_Ex1__Person_t__) */