#include "person.h"
#include <string>
#pragma warning (disable:4996)
using namespace std;
int person::newID = 0;

person::person(string aName, gen g, person* m, person* f) :ID(++newID), gender(g)
{
	try
	{
		if (ID > 2 && m == nullptr)
		{
			throw exception("you can not create more then one ADAM and EVA");
		}
	}
	catch (exception& ex)
	{
		cout << "ERROR-" << ex.what() << endl;
	}
	try
	{
		if (aName == "")
		{
			throw exception("person must has got name");
		}
		else
		{
			SetName(aName);
		}
	}
	catch (const exception& ex)
	{
		cerr << "ERROR:" << ex.what();
	}
	try
	{
		if (gender != male && gender != female)
		{
			throw exception("person has not got gender");
		}
	}
	catch (const exception& ex)
	{
		cerr << "Error:" << ex.what();
	}
	if (f != nullptr)
	{
		setFather(f);
	}
	if (m != nullptr)
	{
		setMother(m);
	}
}
void person::Clone(person& p)
{
	name = p.GetName();
}
person::person(person& p) : ID(++newID), gender(p.gender)
{
	Clone(p);
}
person& person::operator =(person& p) {
	if (this != &p) {
		Clone(p);
	}
	return *this;
}
int person::GetID() const
{
	return ID;
}
void person::SetName(string aname)
{
	name = aname;
	if (name == "") {
		throw std::runtime_error("Invalid parametr (NULL)");
	}
	if (aname[0] == '\0') {
		throw std::runtime_error("Invalid name length");
	}
}
string person::GetName() const
{
	return name;
}
void person::setMother(person* m)
{
	mother = m;
}
void person::setFather(person* f)
{
	father = f;
}

string person::getGender() const
{
	return this->gender == male ? "male" : "female";
}
string person::getMother() const
{
	return mother->GetName();
}
string person::getFather() const
{
	return father->GetName();
}
person* person::giveBirth(string name, gen gender, person* father)
{
	try
	{
		if (this->gender != female)
		{
			throw exception("mother must have female gender");
		}
	}
	catch (const exception& ex)
	{
		cout << "ERROR:" << ex.what() << endl;
	}

	try
	{
		if (gender != male && gender != female)
		{
			throw "person must have gender";
		}
	}
	catch (const exception& ex)
	{
		cout << "ERROR:" << ex.what() << endl;
	}
	string childname;
	try
	{
		if (name == "")
		{
			throw "child must have a name";
		}
		else
		{
			childname = name;
		}
	}
	catch (const std::exception& ex)
	{
		cout << "ERROR:" << ex.what() << endl;
	}
	auto child = new person(childname, gender, this, father);
	return child;
}
void person::Print() const {
	cout << "Name: " << GetName() << endl;
	cout << "ID: " << GetID() << endl;
	cout << "Gender: " << getGender() << endl;
	if (mother != nullptr)
	{
		cout << "Mother Name: " << getMother() << endl;
	}
	else
	{
		cout << "This person has no mother" << endl;
	}
	if (father != nullptr)
	{
		cout << "Father Name: " << getFather() << endl;
	}
	else
	{
		cout << "This person has no father" << endl;
	}
	cout << endl;
}