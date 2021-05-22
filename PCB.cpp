#include "PCB.h"

ID PCB::getRunningId()
{
	return running->getID();
}

ID PCB::getID()
{
	return myID;
}
