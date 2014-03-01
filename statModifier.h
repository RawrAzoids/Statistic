// File:		statModifier.h
// Creator:		RawrAzoids
// DateCreated:		2/16/14
// LastModified:	3/1/14
// Description:		Allows functionality to the modifiers for any particular stat
#ifndef STATMODIFIER_H
#define STATMODIFIER_H
#include "statSearch.h"
class statModifier // (in statSearch as statFo::modifier) 
{
private:
	statSearch search;
	bool enable; // Determines if being used or not (for pointers)
	bool perm; // Cannot delete if perm = true (for pointers)
	bool lock; // Cannot modify if lock = true (statVal can be modified in case of stat changes)
	double percent; // multiplied by statVal and added to total
	double statVal; // determined by what stat is selected by search (in statSearch as numFo::base)
	double plusC;  // value that is added to total (bonus) (in statSearch as numFo::)
	double total; // total = percent*statVal + plusC
	void recalcTotal();
public:
	statSearch search; // The search for what stat you want to the current stat modified by (public for use of functions)
	statModifier(); // Default constructor
	statModifier(statSearch s, double stat, double per, double plus, bool isPerm, bool isEnable, bool isLock); // Non-default Constructor
	statModifier(statModifier &); // Copy Constructor
	//Mutators
	void setLock(bool); // void always modifiable
	void setStatVal(double n); // void since it is always modifiable
	bool initializeModifier(statSearch s, double stat, double per, double plus, bool isPerm, bool isEnable, bool isLock);
	bool setSearch(statSearch s);
	bool setEnable(bool); // bool modify restrictions
	bool setPermanent(bool); // bool modify restrictions
	bool setPercent(double); // bool modify restrictions
	bool setPlusC(double); // bool modify restrictions
	bool clearModifier(); // sets everything back to their initial values unless locked
	// Accessors
	statSearch getSearch();
	double getPercent();
	double getPlusC();
	double getStatVal();
	double getTotal();
	bool getLock();
	bool getPermanent();
	bool getEnable();
	statModifier operator=(statModifier); // Overrides even if lock is enabled
	bool operator==(statModifier); // Determines
	bool operator!=(statModifier);
};
#endif
