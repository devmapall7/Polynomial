#include "Polynomial.h"


Polynomial::Polynomial()
{
	size = 0;
	coeff = nullptr;
}
Polynomial::Polynomial(int* coeff, int size)
{
	this->size = size;
	this->coeff = new int[size];
	for (int i = 0;i<size;i++) this->coeff[i] = coeff[i];
}
Polynomial::Polynomial(const Polynomial& aPoly)
{
	coeff = new int[aPoly.size];
	for (int i = 0; i < aPoly.size;i++) coeff[i] = aPoly.coeff[i];
	size = aPoly.size;
}
int Polynomial::coefficient(unsigned int power) const
{
	if (power >= this->size) return 0;
	else return this->coeff[power];
}
long long Polynomial::compute(int x)
{
	long long result = 0;
	for (int i = 0;i < size;i++)
	{
		result +=coeff[i]* pow(x,i);
	}
	return result;
}
void Polynomial::grow(unsigned int newSize)
{
	if (newSize > this->size)
	{
		int* temp = new int[newSize];
		for (int i = 0; i < newSize; i++)
		{
			if (i < this->size) temp[i] = this->coeff[i];
			else temp[i] = 0;
		}
		delete[] this->coeff;
		this->coeff = temp;
		this->size = newSize;
	}
	else return;
}
int Polynomial::getSize() const
{
	return this->size;
}
const Polynomial& Polynomial::operator=(const Polynomial& rhs)
{
	if (this == &rhs)
	{
		return *this;
	}
	Polynomial temp(rhs);
	swap(this->size, temp.size);
	swap(this->coeff, temp.coeff);
	return *this;
}
Polynomial Polynomial::operator+(Polynomial rhs)
{
	if (rhs.size > this->size)
	{
		int* temp = new int[rhs.size];
		for (int i = 0; i < rhs.size; i++)
		{
			if (i < this->size) temp[i] = this->coeff[i] + rhs.coeff[i];
			else temp[i] = rhs.coeff[i];
		}
		Polynomial a(temp, rhs.size);
		delete[] temp;
		return Polynomial(a);
	}
	else
	{
		int* temp = new int[this->size];
		for (int i = 0; i < this->size; i++)
		{
			if (i < rhs.size) temp[i] = this->coeff[i] + rhs.coeff[i];
			else temp[i] = this->coeff[i];
		}
		Polynomial a(temp,this->size);
		delete[] temp;
		return Polynomial(a);
	}
}
Polynomial Polynomial::operator-(Polynomial rhs)
{
	if (rhs.size > this->size)
	{
		int* temp = new int[rhs.size];
		for (int i = 0; i < rhs.size; i++)
		{
			if (i < this->size) temp[i] = this->coeff[i] - rhs.coeff[i];
			else temp[i] = 0 - rhs.coeff[i];
		}
		Polynomial a(temp, rhs.size);
		delete[] temp;
		return Polynomial(a);
	}
	else
	{
		int* temp = new int[this->size];
		for (int i = 0; i < this->size; i++)
		{
			if (i < rhs.size) temp[i] = this->coeff[i] - rhs.coeff[i];
			else temp[i] = this->coeff[i];
		}
		Polynomial a(temp, this->size);
		delete[] temp;
		return Polynomial(a);
	}
}
Polynomial Polynomial::operator*(Polynomial rhs)
{
	int* temp = new int[this->size + rhs.size - 1];
	for (int i = 0; i < this->size + rhs.size - 1; i++)
	{
		temp[i] = 0;
	}
	for (int i=0;i<this->size;i++)
		for (int j = 0; j < rhs.size; j++)
		{
			temp[i + j] += this->coeff[i] * rhs.coeff[j];
		}
	Polynomial a(temp, this->size + rhs.size - 1);
	delete[] temp;
	return Polynomial(a);
}
bool Polynomial::operator==(Polynomial rhs)
{
	if (this->size != rhs.size) return 0;
	for (int i = 0; i < this->size; i++)
	{
		if (this->coeff[i] != rhs.coeff[i]) return 0;
	}
	return 1;
}
bool Polynomial::operator!=(Polynomial rhs)
{
	if (this->size != rhs.size) return 1;
	for (int i = 0; i < this->size; i++)
	{
		if (this->coeff[i] != rhs.coeff[i]) return 1;
	}
	return 0;
}
Polynomial& Polynomial::operator+=(Polynomial rhs)
{
	if (this->size < rhs.size) grow(rhs.size);
	for (int i = 0; i < rhs.size; i++)
	{
		this->coeff[i] += rhs.coeff[i];
	}
	return *this;
}
Polynomial& Polynomial::operator-=(Polynomial rhs)
{
	if (this->size < rhs.size) grow(rhs.size);
	for (int i = 0; i < rhs.size; i++)
	{
		this->coeff[i] -= rhs.coeff[i];
	}
	return *this;
}
Polynomial& Polynomial::operator*=(Polynomial rhs)
{
	int* temp = new int[this->size + rhs.size - 1];
	for (int i = 0; i < this->size + rhs.size - 1; i++)
	{
		temp[i] = 0;
	}
	for (int i = 0; i < this->size; i++)
		for (int j = 0; j < rhs.size; j++)
		{
			temp[i + j] += this->coeff[i] * rhs.coeff[j];
		}
	delete[] this->coeff;
	this -> coeff = temp;
	this->size += rhs.size - 1;
	return *this;
}
Polynomial::~Polynomial()
{
	delete[] coeff;
}
istream& operator>>(istream& inStream, Polynomial& poly)
{
	int size;
	inStream >> size;
	int* a = new int[size];
	for (int i = 0; i < size; i++) inStream >> a[i];
	poly = Polynomial(a, size);
	delete[] a;
	return inStream;
}
ostream& operator<<(ostream& outStream,const Polynomial& poly)
{
	bool flag = 0;
	for (int i = poly.getSize(); i >=0; i--)
	{
		if (poly.coefficient(i) != 0)
		{
			if (flag)
			{
				if (poly.coefficient(i) > 0)
				{
				if(i == 0) outStream << "+" << poly.coefficient(i);
				else if (i == 1) outStream << "+" << poly.coefficient(i) << "*x";
				else outStream << "+" << poly.coefficient(i) << "*x^" << i;
				}
				else
				{
					if (i == 0) outStream << poly.coefficient(i);
					else if (i == 1) outStream << poly.coefficient(i) << "*x";
					else outStream << poly.coefficient(i) << "*x^" << i;
				}
			}
			else
			{
				if (i == 0) outStream << poly.coefficient(i);
				else if (i == 1) outStream << poly.coefficient(i) << "*x";
				else outStream << poly.coefficient(i) << "*x^" << i;
				flag = true;
			}
			
		}
	}
	return outStream;
}