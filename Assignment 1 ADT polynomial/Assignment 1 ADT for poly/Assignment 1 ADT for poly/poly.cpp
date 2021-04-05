///////////////////////////////////////////////////////
/// NEED COMMENTS
//////////////////////////////////////

#include <iostream>
#include "poly.h"
#include <string>
using namespace std;

//constructor
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

//deep copy constructor
Poly::Poly(Poly& p)
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

Poly Poly::operator+(Poly& p)
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

Poly Poly::operator-(Poly& p)
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
//multiply the coeff, add the exponents
Poly Poly::operator*(Poly& p)
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



int Poly::getSize() const
{
	return maxExponent + 1;
}

int Poly::getCoeff(int exponent) const
{
	return arr[exponent];
}

void Poly::setCoeff(int coeff, int exponent)
{
	arr[exponent] = coeff;
}

//gotta valgrind to check
Poly::~Poly()
{
	
}


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

	//if 2 arg print
	else
	{
		//TODO don't print 0's if zeros filled deleted
		//loop through whole array starting from back
		for (int i = p.getSize() - 1; i > 0; i--)
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
	}

	out << outputString;
	return out;
}
