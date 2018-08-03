#pragma once
#include <string>
using namespace std;
class Student
{
public:
	string firstName;
	string lastName;
	int UID;
	

	Student(){}

	Student(string fn, string ln, int _UID)
	{
		firstName = fn;
		lastName = ln;
		UID = _UID;
	}

	//friend bool operator==(const Student& lhs, const Student& rhs)
	//{
	//	return (lhs.firstName == rhs.firstName) &&
	//		(lhs.lastName == rhs.lastName);
	//}

	friend ostream& operator<<(ostream& os, const Student& s)
	{
		os << "------------------------" << endl;
		os << "Last Name: " << s.lastName << endl;
		os << "First Name: " << s.firstName << endl;
		os << "UID: " << s.UID << endl;
		os << "------------------------" << endl;

		return os;
	}
};

