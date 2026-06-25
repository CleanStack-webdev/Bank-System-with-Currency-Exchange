#pragma once
#include <iostream>
#include <string>
using namespace std;

class clsPerson
{

private:

	string _FirstName;
	string _LastName;
	string _Email;
	string _Phone;

public:

	clsPerson(string FirstName, string LastName, string Email, string Phone)
	{
		_FirstName = FirstName;
		_LastName = LastName;
		_Email = Email;
		_Phone = Phone;
	}

	//Property Get
	string GetFirstName()
	{
		return _FirstName;
	}

	//Property Set
	void SetFirstName(string FirstName)
	{
		_FirstName = FirstName;
	}
	__declspec(property(get = GetFirstName, put = SetFirstName)) string FirstName;

	//Property Get
	string GetLastName()
	{
		return _LastName;
	}

	//Property Set
	void SetLastName(string LastName)
	{
		_LastName = LastName;
	}
	__declspec(property(get = GetLastName, put = SetLastName)) string LastName;

	//Property Get
	string GetEmail()
	{
		return _Email;
	}

	//Property Set
	void SetEmail(string Email)
	{
		_Email = Email;
	}

	__declspec(property(get = GetEmail, put = SetEmail)) string Email;

	//Property Get
	string GetPhone()
	{
		return _Phone;
	}

	//Property Set
	void SetPhone(string Phone)
	{
		_Phone = Phone;
	}
	__declspec(property(get = GetPhone, put = SetPhone)) string Phone;

	string FullName()
	{
		return _FirstName + " " + _LastName;
	}

};