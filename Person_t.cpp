//
//  Person_t.cpp
//  Adv_Ex1
//
//  Created by tom sivan on 3/26/15.
//  Copyright (c) 2015 tomsivan. All rights reserved.
//

#include "Person_t.h"
#include <string>
using namespace std;

size_t Person_t::m_globID = 1;

//constructors

Person_t::Person_t() :
m_id(m_globID++)
{
}

Person_t::Person_t(const string& name, int age) : // constructor
m_age(age), m_name(name), m_id(m_globID++)
{
}

Person_t::Person_t(const Person_t& p) : // copy constructor
m_id(m_globID++), m_age(p.getAge()), m_name(p.getName())
{
}

//destructors
Person_t:: ~Person_t() // destructor
{
    
}

//operators
Person_t& Person_t::operator=(const Person_t& p)
{
	if (this != &p)
	{
		m_name = p.getName();
		m_age = p.getAge();
	}

	return *this;
}

bool Person_t::operator==(const Person_t& p)
{
	return (m_age == p.getAge()) && (!strcmp(m_name.c_str(), p.m_name.c_str()));
}

//functions
string Person_t::toString()
{
	return m_name + ", " + to_string(m_age);
}