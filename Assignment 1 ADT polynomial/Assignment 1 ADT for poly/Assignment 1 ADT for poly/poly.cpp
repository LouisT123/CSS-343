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
	/*for (int i = 0; i < getSize(); i++)
	{
			arr[i] = 0;
	}*/
	//add coeff to largest exponent
	arr[largestExponentIn] = coefficientIn;
}

//deep copy constructor
Poly::Poly(Poly& p)
{
	maxExponent = p.maxExponent;

	this->arr = (int*)malloc(sizeof(int) * getSize());

	//looping through array starting from the largest exp index 
	//or largest coefficient and fill w/ 0's
	/*for (int i = 0; i < getSize(); i++)
	{
		this->arr[i] = 0;
	}*/

	//add coeff to largest exponent
	this->arr[p.maxExponent] = p.coeff;

}

Poly Poly::operator+(const Poly& p) 
{
	////find biggest power
	//int maxExp = this->maxExponent;
	////if first exp larger than last...
	//if (this->getSize() > p.getSize())
	//{
	//	//...make it the largest exp
	//	maxExp = this->getSize();

	//	//create new poly based on this size
	//	Poly sum(*this);

	//	//for size of poly with smallest exp 
	//	for (int i = 0; i < p.getSize() + 1; i++)
	//	{
	//		//add each element of this array with corresponding element from other object's array 
	//		sum.arr[i] = sum.arr[i] + p.arr[i];
	//	}
	//	return sum;
	//}
	//else
	//{
	//	for (int i = 0; i < ; i++)
	//	{

	//	}
	//}

	//another attempt at implementation  

	if (this->getSize() > p.getSize())
	{
		Poly sum(*this);
		for (size_t i = 0; i < this->getSize(); i++)
		{
			sum.arr[i] = arr[i];
		}
		for (size_t i = 0; i < p.getSize(); i++)
		{
			sum.arr[i] += p.arr[i];
		}
		//sum is returning (0,8)
		return sum;
	}

	

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
//Poly::~Poly()
//{
	//delete[] arr;
//}


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

		//TODO don't print 0's
		//loop through whole array starting from back
		for (int i = p.getSize() - 1; i > 0; i--)
		{
			
			if (p.getCoeff(i) > 0)
			{
				outputString += "+" + to_string(p.arr[i]) + "x^" + to_string(i);
			}
			else if (p.getCoeff(i) < 0)
			{
				outputString += to_string(p.arr[i]) + "x^" + to_string(i);
			}
		}
	}

	out << outputString;
	return out;
}
