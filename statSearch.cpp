// File:			statSearch.cpp
// Creator:			RawrAzoids
// DateCreated:		2/15/14
// LastModified:	2/25/14
// Description:		
#include "statSearch.h"
statSearch::statSearch()
{
	description.clear();
}
/*statSearch::statSearch(statFo::statFo s, distFo::distFo d, magicFo::magicFo m, numFo::numFo n, combFo::combFo c)
{
	statistic = new
	statistic = s;
	distance = d;
	magic = m;
	amount = n;
	combat = c;
	description.clear();
}*/
statSearch::statSearch(statSearch &s)
{
	amount = s.amount;
	distance = s.distance;
	statistic = s.statistic;
	combat = s.combat;
	description = s.description;
	magic = s.magic;
}
// Mutators
bool statSearch::setName(std::string s)
{
	bool temp = true;
	if(s.length() < STRING_LENGTH)
		name = s;
	else
		temp = false;
	return temp;
}
bool statSearch::setDescription(std::string s)
{
	bool temp = true;
	if(s.length() < STRING_LENGTH)
		description = s;
	else
		temp = false;
	return temp;
}
void statSearch::setStatSearch(statFo::statFo s, distFo::distFo d, magicFo::magicFo m, numFo::numFo n, combFo::combFo c)
{
	statistic = s;
	distance = d;
	magic = m;
	amount = n;
	combat = c;
}
void statSearch::setStatisticInfo(statFo::statFo s)
{
	if(statistic == NULL)
		statistic[0]= new statFo::statFo[1];
	statistic = s;
}
void statSearch::setDistanceInfo(distFo::distFo d)
{
	if(distance == NULL)
		distance = new distFo::distFo[1];
	distance[0] = d;
}
void statSearch::setMagicInfo(magicFo::magicFo m)
{
	if(magic == NULL)
		magic = new magicFo::magicFo[1];
	magic[0] = m;
}
void statSearch::setAmountInfo(numFo::numFo n)
{
	if(amount == NULL)
		amount = new numFo::numFo[1];
	amount[0] = n;
}
void statSearch::setCombatInfo(combFo::combFo c)
{
	if(combat == NULL)
		combat = new combFo::combFo[1];
	combat[0] = c;
}
void statSearch::clearStatSearch()
{
	delete statistic;
	delete distance;
	delete magic;
	delete amount;
	delete combat;
	name.clear();
	description.clear();
}
// Accesors
std::string statSearch::getName()
{
	return name;
}
std::string statSearch::getDescription()
{
	return description;
}
statSearch statSearch::getSearchInfo()
{
	return *this;
}
std::string getStatisticList()
{
	return "none health mana energy strength stamina intellect agility dexterity armor speed luck charisma"
	+ " perception weight critcal evade block charm detect hit miss attack defense distance combat damage resistance";
}
std::string getDistanceList()
{
	return "none combat travel vision detect";
}
std::string getAmountList()
{ 
	return "none base bonus total current percent lower upper min max modifier";
}
std::string getCombatList()
{
	return "none melee range magic chemical fusion";
}
std::string getMagicList()
{
	return "none neutral fire water wind earth nature electric holy dark heal";
}
statFo::statFo statSearch::getStatisticInfo()
{
	if(statistic != NULL)
		return statistic[0];
	else
		return statFo::none;
}
distFo::distFo statSearch::getDistanceInfo()
{
	if(distance != NULL)
		return distance[0];
	else
		return distFo::none;
}
magicFo::magicFo statSearch::getMagicInfo()
{
	if(magic != NULL)
		return magic[0];
	else
		return magFo::none;
}
numFo::numFo statSearch::getAmountInfo()
{
	if(amount != NULL)
		return amount[0];
	else
		return numFo::none;
}
combFo::combFo statSearch::getCombatInfo()
{
	if(combat != NULL)
		return combat[0];
	else
		return combFo::none;
}
bool statSearch::similarStat(statSearch s)
{
	bool temp = false;
	if(statistic != statFo::none && s.statistic != statFo::none)
	{
		if(statistic == s.statistic)
		{
			switch(statistic)
			{
			case statFo::distance:
				if(distance != distFo::none && s.distance != distFo::none)
					if(distance == s.distance)
						temp = true;
				break;
			case statFo::combat:
				if(combat != combFo::none && s.combat != combFo::none)
					if(combat == s.combat)
						temp = true;
				break;
			case statFo::resistance:
				if(magic != magicFo::none && s.magic != magicFo::none)
					if(magic == s.magic)
						temp = true;
				break;
			default:
				temp = true;break;
			}
		}
	}
	return temp;
}
bool statSearch::similarAmount(statSearch s)
{
	bool temp = false;
	if(statistic != statFo::none && s.statistic != statFo::none)
	{
		if(amount != numFo::none && s.amount != numFo::none)
			if(amount == s.amount)
			{
				if(statistic == s.statistic)
				{
					switch(statistic)
					{
					case statFo::distance:
						if(distance != distFo::none && s.distance != distFo::none)
							if(distance == s.distance)
								temp = true;
						break;
					case statFo::combat:
						if(combat != combFo::none && s.combat != combFo::none)
							if(combat == s.combat)
								temp = true;
						break;
					case statFo::resistance:
						if(magic != magicFo::none && s.magic != magicFo::none)
							if(magic == s.magic)
								temp = true;
						break;
					default:
						temp = true;break;
					}
				}
			}
	}
	return temp;
}
// Overloaded operators
statSearch statSearch::operator=(statSearch s)
{
	if(s.amount != NULL)
		setAmountInfo(s.amount[0]);
	distance = s.distance;
	statistic = s.statistic;
	combat = s.combat;
	description = s.description;
	magic = s.magic;
}
bool statSearch::operator==(statSearch s)
{
	bool temp;
	if(statistic != s.statistic)
		temp = false;
	else if(distance != s.distance)
		temp = false;
	else if(magic != s.magic)
		temp = false;
	else if(amount != s.amount)
		temp = false;
	else if(combat != s.combat)
		temp = false;
	else
		temp = true;
	return temp;
}
bool statSearch::operator!=(statSearch s)
{
	return !(*this == s);
}
