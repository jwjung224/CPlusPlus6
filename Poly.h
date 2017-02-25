// ------------------------------- Poly.h -------------------------------
// Joon Jung, CSS 343 Fall 2015 Assignment #1
// Created on 10/1/2015
// Last modificated on 10/10/2015
// ---------------------------------------------------------------------- 
// Purpose - Design file of Poly.cpp file
//           This Poly.h file comprise of constructors, functions
//           overload operators, and private datas to depict polynomial 
//           equations that use array.
// ---------------------------------------------------------------------- 
// Note - Dynamically allocate initial memory for array using only 
//        as many elements as needed is the key.
// ---------------------------------------------------------------------- 

#include <iostream>

using namespace std;

class Poly
{
	// Overload operators for input stream & output steam
	friend ostream &operator<<(ostream &outStream, const Poly &polyOut);
	friend istream &operator>>(istream &inStream, Poly &polyIn);

public:
	// Constructors include copy constoructor
	Poly();
	Poly(const int incCoef);
	Poly(const int incCoef, const int incPower);
	Poly(const Poly &incPoly);
	~Poly();

	// Accessors (i.e getters & setters)
	int getCoef(const int incPower) const;
	void setCoef(const int incCoef, const int incPower);
	int getArraySize() const;
	void setArraySize(const int incNumber);

	// Overloads common operators
	bool operator==(const Poly &rightPoly) const;
	bool operator!=(const Poly &rightPoly) const;
	Poly operator+(const Poly &rightPoly) const;
	Poly operator-(const Poly &rightPoly) const;
	Poly operator*(const Poly &rightPoly) const;
	Poly &operator+=(const Poly &rightPoly);
	Poly &operator-=(const Poly &rightPoly);
	Poly &operator*=(const Poly &rightPoly);
	Poly &operator=(const Poly &rightPoly);

private:
	// Private value of Poly.h consist of one pointer that points to array and its array size
	int* coefPtr = NULL;
	int arraySize;
};
