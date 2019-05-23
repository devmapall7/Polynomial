#pragma once
#include<iostream>
using namespace std;
class Polynomial
{
private:
	int *coeff;
	int size;
public:
	// Constructors
	Polynomial();
	Polynomial(int* coeff, int size);

	// Copy Constructor
	Polynomial(const Polynomial&);

	// Member Functions 
	int coefficient(unsigned int power) const;
	long long compute(int x);
	int getSize() const;
	// Function used to "grow" the array by increasing its size
	void grow(unsigned int newSize);
	// Assignment operator
	const Polynomial& operator=(const Polynomial&);
	// Arithmetic Operators
	Polynomial operator+(Polynomial rhs);
	Polynomial operator-(Polynomial rhs);
	Polynomial operator*(Polynomial rhs);
	// Relational operators
	bool operator==(Polynomial rhs);
	bool operator!=(Polynomial rhs);
	// Update operators
	Polynomial& operator+=(Polynomial rhs);
	Polynomial& operator-=(Polynomial rhs);
	Polynomial& operator*=(Polynomial rhs);
	// Destructor
	~Polynomial();
};

istream& operator>>(istream& inStream, Polynomial& poly);
ostream& operator<<(ostream& outStream, const Polynomial& poly);
