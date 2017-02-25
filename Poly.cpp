// --------------------------------- Poly.cpp ----------------------------------
// Joon Jung, CSS 343 Fall 2015 Assignment #1
// Created on 10/1/2015
// Last modificated on 10/10/2015
// -----------------------------------------------------------------------------
// Purpose - Composition of functions and constructors of Poly to make Poly Class
// -----------------------------------------------------------------------------
// Note - Orders of coding functions & constructors are same with Poly.h
// -----------------------------------------------------------------------------

#include "Poly.h"

// ------------------------------ operator<< -----------------------------------
// Description: Overload output operator << for Poly Class. Display Poly object.
// -----------------------------------------------------------------------------
ostream &operator<<(ostream &outStream, const Poly &polyOut)
{	
	bool isAllValueZero = true;
	// output print out from back of the array 
	// because lastest array element carry the largest exponent power.
	for (int i = polyOut.arraySize - 1; i >= 0; i--)
	{
		if (polyOut.getCoef(i) != 0)
		{
			outStream << " ";
			isAllValueZero = false;

			if (polyOut.getCoef(i) > 0)
			{
				outStream << "+";
			}
			if (i == 0)
			{
				outStream << polyOut.getCoef(i);
			}
			else if (i == 1)
			{
				outStream << polyOut.getCoef(i) << "x";
			}
			else
			{
				outStream << polyOut.getCoef(i) << "x^" << i;
			}
		}
	}
	// print out single 0 if all values are 0.
	if (isAllValueZero)
	{
		outStream << " " << 0;
	}
	return outStream;
}

// ------------------------------ operator>> ----------------------------------
// Description: Overload input operator >> for Poly Class. Takes user input 
//              into Poly object.
// ----------------------------------------------------------------------------
istream &operator>>(istream &inStream, Poly &incPoly)
{
	int typedCoef = 0;
	int typedIndex = 0;

	while ((typedCoef != -1) || (typedIndex != -1))
	{
		inStream >> typedCoef >> typedIndex;
		incPoly.setCoef(typedCoef, typedIndex);
	}
	return inStream;
}

// ------------------------- Poly <default constructor> ---------------------------
// Description: Defalut constructor that creates Poly Class with one element. 
// --------------------------------------------------------------------------------
Poly::Poly()
{
	// Default constructor creates 1 array 
	// with size of one element that contains value 0.
	arraySize = 1;
	coefPtr = new int[arraySize];
	coefPtr[0] = 0;
}

// ------------------------------ Poly <1 parameter> ------------------------------
// Description: Constructor with 1 parameter that creates Poly Class with array 
//              element size 1. 
// --------------------------------------------------------------------------------
Poly::Poly(int incCoef)
{
	// create array size 1 and put incoming value into array[0].
	arraySize = 1;
	coefPtr = new int[arraySize];
	coefPtr[0] = incCoef;
}

// ----------------------------- Poly <2 parameters> ------------------------------
// Description: Constructor with 2 parameters that creates Poly Class with array 
//              element size number of exponent + 1.
// --------------------------------------------------------------------------------
Poly::Poly(int incCoef, int incPower)
{
	// size of array(arraySize) is always one bigger than index(incPower).
	arraySize = incPower + 1;
	coefPtr = new int[arraySize];
	
	for (int i = 0; i < arraySize; i++)
	{
		coefPtr[i] = 0;
	}
	coefPtr[incPower] = incCoef;
}

// --------------------------- Poly <copy constructor> ----------------------------
// Description: Copy constructor for Poly Class that makes deep copy of incoming
//              Poly object.
// --------------------------------------------------------------------------------
Poly::Poly(const Poly &incPoly)
{
	// create size of array that is same as incoming poly object,
	// then copy individual value into new array.
	arraySize = incPoly.arraySize;
	coefPtr = new int[arraySize];
	
	for (int i = 0; i < arraySize; i++)
	{
		coefPtr[i] = incPoly.coefPtr[i];
	}
}

//------------------------------ ~Poly <destructor> -------------------------------
// Description: Destructor for Poly Class. Delete coefPtr to prevent memory leak.
// --------------------------------------------------------------------------------
Poly::~Poly()
{
	delete[] coefPtr;
}

