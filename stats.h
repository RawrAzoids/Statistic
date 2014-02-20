// File:			stats.h
// Creator:			Clayton Hall
// DateCreated:		7/23/13
// LastModified:	2/19/14
// Description:		Allows the use of stats and modifiers.
#ifndef STATS_H
#define STATS_H
#include "statTotal.h"

const int STAT_MAX = 1;
const int BASE_STAT_MAX = 1;
const int RESOURCE_STAT_MAX = 1;
const int SPECIAL_STAT_MAX = 1;
const int CUSTOM_STAT_MAX = 5;

struct baseStatInfo
{
	statTotal *info;
	bool enable;
};
struct minMaxStat
{
	statTotal min, max;
};
struct specialStatFndtn
{
	minMaxStat amount;
	statTotal basic, chance;
};
struct specialStatInfo
{
	specialStatFndtn *info;
	bool enable;
};
struct distanceStatFndtn
{
	minMaxStat amount;
	statTotal basic;
};
struct distanceStatInfo
{
	distanceStatFndtn *info;
	bool enable;
};
struct damageStatFndtn
{
	specialStatInfo critical, hit, miss, injure, effect;
	minMaxStat amount;
	statTotal basic; 
};
struct defenseStatFndtn
{
	specialStatInfo block, parry, evade, counter;
	minMaxStat amount;
	statTotal basic; 
};
struct combatStatFndtn
{
	damageStatFndtn damage;
	defenseStatFndtn defense;
};
struct combatStatInfo
{
	combatStatFndtn *info;
	bool enable;
};
struct baseStats
{		// gives two stats for similar things (strength brown),(stamina and fortitude)...
	baseStatInfo strength, brawn, stamina, fortitude, intellect, wisdom, agility, dexterity, speed, quickness, luck, fate, charisma, social, perception, alertness, mass, weight, *custom;
};
struct resourceStats
{   // Gives two stats for similar things (health vitality),(mana psych)...
	baseStatInfo health, vitality, mana, psyche, energy, endurance, points, score, *custom;
};
struct specialStat
{
	specialStatInfo fortune, detect, sneak, charm, *custom;
};
struct combatStat
{
	combatStatInfo melee, range, spell, chemical, *custom;
};
struct distanceStat
{
	distanceStatInfo melee, range, spell, chemical, vision, travel, detect, *custom;
};
class stats
{
private:
	baseStats base;
	combatStat combat;
	specialStat special;
	distanceStat distance;
	resourceStats resource;


public:
	stats();
/*	// Mutators
	void recalcStatTotal();
//	void recalcStatBonus();
	void recalcStatBase();
	bool recalcStats(mit::myInfoType stat);
	void recalcDefenseResist();
	void recalcDistance();
public:
	// Default constructor
	stats();
	// Non-default constructor

	// Copy constructor
	stats(stats&);
	// Mutators
	bool incrStat(mit::myInfoType stat, double);
	bool incrStat(magicType magic, int, char);
	void baseStatsIncr(int maxHealth, int strength, int stamina, int intellect, int agility, int armor, int speed, int perception, int charisma, int weight, double bonCrit, double bonEvade, double bonBlock, double bonCharm);
	void bonStatsIncr(int bonHealth, int strength, int stamina, int intellect, int agility, int armor, int speed, int perception, int charisma, int weight, double bonCrit, double bonEvade, double bonBlock, double bonCharm);
	void incrBonDam(int minSpell, int maxSpell, int minRange, int maxRange, int minMelee, int maxMelee);
	void incrBonRng(int melee, int range, int spell);
	bool magicIncr(char c, int _neutral, int _fire, int _water, int _nature, int _holy, int _dark, int _heal);
	bool magicIncr(std::string s, int _neutral, int _fire, int _water, int _nature, int _holy, int _dark, int _heal);
	bool setLevel(int lvl);
	bool addStatModifier(statSearch modified, double amount, statSearch modifier);
	// Accesors
	double getStatInfo(stat::statType stat, baseBonTot::baseBonTot baseBonTot);
	double getStatInfo(minMax::minMax minMax, stat::statType stat);
	double myStatsInfo(mit::myInfoType stat);
	double myStatsInfo(stat::statType stat);
	int myResistance(magicType magic, char);
	playerStatus myStatus();

	// Overloaded Operators
	*/
};
#endif
