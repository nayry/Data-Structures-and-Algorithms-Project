#ifndef PERSON_H
#define PERSON_H
#include<iostream>
#include<string>

using namespace std;

class person {
public:
	string Title;
	string Surname;
	string Givenname;
	string Gender;
	string Birthday;
	string StreetAddress;
	string City;
	string StateFull;
	string ZipCode;
	string CountryFull;
	string TelephoneCountryCode;
	string TelephoneNumber;
	string EmailAddress;
	string Occupation;
	string Company;
	void dispaly();
};
#endif // !PERSON_H


