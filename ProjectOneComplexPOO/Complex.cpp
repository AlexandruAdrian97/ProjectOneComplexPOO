#include "pch.h"
#include "Complex.h"
#include <iostream>
#include <string>

using namespace std;


Complex::Complex()
{
	Real = 0;
	Imaginar = 0;
}

Complex::Complex(double Re, double Im)
{
	Real = Re;
	Imaginar = Im;
}

Complex::Complex(Complex &x)
{
	Real = x.getReal();
	Imaginar = x.getImaginar();
}



// Nu functioneaza si nu inteleg motivul
/*
	Complex::Complex(string s) 
	{


	int i = 0;

	if (s[0] == 'i' || s[1] == 'i')

		Real = 0;

	else

	{

		for (i = 1; i < s.size(); i++)

			if (s[i] == '+' || s[i] == '-')

				break;

		Real = stod(s.substr(0, i));

	}

	if (i == s.size())

		Imaginar = 0;

	else if (s[i] == '-')

		Imaginar = -1;

	else Imaginar = 1;



	if (s[i] != 'i' && i + 3 < s.size())

		Imaginar *= stod(s.substr(i + 3, s.size()));

	else if (i + 3 < s.size())

		Imaginar = stod(s.substr(i + 2, s.size()));



}

	*/





//Supraîncărcarea operatorilor compuși de atribuire:

Complex& Complex::operator = (const Complex &x)
{
	if (this != &x) {
		this->Real = x.getReal();
		this->Imaginar = x.getImaginar();
	}
	return *this;
}

Complex& Complex::operator += (const Complex& x)
{
	if (this != &x) {

		Real += x.getReal();
		Imaginar += x.getImaginar();
	}
	return *this;
}

Complex& Complex::operator += (const double x)
{
	this->Real = Real + x;
	return *this;
}

Complex& Complex::operator -= (const Complex& x)
{
	if (this != &x) {
		Real -= x.getReal();
		Imaginar -= x.getImaginar();
	}
	return *this;
}

Complex& Complex::operator -= (const double x)
{
	this->Real = Real - x;
	return *this;
}

Complex& Complex::operator *= (const Complex& x)
{
	if (this != &x) {
		double s = Real;
		Real = Real * x.getReal() - Imaginar * x.getImaginar();
		Imaginar = s * x.getImaginar() + Imaginar * x.getReal();
	}
	return *this;

}

Complex& Complex::operator *= (const double x)
{
	Real = Real * x;
	Imaginar = Imaginar * x;
	return *this;
}

Complex& Complex::operator /= (Complex& x)
{
	if (this != &x) {

		double s1 = Real;
		double s2 = x.getReal() * x.getReal() + x.getImaginar() * x.getImaginar();

		Real = (Real * x.getReal() + Imaginar * x.getImaginar()) / s2;
		Imaginar = (Imaginar * x.getReal() - s1 * x.getImaginar()) / s2;
	};

	return *this;
}

Complex& Complex::operator /= (const double x)
{
	if (x == 0)
	{
		cout << "Nu se poate efectua impartirea la 0 ";
	}
	else
	{
		Real = Real / x;
		Imaginar = Imaginar / x;

		return *this;
	}

}

//Nu functioneaza..
/*
 string Complex::ToString() {

	string s = "";

	if (this->Real == 0)
	{
	if (this->Imaginar == 0)
		s += "0";
			else
	if (this->Imaginar == 1)
		s += "i";
			else
	if (this->Imaginar == -1)
		s += "-i";
			else {
	if (this->Imaginar > 0)
		s += "i*" + to_string(this->Imaginar);
			else
		s += "-i*" + to_string(-(this->Imaginar));

	}
	}
	else
	{
	if (this->Imaginar == 0)
		s += to_string(this->Real);
			else
	if (this->Imaginar == 1)
		s += to_string(this->Real) + "+i";
			else
	if (this->Imaginar == -1)
		s += to_string(this->Real) + "-i";
			else {
	if (this->Imaginar > 0)
		s += to_string(this->Real) + "+i*" + to_string(this->Imaginar);
			else
		s += to_string(this->Real) + "-i*" + to_string(-(this->Imaginar));

	}
	}

	return s;


}

*/


//Supraîncărcarea operatorilor aritmetici unari:

Complex operator + (const Complex &x)
{
	Complex z;
	z.Real = x.getReal();
	z.Imaginar = x.getImaginar();
	return z;
}

Complex operator - (const Complex x)
{
	Complex z;
	z.Real = x.getReal() *(-1);
	z.Imaginar = x.getImaginar()*(-1);
	return z;
}



//Supraîncărcarea operatorilor aritmetici binari:

Complex operator + (const Complex& x, const Complex& y)
{
	Complex z;
	z.Real = x.getReal() + y.getReal();
	z.Imaginar = x.getImaginar() + y.getImaginar();
	return z;
}

Complex operator + (const Complex& x, const double y)
{
	Complex z;
	z.Real = x.getReal() + y;
	z.Imaginar = x.getImaginar();
	return z;
}

Complex operator + (const double x, const Complex& y)
{
	Complex z;
	z.Real = x + y.getReal();
	z.Imaginar = y.getImaginar();
	return z;
}

Complex operator - (const Complex& x, const Complex& y)
{
	Complex z;
	z.Real = x.getReal() - y.getReal();
	z.Imaginar = x.getImaginar() - y.getImaginar();
	return z;
}

Complex operator - (const Complex& x, const double y)
{
	Complex z;
	z.Real = x.getReal() - y;
	z.Imaginar = x.getImaginar();
	return z;
}

