#include "Quadratic.h"


Quadratic::Quadratic()
{
	a = 0;
	b = 0;
	c = 0;
}

Quadratic::Quadratic(int xa)
{
	a = xa;
	b = 0;
	c = 0;
}

Quadratic::Quadratic(int xa, int xb)
{
	a = xa;
	b = xb;
	c = 0;
}

Quadratic::Quadratic(int xa, int xb, int xc)
{
	a = xa;
	b = xb;
	c = xc;
}

int Quadratic::coefficient(unsigned int power) const
{
	if (power == 0) return c;
	else if (power == 1) return b;
	else if (power == 2) return a;
	else return 0;
}

int Quadratic::compute(int value)
{
	return value*value*a + value*b + c;
}

Quadratic Quadratic::operator+(Quadratic rhs)
{
	return Quadratic(a + rhs.a, b + rhs.b, c + rhs.c);
}

Quadratic Quadratic::operator-(Quadratic rhs)
{
	return Quadratic(a - rhs.a, b - rhs.b, c - rhs.c);
}

bool Quadratic::operator ==(Quadratic rhs)
{
	return a == rhs.a && b == rhs.b && c == rhs.c;
}

bool Quadratic::operator !=(Quadratic rhs)
{
	return a != rhs.a && b != rhs.b && c != rhs.c;
}

Quadratic& Quadratic::operator+=(Quadratic rhs)
{
	this->a += rhs.a;
	this->b += rhs.b;
	this->c += rhs.c;
	return *this;
}

Quadratic& Quadratic::operator-=(Quadratic rhs)
{
	this->a -= rhs.a;
	this->b -= rhs.b;
	this->c -= rhs.c;
	return *this;
}

istream& operator>>(istream& inStream, Quadratic& quadratic)
{
	int a, b, c;
	inStream >> a  >> b  >> c;
	quadratic = Quadratic(a, b, c);
	return inStream;
}

ostream& operator<<(ostream& outStream, const Quadratic& quadratic)
{
	outStream << quadratic.coefficient(2) << "*x^2";
	if (quadratic.coefficient(1) >= 0) outStream << "+";
	outStream << quadratic.coefficient(1) << "*x";
	if (quadratic.coefficient(0) >= 0) outStream << "+";
	outStream << quadratic.coefficient(0);
	return outStream;
}
Quadratic::~Quadratic()
{
}
