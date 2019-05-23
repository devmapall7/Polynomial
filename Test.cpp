#include<iostream>
#include "Quadratic.h"
#include "Polynomial.h"
using namespace std;
int main()
{
	// Testing constructors, output and coefficient(output uses coefficient)
	Quadratic q1(5,6,7);
	cout << q1 << endl;
	Quadratic q2(1,2);
	cout << q2 << endl;
	Quadratic q3(9);
	cout << q3 << endl;
	Quadratic q4;
	cout << q4 << endl;
	cout << "Eter 3 numbers for coefficients:";
	cin >> q4;
	cout << q4 << endl;
	// Testing compute
	cout << "x=5 result:";
	cout << q4.compute(5) << endl;
	// Testing == and != operators
	if (q1 == q2) cout << "Error" << endl;
	if (q1 == Quadratic(5,6,7)) cout<<"True"<<endl;
	if (q1 != q2) cout << "True" << endl;
	if (q1 != q1) cout << "Error" << endl;
	// Testing of other operators
	cout << q1 + q4 << endl;
	cout << q4 - q2 << endl;
	q1 += q4;
	q4 -= q2;
	cout << q1 << endl;
	cout << q4 << endl<<endl;
	// Testing constructor
	int temp[] = { 6, 2, -3, 0, 1, 9 };
	Polynomial p1(temp, 6);
	cout << "Constructed polynomial:";
	cout << p1 << endl;
	// First cout should be just an empty line because of how I have implemented <<
	// Testing input and output and coefficient(output uses coefficient)
	Polynomial p2;
	cout << p2 << endl;
	cout << "Enter size followed by coefficients:";
	cin >> p2;
	cout << p2 << endl;
	// Testing compute
	cout << "x=5 result:";
	cout << p2.compute(5) << endl;
	// Testing == and != operators
	if (p1 == p2) cout << "The constructed polynomial and your polynomial are equal!" << endl;
	else if (p1 != p2) cout << "The constructed polynomial and your polynomial are not equal!" << endl;
	if (p1 != p1) cout << "Error!" << endl;
	if (p2 == p2) cout << "True" << endl;
	// Testing +-* operators
	cout << "Addition:" << p1 + p2 << endl;
	cout << "Subtraction:" << p1 - p2 << endl;
	cout << "Multiplication:" << p1 * p2 << endl<<endl;
	// Testing copy constructor and update operators
	Polynomial p3(p2);
	p2 += p1;
	cout << "Addition:" << p2 << endl;
	p1 -= p3;
	cout << "Subtraction:" << p1 << endl;
	p1 += p3;
	p1 *= p3;
	cout << "Multiplication:" << p1 << endl;
	system("PAUSE");
	return 0;
}