Complex operator - (const double x, const Complex& y)
{
	Complex z;
	z.Real = x - y.getReal();
	z.Imaginar = y.getImaginar();
	return z;
}

Complex operator * (const Complex& x, const Complex& y)
{
	Complex z;
	double a1_a2 = y.getReal() * x.getReal();
	double b1_b2 = y.getImaginar() * x.getImaginar();
	double a1_b2 = y.getReal() * x.getImaginar();
	double b1_a2 = y.getImaginar() * x.getReal();
	z.Real = a1_a2 - b1_b2;
	z.Imaginar = b1_a2 + a1_b2;
	return z;
}

Complex operator * (const Complex& x, const double y)
{
	Complex z;
	z.Real = x.getReal() * y;
	z.Imaginar = x.getImaginar() * y;
	return z;
}

Complex operator * (const double x, const Complex& y)
{
	Complex z;
	z.Real = y.getReal() * x;
	z.Imaginar = y.getImaginar() * x;
	return z;
}

Complex operator / (const Complex& x, const Complex& y)
{
	Complex z;
	z = y;
	if (y.getReal() == 0 && y.getImaginar() == 0)
	{
		cout << "Error: Can't be done !! " << endl;
		return z;
	}
	else
	{
		double re = (x.getReal() * y.getReal() + x.getImaginar() * y.getImaginar()) / (y.getReal() * y.getReal() + y.getImaginar() * y.getImaginar());
		double im = (x.getImaginar() * y.getReal() - x.getReal() * y.getImaginar()) / (y.getReal() * y.getReal() + y.getImaginar() * y.getImaginar());
		z.Real = re;
		z.Imaginar = im;
		return z;
	}
}

Complex operator / (const Complex& x, const double y)
{
	Complex z;
	z = x;
	if (y == 0)
	{
		cout << "Error: Can't be done !! " << endl;
		return z;
	}
	else
	{
		z.Real = x.getReal() / y;
		z.Imaginar = x.getImaginar() / y;
		return z;
	}
}

Complex operator / (const double x, Complex &y)
{
	Complex z;
	z = y;
	if (y.getImaginar() == 0 && y.getReal() == 0)
	{
		cout << "Error: Can't be done !! " << endl;
		return y;
	}
	else
	{
		z.Real = (x*y.getReal()) / (y.getReal() * y.getReal() + y.getImaginar() * y.getImaginar());
		z.Imaginar = (-x * y.getImaginar()) / (y.getReal() * y.getReal() + y.getImaginar() * y.getImaginar());
		return z;
	}
}

Complex operator ^ (Complex& x, int n)
{
	int i;
	Complex aux;
	aux = x;
	if (n == 0)
	{
		aux.Real = 1;
		aux.Imaginar = 0;
	}
	else
		for (i = 1; i < n; i++)
			aux = x * aux;
	return aux;
}



//Supraîncărcarea operatorilor relationali:

bool operator == (const Complex& x, const Complex& y)
{
	if (x.getReal() == y.getReal() && x.getImaginar() == y.getImaginar())
		return true;
	return false;
}

bool operator == (const Complex& x, const double y)
{
	if (x.getReal() == y && x.getImaginar() == 0)
		return true;
	return false;
}

bool operator == (const double x, const Complex& y)
{
	if (y.getReal() == x && y.getImaginar() == 0)
		return true;
	return false;
}

bool operator != (const Complex& x, const Complex& y)
{
	if (x.getReal() != y.getReal() || x.getImaginar() != y.getImaginar())
		return true;
	return false;
}

bool operator != (const Complex& x, const double y)
{
	if (x.getReal() != y || x.getImaginar() != 0)
		return true;
	return false;
}

bool operator != (const double x, const Complex& y)
{
	if (x != y.getReal() || 0 != y.getImaginar())
		return true;
	return false;
}



void Complex::Add()
{
	cout << "Real: ";
	cin >> Real;
	cout << "Imaginar: ";
	cin >> Imaginar;
	cout << endl;
}


void Complex::Display()
{
	if (Real == 0)
	{
		if (Imaginar == 0)
			cout << "0";
		else
			if (Imaginar == 1)
				cout << "i";
			else
				if (Imaginar == -1)
					cout << "-i";
				else {
					if (Imaginar > 0)
						cout << Imaginar << "*i";
					else
						cout << Imaginar << "*i";
				}
	}
	else
		if (Real > 0)
		{
			if (Imaginar == 0)
				cout << Real;
			else
				if (Imaginar == 1)
					cout << Real << "+i";
				else
					if (Imaginar == -1)
						cout << Real << "-i";
					else {
						if (Imaginar > 0)
							cout << Real << "+" << Imaginar << "*i";
						else
							cout << Real << Imaginar << "*i";
					}
		}
		else
			if (Real < 0)
			{
				if (Imaginar == 0)
					cout << Real;
				else
					if (Imaginar == 1)
						cout << Real << "+i";
					else
						if (Imaginar == -1)
							cout << Real << "-i";
						else {
							if (Imaginar > 0)
								cout << Real << "+" << Imaginar << "*i";
							else
								cout << Real << Imaginar << "*i";
						}
			}
}


void Complex::Conjugate()
{
	Real = Real;
	Imaginar = -1 * getImaginar();


}




///Supraincarcarea operatorilor de citire si afisare:  nu merg deoarece nu mi functioneaza constructorul cu parametru string si functia toString)
/*
istream& operator>>(istream& is, Complex& x) 
{
	string c;
	is >> c;
	Complex ob(c);
	x = ob;

	return is;
}


ostream& operator<<(ostream& os, const Complex& x){
	os << x.ToString();

  return os;
}


*/




