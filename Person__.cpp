#include <iostream>
#include "person.h"
#include <string>

using namespace std;
int main()
{	
	person EVA("EVA", female);
	person ADAM("ADAM", male);

	ADAM.Print();
	person* SERGEI = EVA.giveBirth("SERGEI", female, &ADAM);
	person* SONYA = EVA.giveBirth("SONYA", female, &ADAM);
	person* IVAN = SONYA->giveBirth("IVAN", male, &ADAM);
	IVAN->Print();
	SONYA->Print();
	person* NASTA = ADAM.giveBirth("NASTA", male, &ADAM);
	NASTA->Print();


	return 0;

}
