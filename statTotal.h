// File:			statTotal.h
// Creator:			Clayton Hall
// DateCreated:		2/15/14
// LastModified:	2/19/14
// Description:		Creates a stat object to allow functionality to a single stat.
#ifndef STATTOTAL_H
#define STATTOTAL_H
#include "statFoundation.h"
#include <list>
const int BOUNDS_MAX = INT_MAX;
const int BOUNDS_MIN = -INT_MAX;
const int BOUNDS_SIZE_MAX = 1;
const int ELEMENT_MAX = INT_MAX;
struct statBounds
{
	double limitMax, limitMin; // Maximum and Minimum bounds that the stat can go
	double limitLower, limitUpper; // Upper and Lower limit of the current bounds
	statBounds()
	{
		limitMax = limitMin = limitLower = limitUpper = 0;
	}
};
struct element
{
	std::string description;
	statFoundation stat;
};
class statTotal
{
private:
	int elementSize;
	bool enableBounds;
	statBounds *bound;
	statFoundation total;
	element *elements;

public:
	statTotal();// Default Constructor
	statTotal(int);// Non-Default Constructor
	statTotal(statTotal&);// Copy Constructor
	// Destructor

	// Mutators
	bool setElementSize(int);

	// Accessors

};
#endif
