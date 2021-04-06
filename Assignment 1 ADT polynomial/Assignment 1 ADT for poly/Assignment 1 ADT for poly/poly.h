#pragma once
#include <iostream>
using namespace std;


class Poly
{
public:
	Poly(int coefficientIn = 0, int largestExponentIn = 0);
	//deep copy constructor
	Poly(const Poly& p);


	~Poly();

	//overloads
	friend ostream& operator<<(ostream& out, const Poly& p);

	Poly operator+(const Poly& p);
	Poly operator-(const Poly& p);
	Poly operator*(const Poly& p);
	bool operator==(const Poly& p) const;
	bool operator!=(const Poly& p) const;
	Poly& operator+=(Poly& p);
	Poly& operator-=(Poly& p);
	Poly& operator*=(Poly& p);

	//Poly operator-(int n) const;
	//Poly operator+(int n) const;
	//Poly operator*(int n);
	//Poly& operator+=(int n);
	//Poly& operator-=(int n);
	//Poly& operator*=(int n);


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
