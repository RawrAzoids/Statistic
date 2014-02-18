// File:			statSearch.h
// Creator:			RawrAzoids
// DateCreated:		2/15/14
// LastModified:	2/18/14
// Description:		Creates a search object for any particular stat
#ifndef STATSEARCH_H
#define STATSEARCH_H
#include "myTextGameInfoList.h"
#include <string>
#include <queue>

const int STRING_LENGTH = 100;
struct statFusion
{
	int mSize, wSize, cSize;
	magicFo::magicFo *fMagic;
	weapFo::weapFo *fWeapon;
	combFo::combFo *fCombat;
};
class statSearch // All enums to search for what type of stat you are talking about
{
private:
	std::string name, description; // the description up for your own use
	statFo::statFo statistic; // The general type of stat. (agility, strength, combat, distance...)
	distFo::distFo distance; // The general type of distance. If not distance leave as none.
	magicFo::magicFo magic; // The general type of magic used. If not magic leave as none.
	numFo::numFo amount; // The general type of number. (ex: bonus, current, max...)
	combFo::combFo combat; // Type of combat used. If not combat leave as none.
	weapFo::weapFo weapon; // General type of weapon used. If not combat leave as none.
	rsrcFo::rsrcFo resource;
public:
	std::queue<statFo::statFo> statistic;
	std::queue<distFo::distFo> distance
	std::queue<magicFo::magicFo> magic
	statSearch(); // Default constructor
	statSearch(statFo::statFo s, distFo::distFo d, magicFo::magicFo m, numFo::numFo n, combFo::combFo c); // Non-default constructor
	statSearch(statSearch &); // Copy constructror

	// Mutators
	bool setName(std::string s);
	bool setDescription(std::string s);
	void setStatSearch(statFo::statFo s, distFo::distFo d, magicFo::magicFo m, numFo::numFo n, combFo::combFo c);
	void setStatisticInfo(statFo::statFo s);
	void setDistanceInfo(distFo::distFo d);
	void setMagicInfo(magicFo::magicFo m);
	void setAmountInfo(numFo::numFo n);
	void setCombatInfo(combFo::combFo c);
	void clearStatSearch(); // Clears description and sets everything else back to none

	// Accesors
	std::string getName();
	std::string getDescription();
	statSearch getStatSearch();
	std::string getStatisticList();
	std::string getDistanceList();
	std::string getAmountList();
	std::string getCombatList();
	statFo::statFo getStatisticInfo();
	distFo::distFo getDistanceInfo();
	magicFo::magicFo getMagicInfo();
	numFo::numFo getAmountInfo();
	combFo::combFo getCombatInfo();
	// stat* refers to statistic, distance, magic, combat, and resource
	bool similarStat(statSearch); // detects for similar stat* enums between two statSearches
	bool similarAmount(statSearch); // detects for similar stat* and amount enums between two statSearches

	// Overloaded operators
	statSearch operator=(statSearch);
	bool operator==(statSearch);
	bool operator!=(statSearch);
};
#endif
