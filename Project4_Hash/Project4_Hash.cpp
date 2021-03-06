// Project4_Hash.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "HashTable.h"
#include "Student.h"
#include <iostream>

template class HashTable<Student>;

using namespace std;


int main()
{
	int collisions = 0;
	HashTable<Student> a1 = HashTable<Student>();
	Student s;
	s.firstName = "logan";
	s.lastName = "Krause";
	s.UID = 8247;
	Student s1;
	s1.firstName = "Hannah";
	s1.lastName = "Myers";
	s1.UID = 6247;
	a1.insert(8427, s, collisions);
	HashTable<Student> ht = HashTable<Student>();
	cout << ht.insert(s.UID, s, collisions) << endl;
	cout << ht.insert(s1.UID, s, collisions) << endl;
	cout << ht.find(s.UID, s) << endl;
	cout << ht.find(265, s) << endl;
	cout << ht.alpha() << endl;
	cout << ht.remove(s.UID) << endl;
	cout << ht.alpha() << endl;
	system("pause");
    return 0;
}
