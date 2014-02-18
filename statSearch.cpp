// File:			statSearch.cpp
// Creator:			Clayton Hall
// DateCreated:		2/15/14
// LastModified:	2/18/14
// Description:		
#include "statSearch.h"
statSearch::statSearch()
{
	statistic = statFo::none;
	distance = distFo::none;
	magic = magicFo::none;
	amount = numFo::none;
	combat = combFo::none;
	description.clear();
}
statSearch::statSearch(statFo::statFo s, distFo::distFo d, magicFo::magicFo m, numFo::numFo n, combFo::combFo c)
{
	statistic = s;
	distance = d;
	magic = m;
	amount = n;
	combat = c;
	description.clear();
}
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
	statistic = s;
}
void statSearch::setDistanceInfo(distFo::distFo d)
{
	distance = d;
}
void statSearch::setMagicInfo(magicFo::magicFo m)
{
	magic = m;
}
void statSearch::setAmountInfo(numFo::numFo n)
{
	amount = n;
}
void statSearch::setCombatInfo(combFo::combFo c)
{
	combat = c;
}
void statSearch::clearStatSearch()
{
	statistic = statFo::none;
	distance = distFo::none;
	magic = magicFo::none;
	amount = numFo::none;
	combat = combFo::none;
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
statSearch statSearch::getStatSearch()
{
	return *this;
}
std::string getStatisticList()
{
	return "none health mana energy strength stamina intellect agility dexterity armor speed luck charisma perception weight critcal evade block charm detect hit miss attack defense distance combat damage resistance";
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
	return "none neutral fire water wind earth nature electric holy dark heal"
}
statFo::statFo statSearch::getStatisticInfo()
{
	return statistic;
}
distFo::distFo statSearch::getDistanceInfo()
{
	return distance;
}
magicFo::magicFo statSearch::getMagicInfo()
{
	return magic;
}
numFo::numFo statSearch::getAmountInfo()
{
	return amount;
}
combFo::combFo statSearch::getCombatInfo()
{
	return combat;
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
	amount = s.amount;
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