// ----------------------------------- getCoef ------------------------------------
// Description: get coefficient of x^(n).
// --------------------------------------------------------------------------------
int Poly::getCoef(int incPower) const
{
	// check to see if incoming value is negative or greater than arraySize.
	// If it is then return 0 because it does not have any value.
	if ((this->arraySize <= incPower) || (incPower < 0))
	{
		return 0;
	}
	else
	{
		return this->coefPtr[incPower];
	}
}

// ----------------------------------- setCoef ------------------------------------
// Description: set coefficient of x^(n).
// --------------------------------------------------------------------------------
void Poly::setCoef(const int incCoef, const int incPower)
{
	if (incPower >= 0)
	{
		int newArraySize = incPower + 1;
		// Increase the arraySize if incoming exponent power 
		// is greater than current arraySize.
		if (this->arraySize < newArraySize)
		{
			Poly tempPoly(incCoef, incPower);
			*this += tempPoly;
		}
		else
		{
			this->coefPtr[incPower] = incCoef;
		}
	}
}

// -------------------------------- getArraySize ----------------------------------
// Description: get size of Poly object's array element.
// --------------------------------------------------------------------------------
int Poly::getArraySize() const
{
	return this->arraySize;
}

// -------------------------------- setArraySize ----------------------------------
// Description: set size of Poly object's array element.
// --------------------------------------------------------------------------------
void Poly::setArraySize(const int incNumber)
{
	if (incNumber >= 0)
	{
		arraySize = incNumber;
	}
}

// --------------------------------- operator== -----------------------------------
// Description: overloads == sign that compares two Poly objects to determine that 
//              both objects are same.
// --------------------------------------------------------------------------------
bool Poly::operator==(const Poly &rightPoly) const
{
	int smallerArraySize = 0;
	int biggerArraySize = 0;

	// compare two poly object to determine which one is small and bigger
	if (this->arraySize >= rightPoly.arraySize)
	{
		smallerArraySize = rightPoly.arraySize;
		biggerArraySize = this->arraySize;
	}
	else
	{
		smallerArraySize = this->arraySize;
		biggerArraySize = rightPoly.arraySize;
	}

	// loop through until biggerArraySize and compare contents
	for (int i = 0; i < biggerArraySize; i++)
	{
		if (i < smallerArraySize)
		{
			if (this->coefPtr[i] != rightPoly.coefPtr[i])
			{
				return false;
			}
		}
		// compare rest of elements behind smallerArraySize on bigger array
		else
		{
			if (rightPoly.arraySize > this->arraySize)
			{
				if (rightPoly.coefPtr[i] != 0)
				{
					return false;
				}
			}
			else
			{
				if (this->coefPtr[i] != 0)
				{
					return false;
				}
			}
		}
	}
	// return true when it all passed its condition between two Poly objects.
	return true;
}

// --------------------------------- operator!= -----------------------------------
// Description: overloads != sign that compare two Poly objects to determine that
//                           both objects are not same.
// --------------------------------------------------------------------------------
bool Poly::operator!=(const Poly &rightPoly) const
{
	return !(*this == rightPoly);
}

// --------------------------------- operator+ ------------------------------------
// Description: overloads + sign that performs adding two Poly objects.
// --------------------------------------------------------------------------------
Poly Poly::operator+(const Poly &rightPoly) const
{
	int newExponent = 0;

	// Assign bigger size of array in between Left & Right Poly object.
	// (this->arraySize < rightPoly.arraySize) ? 
	// (newExponent = rightPoly.arraySize - 1) : (newExponent = this->arraySize - 1);
	// is another version of line 269 to 276.
	if (this->arraySize < rightPoly.arraySize)
	{
		newExponent = rightPoly.arraySize - 1;
	}
	else
	{
		newExponent = this->arraySize - 1;
	}

	// Create new Poly object with bigger array size.
	Poly tempPoly(0, newExponent);

	for (int i = 0; i < this->arraySize; i++)
	{
		tempPoly.coefPtr[i] = this->coefPtr[i];

	}

	for (int i = 0; i < rightPoly.arraySize; i++)
	{
		tempPoly.coefPtr[i] += rightPoly.coefPtr[i];
	}
	return tempPoly;
}

