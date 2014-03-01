// File:		statFoundation.cpp
// Creator:		Clayton Hall
// DateCreated:		2/15/14
// LastModified:	3/1/14
// Description:		stat.h implementation file
#include "statFoundation.h"
/* Private */
void statFoundation::recalcModifier()
{
/*	recalcSimilar(); // if stats are similar they are calculated in a different way
	if(modify.similar)
	{
		int *indexes; // gets the indexes of which modifiers are similar
		for(int i = 0; i <modify.size;i++)
			amount.modifier = modify.mod[i];

	}*/
}
void statFoundation::recalcSimilar()
{
	if(!modify.enable)
	{
		bool *skip, similar = false; // keeps track of indexes that can be skipped
		skip = new bool[modify.size];
		std::queue<int> temp;
		for(int i = 0; i <modify.size; i++)
		{
			if(!skip[i]) // index skip flag
			{
				for(int j = 1; j < modify.size; j++)
				{
					if(!skip[j] && modify.mod[i].areSimilar(modify.mod[j])) // skip flag and counts similar objects
						{
							if(!similar)
								temp.push(i);
							similar = true;
							skip[j] = true;
							temp.push(j);
						}
				}
				modify.similar.push(temp);
				for(int j = 0; j <temp.size(); j++)
					temp.pop();
				similar = false;
			}
			skip[i] = true;
		}
	}
}
void statFoundation::recalcTotal()
{
	total.amount = base.amount + bonus.amount;
}
/* Public */
// Constructors (integer values)
statFoundation::stat()
{
}
// Mutators
/*bool statFoundation::setBase(double n)
{
	base.amount = n;
}
bool statFoundation::setBonus(double n)
{
	amount.bonus = n;
}
bool statFoundation::setCurrent(double n)
{
	amount.current = n;
}*/
bool statFoundation::addStatModifier(statModifier m)
{
	return addStatModifier(m.getSearch(),m.getNumber(),m.getPercent(),m.getEnable(),m.getPermanent(),m.getLock());
}
bool statFoundation::addStatModifier(statSearch s, double n, double x, bool enable, bool perm, bool lock)
{
	bool temp;
	
	// Needs to be implemented.
	if(search == s)
	{
		
		
	}
	/*else if(!search.isSimilar(s)) // Does not allow a stat to modify itself
	{
		recalcSimilar();
		temp = true;
		statModifier *infoTemp;
		infoTemp = new statModifier[modify.size];
		for(int i = 0; i < modify.size; i++) // finds if the new stat is not similar to any previous ones
		{									// quits and sends back false if the new modifier is previous to ones
			if(modify.mod[i].getSearch().isSimilar(infoTemp[i].getSearch()))
			{
				std::cerr << "New modifier can not be similar to previous ones.";
				temp = false;
				i = modify.size; 
			}
		}
		if(temp)
		{
			for(int i = 0; i < modify.size; i++) // copying all the previous information into a temp variable
			{
				infoTemp[i].setSearch(modify.mod[i].getSearch());
				infoTemp[i].setPercent(modify.mod[i].getPercent());
				infoTemp[i].inUse = modify.mod[i].inUse;
				infoTemp[i].isPerm = modify.mod[i].isPerm;
			}
			delete [] modify.mod;
			modify.mod = new statInfo[modify.size+1];
			for(int i = 0; i < modify.size; i++) // copying the previous information back into modify
			{
				modify.mod[i].search.setStatisticInfo(); = infoTemp[i].search;
				modify.mod[i].percent = infoTemp[i].percent;
				modify.mod[i].inUse = infoTemp[i].inUse;
				modify.mod[i].isPerm = infoTemp[i].isPerm;
			}
			modify.mod[modify.size].search = s;
			modify.mod[modify.size].percent = percent;
			modify.mod[modify.size].inUse = inUse;
			modify.mod[modify.size].isPerm = isPerm;
			modify.size++;
		}
			
		delete []infoTemp;
	}
	else
	{
		temp = true;

	}*/

	return temp;
}
bool statFoundation::addStatModifier(statSearch search, double percent, bool isPerm)
{
	return addStatModifier(search, percent, true, isPerm);
}
bool statFoundation::delStatModifier(statSearch search)
{

}
bool statFoundation::delStatModifier(int n)
{
	bool temp = true;
	if(n < modify.size && !modify.mod[n].isPerm) // Checks to see if n is bigger than array size
	{											 // and makes sure the modifier isn't permanent
		bool temp2 = false;
		statModifier *infoTemp;
		infoTemp = new statModifier[modify.size-1];
		for(int i = 0; i <modify.size-1;i++)
		{
			if(!temp2)
			{
				infoTemp[i].search = modify.mod[i].search;
				infoTemp[i].percent = modify.mod[i].percent;
				infoTemp[i].inUse = modify.mod[i].inUse;
				infoTemp[i].isPerm = modify.mod[i].isPerm;
			}
			else
			{
				infoTemp[i].search = modify.mod[i+1].search;
				infoTemp[i].percent = modify.mod[i+1].percent;
				infoTemp[i].inUse = modify.mod[i+1].inUse;
				infoTemp[i].isPerm = modify.mod[i+1].isPerm;
			}
			if(!temp2 && i < n)
				temp2 = true;
		}
		delete [] modify.mod;
		modify.size--;
		modify.mod = new statInfo[modify.size];
		for(int i = 0; i <modify.size-1; i++)
		{
				modify.mod[i].search = infoTemp[i].search;
				modify.mod[i].percent = infoTemp[i].percent;
				modify.mod[i].inUse = infoTemp[i].inUse;
				modify.mod[i].isPerm = infoTemp[i].isPerm;
		}
		delete [] infoTemp;
	}
	else
		temp = false;
	return temp;
}
bool statFoundation::delStatModifier()
{
	bool temp = false;


	return temp;
}
//Accesors
statSearch statFoundation::getSearchStat();
int statFoundation::getStartAmount();
int statFoundation::getModifierAmount();
int statFoundation::getTotalAmount();
