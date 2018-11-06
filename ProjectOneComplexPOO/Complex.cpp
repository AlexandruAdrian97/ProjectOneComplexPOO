#include "pch.h"
#include "Complex.h"
#include <iostream>
#include <string>

using namespace std;




Complex::Complex(double Re, double Im)
{
	m_real = Re;
	m_imaginar = Im;
}

Complex::Complex(const Complex &x)
{
	m_real = x.getReal();
	m_imaginar = x.getImaginar();
}



// Nu functioneaza si nu inteleg motivul
/*
	Complex::Complex(std::string s) 
	{

	int i = 0;

	if (s[0] == 'i' || s[1] == 'i')
		m_real = 0;
	else
	{
		for (i = 1; i < s.size(); i++)

		if (s[i] == '+' || s[i] == '-')
	break;
		m_real = stod(s.substr(0, i));
}
	if (i == s.size())

	m_imaginar = 0;

		else 
	if (s[i] == '-')

	m_imaginar = -1;

		else 
	m_imaginar = 1;

	if (s[i] != 'i' && i + 3 < s.size())

		m_imaginar *= stod(s.substr(i + 3, s.size()));

	else if (i + 3 < s.size())

		m_imaginar = stod(s.substr(i + 2, s.size()));



}
*/





//Supraîncărcarea operatorilor compuși de atribuire:

Complex& Complex::operator = (const Complex &x)
{
	if (this != &x) {
		this->m_real = x.getReal();
		this->m_imaginar = x.getImaginar();
	}
	return *this;
}

Complex& Complex::operator += (const Complex& x)
{
	m_real += x.getReal();
	m_imaginar += x.getImaginar();
	
	return *this;
}

Complex& Complex::operator += (const double x)
{
	this->m_real = m_real + x;
	return *this;
}

Complex& Complex::operator -= (const Complex& x)
{
	m_real -= x.getReal();
	m_imaginar -= x.getImaginar();	
	return *this;
}

Complex& Complex::operator -= (const double x)
{
	this->m_real = m_real - x;
	return *this;
}

Complex& Complex::operator *= (const Complex& x)
{
	double s = m_real;
	m_real = m_real * x.getReal() - m_imaginar * x.getImaginar();
	m_imaginar = s * x.getImaginar() + m_imaginar * x.getReal();
	
	return *this;

}

Complex& Complex::operator *= (const double x)
{
	m_real = m_real * x;
	m_imaginar = m_imaginar * x;
	return *this;
}

Complex& Complex::operator /= (Complex& x)
{
	double s1 = m_real;
	double s2 = x.getReal() * x.getReal() + x.getImaginar() * x.getImaginar();

	m_real = (m_real * x.getReal() + m_imaginar * x.getImaginar()) / s2;
	m_imaginar = (m_imaginar * x.getReal() - s1 * x.getImaginar()) / s2;

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
		m_real = m_real / x;
		m_imaginar = m_imaginar / x;

		return *this;
	}

}

//Nu functioneaza..
/*
 std::string Complex::ToString() {

	std::string s = "";

	if (x.m_real == 0)
	{
	if (x.m_imaginar == 0)
		s += "0";
			else
	if (x.m_imaginar == 1)
		s += "i";
			else
	if (x.m_imaginar == -1)
		s += "-i";
			else {
	if (x.m_imaginar > 0)
		s += "i*" + to_string(x.m_imaginar);
			else
		s += "-i*" + to_string(-x.m_imaginar);

	}
	}
	else
	{
	if (x.m_imaginar == 0)
		s += to_string(x.m_real);
			else
	if (x.m_imaginar == 1)
		s += to_string(x.m_real) + "+i";
			else
	if (x.m_imaginar == -1)
		s += to_string(x.m_real) + "-i";
			else {
	if (x.m_imaginar > 0)
		s += to_string(x.m_real) + "+i*" + to_string(x.m_imaginar);
			else
		s += to_string(x.m_real) + "-i*" + to_string(-(x.m_imaginar));

	}
	}

	return s;


}


 */

//Supraîncărcarea operatorilor aritmetici unari:

Complex operator + (const Complex &x)
{
	Complex z;
	z.m_real = x.getReal();
	z.m_imaginar = x.getImaginar();
	return z;
}

