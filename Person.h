#pragma once
#include <iostream>
#include <string>
using namespace std;
enum gen { male, female };
class person {
private:
	static int newID;
	const int ID;
	string name;
	const gen gender;
	person* mother;
	person* father;
public:
	person& operator =(person&);
	int GetID()const;
	void Clone(person&);
	person(person&);
	person(string aName, gen g, person* m = nullptr, person* f = nullptr);
	void SetName(string aname);
	string GetName()const;
	void setMother(person* m);
	void setFather(person* f);
	string getGender() const;
	string getMother()const;
	string getFather()const;
	person* giveBirth(string name, gen, person* = nullptr);
	void Print() const;


};