// ---------------------------------- operator- -----------------------------------
// Description: overloads - sign that performs subtracting two Poly objects.
//                          Same implementation as overload+ but logic of (-).
// --------------------------------------------------------------------------------
Poly Poly::operator-(const Poly &rightPoly) const
{
	int newExponent = 0;

	if (this->arraySize < rightPoly.arraySize)
	{
		newExponent = rightPoly.arraySize - 1;
	}
	else
	{
		newExponent = this->arraySize - 1;
	}

	Poly tempPoly(0, newExponent);

	for (int i = 0; i < this->arraySize; i++)
	{
		tempPoly.coefPtr[i] = this->coefPtr[i];
	
	}

	for (int i = 0; i < rightPoly.arraySize; i++)
	{
		tempPoly.coefPtr[i] -= rightPoly.coefPtr[i];
	}
	return tempPoly;
}

// ---------------------------------- operator* -----------------------------------
// Description: overloads * sign that performs multiplying two Poly objects
// --------------------------------------------------------------------------------
Poly Poly::operator*(const Poly &rightPoly) const
{
	// size of newExponent is combine of left poly and right poly subtract by 2.
	// It is -2 because it is array index. not array size.
	int newExponent = this->arraySize + rightPoly.arraySize - 2;
	Poly tempPoly(0, newExponent);

	// Outer loop traverse though one Poly object 
	// ,then nested loop calculate multiplying each of elements only if value is not 0.
	for (int i = 0; i < this->arraySize; i++)
	{
		if (this->coefPtr[i] != 0)
		{
			for (int j = 0; j < rightPoly.arraySize; j++)
			{
				tempPoly.coefPtr[i + j] += (this->coefPtr[i] * rightPoly.coefPtr[j]);
			}
		}
	}
	return tempPoly;
}

// -------------------------------- operator+= -----------------------------------
// Description: overloads += sign that calculate addinging two Poly objects,
//              moreover it sums up adding results
// --------------------------------------------------------------------------------
Poly &Poly::operator+=(const Poly &rightPoly)
{
	return *this = (*this + rightPoly);
}

// --------------------------------- operator-= ----------------------------------
// Description: overloads -= sign that calculate subtracting two Poly objects,
//              moreover it sums up subtracting results
// --------------------------------------------------------------------------------
Poly &Poly::operator-=(const Poly &rightPoly)
{
	return *this = (*this - rightPoly);
}

// --------------------------------- operator*= -----------------------------------
// Description: overloads *= sign that calculate multiplying two Poly objects,
//              moreover it sums up multiplying results
// --------------------------------------------------------------------------------
Poly &Poly::operator*=(const Poly &rightPoly)
{
	return *this = (*this * rightPoly);
}

// ---------------------------------- operator= -----------------------------------
// Description: overloads = sign that copy right side of Poly object to left side 
//              of Poly object. This involves deep copy of memory allocate.
// --------------------------------------------------------------------------------
Poly &Poly::operator=(const Poly &rightPoly)
{
	// If current poly object is smaller than incoming poly object,
	// create new array that is size of incoming poly object.
	if (this->arraySize < rightPoly.arraySize)
	{
		// Delete current coefPtr before create bigger array to prevent memory leak.
		delete[] this->coefPtr;
		this->coefPtr = NULL;
		this->arraySize = rightPoly.arraySize;
		this->coefPtr = new int[this->arraySize];

		for (int i = 0; i < this->arraySize; i++)
		{
			this->coefPtr[i] = rightPoly.coefPtr[i];
		}
	}
	// If both Poly's are same size, just copy right poly's value into current one.
	else if (this->arraySize == rightPoly.arraySize)
	{
		for (int i = 0; i < this->arraySize; i++)
		{
			this->coefPtr[i] = rightPoly.coefPtr[i];
		}
	}
	// If current poly object's array size if bigger than incoming poly's,
	// make every array element 0 first, then copy incoming poly's elements.
	else
	{
		for (int i = 0; i < this->arraySize; i++)
		{
			this->coefPtr[i] = 0;
		}

		for (int i = 0; i < rightPoly.arraySize; i++)
		{
			this->coefPtr[i] = rightPoly.coefPtr[i];
		}
	}
	return *this;
}