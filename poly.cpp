//file: poly.h
//Class polynomial implementations from poly.h
//Louis Taing

#include <iostream>
#include "poly.h"
#include <string>
using namespace std;

//-----------------------------------------------------------------------------
//constructor for polynomial class
Poly::Poly(int coefficientIn, int largestExponentIn)
{
	
	maxExponent = largestExponentIn;
	coeff = coefficientIn;
	
	arr = (int*)malloc(sizeof(int) * getSize());

	//looping through array starting from the largest exp index 
	//or largest coefficient and fill w/ 0's
	for (int i = 0; i < getSize(); i++)
	{
			arr[i] = 0;
	}
	//add coeff to largest exponent
	arr[largestExponentIn] = coefficientIn;
}

//-----------------------------------------------------------------------------
//deep copy constructor for polynomial class
Poly::Poly(const Poly& p)
{
	//added this
	this->maxExponent = p.maxExponent;

	this->arr = (int*)malloc(sizeof(int) * getSize());

	//looping through array starting from the largest exp index 
	//or largest coefficient and fill 
	for (int i = 0; i < getSize(); i++)
	{
		this->arr[i] = p.arr[i];
	}

}

Poly Poly::operator=(const Poly& p)
{
	if (this != &p)
	{
		//added this
		this->maxExponent = p.maxExponent;

		this->arr = (int*)malloc(sizeof(int) * getSize());

		//looping through array starting from the largest exp index 
		//or largest coefficient and fill 
		for (int i = 0; i < getSize(); i++)
		{
			this->arr[i] = p.arr[i];
		}
	}
	
	return *this;
}

//-----------------------------------------------------------------------------
//overloaded addition operator  (add 2 polynomials)
//operator +
Poly Poly::operator+(const Poly& p)
{
	
	if (p.getSize() > this->getSize())
	{
		Poly sum;
		sum = Poly(p);
		
		for (int i = 0; i < getSize(); i++)
		{
			sum.arr[i] = arr[i] + sum.arr[i];
		}
		return sum;
	
	}
	else 
	{
		Poly sum2;
		sum2 = Poly(*this);
		
		for (int i = 0; i < p.getSize(); i++)
		{
			sum2.arr[i] = p.arr[i] + sum2.arr[i];
		}
		return sum2;
	
	}
	
}

//-----------------------------------------------------------------------------
//overloaded subtraction operator (subtract 2 polynomials)
//operator -
Poly Poly::operator-(const Poly& p)
{
	
	if (p.getSize() > getSize())
	{
		Poly difference;
		difference = Poly(p);
		
		for (int i = 0; i < getSize(); i++)
		{
			difference.arr[i] = difference.arr[i] - arr[i];
		}
		
		return difference;
	}
	else
	{
		Poly difference2;
		difference2 = Poly(*this);
		
		for (int i = 0; i < p.getSize(); i++)
		{
			difference2.arr[i] = difference2.arr[i] - p.arr[i];
		}
		return difference2;
	}

}

//-----------------------------------------------------------------------------
//overloaded multiplication operator (multiply 2 polynomials)
//operator *
Poly Poly::operator*(const Poly& p)
{
	int curExponent = p.getSize() + this->getSize();
	//here adding exponents
	Poly product(0, curExponent);

	//for whole array of poly 1 
	for (int i = 0; i < this->getSize(); i++)
	{
		//for whole array of poly 2
		for (int g = 0; g < p.getSize(); g++)
		{
			//multiply coefficients
			product.arr[i + g] += (this->arr[i] * p.arr[g]);
		}
	}
	return product;
}

//-----------------------------------------------------------------------------
//overloaded equality operator (compare 2 polynomials to see if equal)
//operator ==
bool Poly::operator==(const Poly& p) const
{
	//if the exponents aren't the same, then return false
	if (maxExponent != p.maxExponent)
	{
		return false;
	}
	//if the coefficients are not the same, then return false
	for (size_t i = 0; i <= maxExponent; i++)
	{
		if (arr[i] != p.arr[i])
		{
			return false;
		}
	}
	return true;
}

//-----------------------------------------------------------------------------
//overloaded inequality operator (compare 2 polynomials to see if not equal)
//operator !=
bool Poly::operator!=(const Poly& p) const
{
	//if the exponents aren't the same, then return false
	if (maxExponent != p.maxExponent)
	{
		return true;
	}
	//if the coefficients are not the same, then return false
	for (size_t i = 0; i <= maxExponent; i++)
	{
		if (arr[i] != p.arr[i])
		{
			return true;
		}
	}
	return false;
}

//-----------------------------------------------------------------------------
//overloaded addition assignment operator (add 1 polynomial to self )
//operator +=
Poly& Poly::operator+=(Poly& p) 
{
	*this = *this + p;
	return *this;
}

