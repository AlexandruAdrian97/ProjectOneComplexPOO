﻿#include "pch.h"
#include "Complex.h"
#include <iostream>


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
		cout << "Eroare: Nu se poate efectua impartirea la 0 ";
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
		cout << "Eroare: Nu se poate efectua impartirea la 0 ";
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
		cout << "Eroare: Nu se poate efectua impartirea la 0 ";
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





///Supraincarcarea operatorilor de citire si afisare: (mai am de lucru, inca nu merg)

/*
ostream& operator<<(ostream& os, const Complex& x){
  os << "("<< x.getReal() <<"," << x.getImaginar() << ")" << endl;
  return os;
}
istream& operator>>(istream& is, Complex& x){
  is >> x.getReal() >> x.getImaginar();
  return is;
}
*/






///Tostring function:  (mai am de lucru, inca nu merg)

/*
ostream& operator<< (Complex& x) {
		return cout << x.toString();
	}

*/


