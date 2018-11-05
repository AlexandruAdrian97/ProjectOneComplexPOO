
#ifndef COMPLEX_H
#define COMPLEX_H
#include <math.h>
#include <iostream>
#include <string>

class Complex
{
private:

	double Real, Imaginar;

public:

	Complex();
	Complex(double, double);
	Complex(Complex&);
	
	//Complex(string); // ??????

	void setReal(double Re) { Real = Re; }
	double getReal()const { return Real; }

	void setImaginar(double Im) { Imaginar = Im; }
	double getImaginar()const { return Imaginar; }

	void Add();
	void Display();
	void Conjugate();

	//string ToString(); //??????? 

	//Supraîncărcarea operatorilor compuși de atribuire

	Complex& operator = (const Complex& x);

	Complex& operator += (const Complex& x);
	Complex& operator += (const double y);

	Complex& operator -= (const Complex &y);
	Complex& operator -= (const double y);

	Complex& operator *= (const Complex &y);
	Complex& operator *= (const double y);

	Complex& operator /= (Complex &y);
	Complex& operator /= (const double y);



	//Supraîncărcarea operatorilor aritmetici unari:

	friend Complex operator + (const Complex& x);
	friend Complex operator - (const Complex x);



	//Supraîncărcarea operatorilor aritmetici binari:

	friend Complex operator + (const Complex& x, const Complex& y);
	friend Complex operator + (const Complex& x, const double y);
	friend Complex operator + (const double x, const Complex&y);

	friend Complex operator - (const Complex& x, const Complex& y);
	friend Complex operator - (const Complex& x, const double y);
	friend Complex operator - (const double x, const Complex& y);

	friend Complex operator * (const Complex& x, const Complex& y);
	friend Complex operator * (const Complex& x, const double y);
	friend Complex operator * (const double x, const Complex& y);

	friend Complex operator / (const Complex& x, const Complex&y);
	friend Complex operator / (const Complex& x, const double y);
	friend Complex operator / (const double x, Complex& y);

	friend Complex operator ^ (Complex& x, int n);



	//Supraîncărcarea operatorilor relationali:

	friend bool operator == (const Complex& x, const Complex &y);
	friend bool operator == (const Complex& x, const double y);
	friend bool operator == (const double x, const Complex& y);

	friend bool operator != (const Complex& x, const Complex &y);
	friend bool operator != (const Complex& x, const double y);
	friend bool operator != (const double x, const Complex& y);



	friend double modul(Complex& x)
	{
		double Re = x.getReal() * x.getReal();
		double Im = x.getImaginar() * x.getImaginar();
		return sqrt(Re + Im);
	}


	friend Complex sqrt(Complex& x)
	{
		Complex z;
		double Re = sqrt((x.getReal() + modul(x)) / 2);
		double Im;

		if (x.getImaginar() < 0)
			Im = (-1) * sqrt((-x.getReal() + modul(x)) / 2);
		else
			Im = sqrt((-x.getReal() + modul(x)) / 2);
		z.Real = Re;
		z.Imaginar = Im;
		return z;
	}


	

	///Supraincarcarea operatorilor de citire si afisare: ???

	//   friend istream& operator>>(istream& is, Complex& x);

	//   friend ostream& operator<<(ostream& os, const Complex& x);

 






};

#endif // COMPLEX_H