//-----------------------------------------------------------------------------
//overloaded subtraction assignment operator (subtract 1 polynomial with self )
//operator -=
Poly& Poly::operator-=(Poly& p)
{
	*this = *this - p;
	return *this;
}

//-----------------------------------------------------------------------------
//overloaded multiplication assignment operator (multiply 1 polynomial with self )
//operator *=
Poly& Poly::operator*=(Poly& p)
{
	*this = *this * p;
	return *this;
}

//-----------------------------------------------------------------------------
//returns size of array
int Poly::getSize() const
{
	return maxExponent + 1;
}

//-----------------------------------------------------------------------------
//returns coefficient of array if possible
int Poly::getCoeff(int exponent) const
{
	if (exponent >= 0)
	{
		return arr[exponent];
	}
	else
	{
		cout << "input is out of range" << endl;
	}
	return 0;
}

//-----------------------------------------------------------------------------
//Set mutuator
//concatenates polynmials
void Poly::setCoeff(int coeff, int exponent)
{
	int size = exponent + 1;
	if (size > maxExponent + 1)
	{
		//create poly with new exp ...
		int* arr2 = (int*)malloc(sizeof(int) * size);
		
		Poly newP(0, size);
		
		//..fill w/ 0's
		for (int i = 0; i < exponent; i++)
		{
			newP.arr[i] = 0;
		}
		//.. copy over ..
		for (int i = 0; i <= maxExponent; i++)
		{
			newP.arr[i] = arr[i];
		}

		newP.arr[exponent] = coeff;
		maxExponent = size;
		arr = newP.arr;
		maxExponent = exponent;
		newP.arr = NULL;
	}
	else
	{
		arr[exponent] = coeff;
	}
	
}

//-----------------------------------------------------------------------------
// accessor
// operator<<
// Overloaded output operator for class Array;
// outputs values for entire array.
ostream& operator<<(ostream& out, const Poly& p)
{
	//inital string
	string outputString = "";

	//if 1 arg print 
	if (p.getCoeff(0) != 0 && p.maxExponent == 0)
	{
		if (p.getCoeff(0) > 0)
		{
			outputString += "+" + to_string(p.getCoeff(0)) + "x^0";
		}
		else
		{
			outputString += to_string(p.arr[0]) + "x^0";
		}
	}
	//if no arg print
	else if (p.arr[0] == 0 && p.maxExponent == 0)
	{
		outputString += to_string(0) + "x^0";
	}
	//print the x^0 as well in int form (ie +50)
	else if (p.getCoeff(0) != 0)
	{
		//loop through whole array starting from back
		for (int i = p.getSize() - 1; i > 1; i--)
		{

			if (p.getCoeff(i) > 0)
			{
				outputString += "+" + to_string(p.arr[i]) + "x^"+to_string(i);
			}
			else if (p.getCoeff(i) < 0)
			{
				outputString += to_string(p.arr[i]) + "x^" +to_string(i);
			}
		}
		if (p.arr[1] > 0)
		{
			outputString += "+" + to_string(p.arr[1]) + "x";
		}
		else if (p.arr[1] == 0)
		{
			//do nothing
		}
		else
		{
			outputString += to_string(p.arr[1]) + "x";
		}
		if (p.arr[0] >= 0)
		{
			outputString += "+" + to_string(p.getCoeff(0));
		}
		else
		{
			outputString += to_string(p.getCoeff(0));
		}
		
	}

	//if 2 arg print
	else
	{
		//loop through whole array starting from back
		for (int i = p.getSize() - 1; i > 1; i--)
		{
		
			if (p.getCoeff(i) > 0)
			{
				outputString += "+" + to_string(p.arr[i]) + "x^"+ to_string(i);
			}
			else if (p.getCoeff(i) < 0)
			{
				outputString += to_string(p.arr[i]) + "x^"+ to_string(i);
			}
		
		}
		if (p.arr[1] > 0)
		{
			outputString += "+" + to_string(p.arr[1]) + "x";
		}
		else if (p.arr[1] == 0)
		{
			//do nothing
		}
		else
		{
			outputString += to_string(p.arr[1]) + "x";
		}
	}

	out << outputString;
	return out;
}
//-----------------------------------------------------------------------------
// mutuator
// operator>> 
// Overloaded input operator for class Array;
// inputs values for entire array.
istream& operator>>(istream& in, Poly& p)
{
	int coeff = 0;
	int expon = 0;
	bool stop = false;

	while (stop == false)
	{
		in >> coeff;
		in >> expon;
		if (coeff == -1 && expon == -1)
		{
			stop == true;
			break;
		}
		p.setCoeff(coeff, expon);
	}

	return in;
}
