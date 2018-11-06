
#ifndef COMPLEX_H
#define COMPLEX_H
#include <math.h>
#include <iostream>
#include <string>

class Complex
{
private:

	double m_real, m_imaginar;

public:

	
	Complex(double r=0, double i=0);
	Complex(const Complex&);
	
	Complex(std::string); 

	void setReal(double Re) { m_real = Re; }
	double getReal()const { return m_real; }

	void setImaginar(double Im) { m_imaginar = Im; }
	double getImaginar()const { return m_imaginar; }

	void Add();
	void Display();
	Complex Conjugate();


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
		z.m_real = Re;
		z.m_imaginar = Im;
		return z;
	}


	

	//Supraincarcarea operatorilor de citire si afisare: ???

//	   friend istream& operator>>(istream& is, Complex& x);

	//   friend ostream& operator<<(ostream& os, const Complex& x);

 






};

#endif // COMPLEX_H











