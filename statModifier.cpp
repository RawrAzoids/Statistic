// File:			statModifier.cpp
// Creator:			RawrAzoids
// DateCreated:		2/16/14
// LastModified:	2/18/14
// Description:		implementation file
#include "statModifier.h"
statModifier::statModifier()
{
	enable = perm = lock = false;
	search.clearStatSearch();
	percent = statVal = plusC = total = 0.0;
}
statModifier::statModifier(statSearch s, double stat, double per, double plus, bool isPerm, bool isEnable, bool isLock)
{
	search = s;
	statVal = stat;
	percent = per;
	plusC = plus;
	perm = isPerm;
	enable = isEnable;
	lock = isLock;
	recalcTotal();
}
statModifier::statModifier(statModifier& m)
{
	search = m.search;
	statVal = m.statVal;
	percent = m.percent;
	plusC = m.plusC;
	perm = m.perm;
	enable = m.enable;
	lock = m.lock;
	recalcTotal();
}
//Mutators
// Private
// Public
void statModifier::setLock(bool b)
{
	lock = b;
}
void statModifier::setStatVal(double n)
{
	statVal = n;
	recalcTotal();
}
bool statModifier::setPlusC(double n)
{
	bool temp = true;
	if(!lock)
		plusC =  n;
	else
		temp = false;
	return temp;
}
bool statModifier::initializeModifier(statSearch s, double stat, double per, double plus, bool isPerm, bool isEnable, bool isLock)
{
	bool temp = true;
	if(!lock)
	{
		search = s;
		percent = per;
		statVal = stat;
		plusC = plus;
		perm = isPerm;
		enable = isEnable;
		lock = isLock;
		recalcTotal();
	}
	else
		temp = false;
	return temp;
}
bool statModifier::setSearch(statSearch s)
{
	bool temp = true;
	if(!lock)
		search = s;
	else
		temp = false;
	return temp;
}
bool statModifier::setEnable(bool b)
{
	bool temp = true;
	if(!lock)
	{
		enable = b;
		recalcAmount()
	}
	else
		temp = false;
	return temp;
}
bool statModifier::setPermanent(bool b)
{
	bool temp = true;
	if(!lock)
		perm = b;
	else
		temp = false;
	return temp;
}
bool statModifier::setPercent(double x)
{
	bool temp = true;
	if(!lock)
	{
		percent = x;
		recalcAmount();
	}
	else
		temp = false;
	return temp;
}
bool statModifier::clearModifier()
{
	bool temp = true;
	if(!lock)
	{
		enable = perm = false;
		search.clearStatSearch();
		percent = amount = num = 0.0;
	}
	else
		temp = false;
	return temp;
}
// Accessors
statSearch statModifier::getSearch()
{
	return search;
}
double statModifier::getPercent()
{
	return percent;
}
double statModifier::getPlusC()
{
	return plusC;
}
double statModifier::getStatVal()
{
	return statVal;
}
double statModifier::getTotal()
{
	return total;
}
bool statModifier::getLock()
{
	return lock;
}
bool statModifier::getPermanent()
{
	return perm;
}
bool statModifier::getEnable()
{
	return enable;
}
statModifier statModifier::operator=(statModifier m)
{
	search = m.search;
	percent = m.percent;
	amount = m.amount;
	num = m.num;
	enable = m.enable;
	perm = m.perm;
	lock = m.lock;
}
bool statModifier::operator==(statModifier m)
{
	bool temp;
	if(search != m.search)
		temp = false;
	else if(percent != m.percent)
		temp = false;
	else if(amount != m.amount)
		temp = false;
	else if(num != m.num)
		temp = false;
	else if(enable != m.enable)
		temp = false;
	else if (perm != m.perm)
		temp = false;
	else if(lock != m.lock)
		temp = false;
	else
		temp = true;
	return temp;
}
bool statModifier::operator!=(statModifier m)
{
	return !(*this == m);
}
