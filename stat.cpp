// File:			stat.cpp
// Creator:			RawrAzoids
// DateCreated:		2/15/14
// LastModified:	2/18/14
// Description:		stat.h implementation file

#include "stat.h"
/* Private */
void stat::recalcModifier()
{
/*	recalcSimilar(); // if stats are similar they are calculated in a different way
	if(modify.similar)
	{
		int *indexes; // gets the indexes of which modifiers are similar
		for(int i = 0; i <modify.size;i++)
			amount.modifier = modify.mod[i];

	}*/
}
void stat::recalcSimilar()
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
/*	if(!modify.enable)
	{
		int simCount = 1, curIndex = 0;
		bool *skip; // keeps track of indexes that can be skipped
		skip = new bool[modify.size];
		for(int i = 0; i < modify.similar.size; i++)
			delete []modify.similar.n[i]; // deletes the old similar arrays
		delete []modify.similar.n;
		delete []modify.similar.index; // deletes old similar index array
		delete []modify.similar.size2; // deletes old sizes of arrays
		modify.similar.size = 0;
		for(int i = 0; i < modify.size; i++) // parses through the modify array
		{
			if(!skip[i]) // skip flag
			{
				
				for(int j = 1; j < modify.size; j++) // parses through the modify array
				{
					if(!skip[j] && modify.mod[curIndex].areSimilar(modify.mod[j])) // skip flag and counts similar objects
						{
							simCount++;
							skip[j] = true;
						}
				}
				if(simCount > 1) // similar flag
				{
					int *temp;
					modify.similar.size++; // index array incremented
					temp = new int[modify.similar.size-1]; // temp created to copy index array
					for(int j = 0; j < modify.similar.size-1; j++)
						temp[j] = modify.similar.index[j];
					modify.similar.index = new int[modify.similar.size]; 
					for(int j = 0; j < modify.similar.size-1; j++)
						modify.similar.index[j] = temp[j];
					modify.similar.index[modify.similar.size-1] = i; // copying new index
					delete []temp; // deleting temp for rewrite
					
					for(int j = 0; j< modify.similar.size; j++)
					{
						modify.similar.size2[curIndex] = simCount;
						temp = new int[modify.similar.size2[j]];
						for(int k = 0; k < modify.similar.size2[j]])
							temp = 
						for(int k = 0; k < modify.similar.size2[j]; k++)
						{
							
							if(modify.mod[curIndex].areSimilar(modify.mod[k])
								modify.similar.n[j][k]
	
						}
						for(int k = 1; k < simCount; k++)
						{
							if(modify.mod[curIndex].areSimilar(modify.mod[k])
								
						}
							
						modify.similar.size2[i]++; // incrementing the new array of array element i size
						for(int j = 0; j < modify.similar.size2[i]-1; j++) // copying the old similar array
							temp[j] = modify.similar.n[i][j];
						delete []modify.similar.n[i];
					
						for(int j = 0; j < modify.similar.size; j++)
							modify.similar.n[j] = new int[modify.similar.size2[j]];

						modify.similar.n[i][modify.similar.index[i]] = new int*[modify.similar.size2[i]];
					}
					
					simCount = 1; // resets similar count back to 1
				}

				for(int j = 0; j< simCount; j++)
				{

				}

				for(int j = 0; j<modify.size; j++)
					if(!skip[j])
					{
						curIndex = j;
						j = modify.size;
					}
				skip[i] = true;
			}
			
		}
	}
	for(int i = 0; i < modify.size; i++)
	{
			for(int j = i+1; j < modify.size; j++)
				if(!skip[j])
					if(modify.mod[i].areSimilar(modify.mod[j]))
					{
						similar[j] = true;
						skip[j] = true;
						count++;
					}
			indexes = new int[count];
			for(int k=0; k<count; k++)
				for(int j= i+1; j<modify.size; j++)
					if(similar[j])
						indexes[k] = j;
			for(int j = 0; j<count; j++)
			{
				modify.similar[indexes[j]] = new int[count];
				modify.similar[indexes[j]][j] = indexes[j];
			}
			for(int j = 0; j<modify.size;j++)
				similar[j] = false;
		count = 0;
		delete []indexes;
		}
	}
	delete []similar;
	delete []skip;*/
}
void stat::recalcTotal()
{
	amount.total = amount.base + amount.bonus + amount.modifier;
}
/* Public */
// Constructors (integer values)
stat::stat()
{
	recalcSimilar();
}
stat::stat(double base)
{
	amount.base = amount.total = initial;
	recalcSimilar();
}
// Mutators
bool stat::setBase(double n)
{
	amount.base = n;
}
bool stat::setBonus(double n)
{
	amount.bonus = n;
}
bool stat::setCurrent(double n)
{
	amount.current = n;
}
bool stat::addStatModifier(statModifier m)
{
	return addStatModifier(m.getSearch(),m.getNumber(),m.getPercent(),m.getEnable(),m.getPermanent(),m.getLock());
}
bool stat::addStatModifier(statSearch s, double n, double x, bool enable, bool perm, bool lock)
{
	bool temp;

	if(
	/*if(search == s)
	{
		temp = false;
		std::cerr << "Cannot add an existing modifier. Use alterStatModifier()";
	}
	else if(!search.isSimilar(s)) // Does not allow a stat to modify itself
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
bool stat::addStatModifier(statSearch search, double percent, bool isPerm)
{
	return addStatModifier(search, percent, true, isPerm);
}
bool stat::delStatModifier(statSearch search)
{

}
bool stat::delStatModifier(int n)
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
bool stat::delStatModifier()
{
	bool temp = false;


	return temp;
}
bool stat::alterModifier(statSearch search, double percent, bool inUse, bool isPerm); // alters a modifier based off search
bool stat::alterModifier(statSearch search, double percent);
bool stat::alterModifier(int n, double percent, bool inUse, bool isPerm); // alters a modifier based off array index
bool stat::alterModifier(int n, double percent);
//Accesors
statSearch stat::getSearchStat();
int stat::getStartAmount();
int stat::getModifierAmount();
int stat::getTotalAmount();
