#include "pch.h"
#include <iostream>
#include "Complex.h"
#include <math.h>

using namespace std;

void Menu()
{
	cout << "CHOOSE AN OPTION FROM BELOW:" << endl;
	cout << endl;
	cout << "_____________________________________________" << endl;
	cout << endl;
	cout << "1.The sum of two complex numbers." << endl;
	cout << "_________________________________________" << endl;
	cout << "2.The difference of two complex numbers." << endl;
	cout << "_________________________________________" << endl;
	cout << "3.The product of two complex numbers." << endl;
	cout << "_________________________________________" << endl;
	cout << "4.The dividing of two complex numbers." << endl;
	cout << "_________________________________________" << endl;
	cout << "5.Powers of a complex number." << endl;
	cout << "_________________________________________" << endl;
	cout << "6.The modulus of a complex number." << endl;
	cout << "_________________________________________" << endl;
	cout << "7.The radical of a complex number." << endl;
	cout << "_________________________________________" << endl;
	cout << "8.The conjugate of a complex number." << endl;
	cout << "_________________________________________" << endl;
	cout << "9.EXIT" << endl;
	cout << "_____________________________________________" << endl;
	cout << endl;
	cout << "Add your option: ";

}

int main()
{
	int option, power, mod;

	Complex first, second, rad;

	cout << "Add your first complex number: " << endl;
	first.Add();

	Menu();

	cin >> option;
	cout << "_____________________________________________" << endl;

	switch (option)
	{
	case 1:
		cout << "Add your second complex number: " << endl;
		second.Add();
		first = first + second;
		cout << "_____________________________________________" << endl;
		cout << "Result: ";
		first.Display();
		cout << endl << "_____________________________________________" << endl;
		break;

	case 2:
		cout << "Add your second complex number: " << endl;
		second.Add();
		first = first - second;
		cout << "_____________________________________________" << endl;
		cout << "Result: ";
		first.Display();
		cout << endl << "_____________________________________________" << endl;
		break;

	case 3:
		cout << "Add your second complex number: " << endl;
		second.Add();
		first = first * second;
		cout << "_____________________________________________" << endl;
		cout << "Result: ";
		first.Display();
		cout << endl << "_____________________________________________" << endl;
		break;

	case 4:
		cout << "Add your second complex number: " << endl;
		second.Add();
		first = first / second;
		cout << "_____________________________________________" << endl;
		cout << "Result: ";
		first.Display();
		cout << endl << "_____________________________________________" << endl;
		break;

	case 5:
		cout << "Add the power number: ";
		cin >> power;
		first = first ^ power;
		cout << "_____________________________________________" << endl;
		cout << "Result: ";
		first.Display();
		cout << endl << "_____________________________________________" << endl;
		break;

	case 6:
		mod = modul(first);
		cout << "_____________________________________________" << endl;
		cout << "The modulus of the number ";
		first.Display();
		cout << " is " << mod << endl;
		cout << endl << "_____________________________________________" << endl;
		break;

	case 7:
		rad = sqrt(first);
		cout << "_____________________________________________" << endl;
		cout << "Result: ";
		rad.Display();
		cout << endl << "_____________________________________________" << endl;
		break;

	case 8:
		first.Conjugate();
		first.Display();
		cout << endl << "_____________________________________________" << endl;
		break;
	case 9:
		return 0;
	default:
		cout << "_____________________________________________" << endl;
		cout << "The option added is not valid!";
		cout << endl << "_____________________________________________" << endl;
	}

	return 0;
}












