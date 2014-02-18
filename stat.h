// File:			stat.h
// Creator:			RawrAzoids
// DateCreated:		2/15/14
// LastModified:	2/18/14
// Description:		Creates a stat object to allow functionality to a single stat.
#ifndef STAT_H
#define STAT_H
#include <iostream>
#include "statModifier.h"
struct modGroup
{						  
	int size;			  // size of modifiers
	std::queue<std::queue<int>> similar;// keeps track of similar modifiers for calculations
	bool enable;		// enable determines if modifiers are being used
	statModifier *mod; // variables that will be stored in modifier
	modGroup()
	{
		size = 0;
		enable  = false;
		mod = new statModifier[size];
	}
};
struct amountGroup
{
	double base, bonus, current, modifier, total;
	amountGroup()
	{
		base = bonus = total = current = modifier = 0.0;
	}
};
struct statInfo
{
	std::string name, description;
	statInfo()
	{
		name.clear();
		description.clear();
	}
	statInfo(std::string n)
	{
		name = n;
		description.clear();
	}
	statInfo(std::string n, std::string d)
	{
		name = n;
		description = d;
	}
};
class stat
{
private:
	statInfo info;
	modGroup modify;
	amountGroup amount;
	
	void recalcModifier();
	void recalcTotal();
	void recalcSimilar();
public:
	statSearch search; // Public for use of functions 
	stat();
	stat(double base);
	stat(double base, double bonus);
	// Mutators
	bool setBase(double);
	bool setBonus(double);
	bool setCurrent(double);
	bool setName(std::string);
	bool setDescription(std::string);
	bool setEnable(bool);
	bool setModEnable(statSearch s, bool enabled); // sets enable of a modifier by statSearch
	bool setModEnable(int index, bool enabled); // sets enable of a modifier by array index 
	bool setModPerm(statSearch s, bool permanent); // sets permanent of a modifier by statSearch
	bool setModPerm(int index, bool permanent); // sets permanent of a modifier by array index 
	bool addStatModifier(statModifier m);
	bool addStatModifier(statSearch search, double number, double percent, bool inUse, bool isPerm, bool isLock); // adds modifier based on search stat
	bool addStatModifier(statSearch search, double number, double percent); // sets up a temporary modifier inUse = lock = true, isPerm = false
	bool delStatModifier(statSearch search); // deletes modifier based off the search given
	bool delStatModifier(int n); // deletes modifier based off array index (starts at 0)
	bool delStatModifier(); // clears all the none 
	bool alterModifier(statSearch search, double percent, bool inUse, bool isPerm); // alters a modifier based off search
	bool alterModifier(statSearch search, double percent);
	bool alterModifier(int n, double percent, bool inUse, bool isPerm); // alters a modifier based off array index (starts at 0)
	bool alterModifier(int n, double percent);
	//Accesors
	statSearch getSearch(); // gets the statSearch for this
	statSearch getModSearch(int index);  // gets the statSearch for a modify by index
	int getIndexVal();
	bool getModifierInUse(int);
	bool getModifierIsPerm(int);
	bool getSimilar();
	double getModifierPercent(int);
	int getModSize();
	double getBase();
	double getBonus();
	double getModifier();
	double getCurrent();
	double getTotal();
};
#endif
