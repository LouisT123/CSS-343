#pragma once
#include <iostream>
using namespace std;


class Poly
{
public:
	Poly(int coefficientIn = 0, int largestExponentIn = 0);
	//deep copy constructor
	Poly(Poly& p);


	~Poly();

	//overloads
	friend ostream& operator<<(ostream& out, const Poly& p);

	Poly operator+( Poly& p);
	Poly operator-( Poly& p);
	Poly operator*(unsigned int num);
	bool operator==(const Poly& p) const;
	bool operator!=(const Poly& p) const;
	Poly& operator+=(const Poly& p) const;
	Poly& operator-=(const Poly& p) const;
	//might have to see bout this one
	Poly& operator*=(const Poly& p) const;

	//a get and set coeff w/ out of range on get
	int getCoeff(int exponent) const;
	void setCoeff(int coeff, int exponent);

	int getSize() const;

private:

	//declare exponent for the size of the array + 1
	int maxExponent = 0;

	int coeff = 0;
	//declare array
	int* arr;
};