Complex operator - (const Complex x)
{
	Complex z;
	z.m_real = x.getReal() *(-1);
	z.m_imaginar = x.getImaginar()*(-1);
	return z;
}



//Supraîncărcarea operatorilor aritmetici binari:

Complex operator + (const Complex& x, const Complex& y)
{
	Complex z;
	z.m_real = x.getReal() + y.getReal();
	z.m_imaginar = x.getImaginar() + y.getImaginar();
	return z;
}

Complex operator + (const Complex& x, const double y)
{
	Complex z;
	z.m_real = x.getReal() + y;
	z.m_imaginar = x.getImaginar();
	return z;
}

Complex operator + (const double x, const Complex& y)
{
	Complex z;
	z.m_real = x + y.getReal();
	z.m_imaginar = y.getImaginar();
	return z;
}

Complex operator - (const Complex& x, const Complex& y)
{
	Complex z;
	z.m_real = x.getReal() - y.getReal();
	z.m_imaginar = x.getImaginar() - y.getImaginar();
	return z;
}

Complex operator - (const Complex& x, const double y)
{
	Complex z;
	z.m_real = x.getReal() - y;
	z.m_imaginar = x.getImaginar();
	return z;
}

Complex operator - (const double x, const Complex& y)
{
	Complex z;
	z.m_real = x - y.getReal();
	z.m_imaginar = y.getImaginar();
	return z;
}

Complex operator * (const Complex& x, const Complex& y)
{
	Complex z;
	double a1_a2 = y.getReal() * x.getReal();
	double b1_b2 = y.getImaginar() * x.getImaginar();
	double a1_b2 = y.getReal() * x.getImaginar();
	double b1_a2 = y.getImaginar() * x.getReal();
	z.m_real = a1_a2 - b1_b2;
	z.m_imaginar = b1_a2 + a1_b2;
	return z;
}

Complex operator * (const Complex& x, const double y)
{
	Complex z;
	z.m_real = x.getReal() * y;
	z.m_imaginar = x.getImaginar() * y;
	return z;
}

Complex operator * (const double x, const Complex& y)
{
	Complex z;
	z.m_real = y.getReal() * x;
	z.m_imaginar = y.getImaginar() * x;
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
		z.m_real = re;
		z.m_imaginar = im;
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
		z.m_real = x.getReal() / y;
		z.m_imaginar = x.getImaginar() / y;
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
		z.m_real = (x*y.getReal()) / (y.getReal() * y.getReal() + y.getImaginar() * y.getImaginar());
		z.m_imaginar = (-x * y.getImaginar()) / (y.getReal() * y.getReal() + y.getImaginar() * y.getImaginar());
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
		aux.m_real = 1;
		aux.m_imaginar = 0;
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
	cin >> m_real;
	cout << "Imaginar: ";
	cin >> m_imaginar;
	cout << endl;
}


void Complex::Display()
{
	if (m_real == 0)
	{
		if (m_imaginar == 0)
			cout << "0";
		else
			if (m_imaginar == 1)
				cout << "i";
			else
				if (m_imaginar == -1)
					cout << "-i";
				else {
					if (m_imaginar > 0)
						cout << m_imaginar << "*i";
					else
						cout << m_imaginar << "*i";
				}
	}
	else
		if (m_real > 0)
		{
			if (m_imaginar == 0)
				cout << m_real;
			else
				if (m_imaginar == 1)
					cout << m_real << "+i";
				else
					if (m_imaginar == -1)
						cout << m_real << "-i";
					else {
						if (m_imaginar > 0)
							cout << m_real << "+" << m_imaginar << "*i";
						else
							cout << m_real << m_imaginar << "*i";
					}
		}
		else
			if (m_real < 0)
			{
				if (m_imaginar == 0)
					cout << m_real;
				else
					if (m_imaginar == 1)
						cout << m_real << "+i";
					else
						if (m_imaginar == -1)
							cout << m_real << "-i";
						else {
							if (m_imaginar > 0)
								cout << m_real << "+" << m_imaginar << "*i";
							else
								cout << m_real << m_imaginar << "*i";
						}
			}
}

Complex Complex::Conjugate()
{
	 Complex z;
	z.m_real = m_real;
	z.m_imaginar = -1 * getImaginar();
	return z;

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




