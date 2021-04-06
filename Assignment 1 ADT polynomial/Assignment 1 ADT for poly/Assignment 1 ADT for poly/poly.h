//file: poly.h
//Class polynomial
//Louis Taing

#pragma once
#include <iostream>
using namespace std;

//---------------------------------------------------------------------------
// Polynomial class:  an abstract data type 
//   -- allows input and output of the polynomial
//   -- allows for comparison of 2 polynomials
//   -- allows for assignment of 2 polynomials
//   -- size is part of the class (so no longer needs to be passed)
//   -- includes range checking, program terminates for out-of-bound subscripts
//
// Implementation and assumptions:
//   -- implemented using an array
//   -- coeff and exponents defaults are 0
//   -- array elements are initialized to zero
//---------------------------------------------------------------------------
class Poly
{
public:
	Poly(int coefficientIn = 0, int largestExponentIn = 0);	 //constructor
	Poly(const Poly& p);									 //deep copy constructor

													//outputs polynomial, mutuator
	friend ostream& operator<<(ostream& out, const Poly& p); 
	
	Poly operator=(const Poly& p);						//assignments 2 polynomials
	Poly operator+(const Poly& p);						//adds 2 polynomials
	Poly operator-(const Poly& p);						//subtracts 2 polynomials
	Poly operator*(const Poly& p);						//mutlipies 2 polynomials
	bool operator==(const Poly& p) const;				//compares 2 polynomials are equal
	bool operator!=(const Poly& p) const;				//compares 2 polynomials are unequal
	Poly& operator+=(Poly& p);							//adds polynomial to self
	Poly& operator-=(Poly& p);							//subtracts polynomial to self
	Poly& operator*=(Poly& p);							//multiplies polynomial to self

	int getCoeff(int exponent) const;						//adds 2 polynomials
	void setCoeff(int coeff, int exponent);					//adds 2 polynomials

	int getSize() const;									//getter for size of arr

private:
	
	int maxExponent = 0;			//declare exponent for the size of the array + 1
	int coeff = 0;					//declare coeff
	int* arr;						//declare array
};
