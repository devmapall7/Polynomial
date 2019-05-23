#pragma once
#include<iostream>
using namespace std;
class Quadratic
{
private:
	// Data representation
	int a, b, c;
public:
	// Constructors
	Quadratic();
	Quadratic(int a);
	Quadratic(int a, int b);
	Quadratic(int a, int b, int c);
	// Member Functions
	int coefficient(unsigned int power) const;
	int compute(int x);
	// Arithmetic Operators
	Quadratic operator+(Quadratic rhs);
	Quadratic operator-(Quadratic rhs);
	// Relational operators
	bool operator==(Quadratic rhs);
	bool operator!=(Quadratic rhs);
	// Update operators
	Quadratic& operator+=(Quadratic rhs);
	Quadratic& operator-=(Quadratic rhs);
	// Getter functions
	// Destructor
	~Quadratic();
};

istream& operator>>(istream& inStream, Quadratic& quadratic);
ostream& operator<<(ostream& outStream, const Quadratic& quadratic);