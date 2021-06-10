#include "PCB.h"

ID PCB::getRunningId()
{
	return running->getID();
}

Thread* PCB::getThreadById(ID id)
{			//LOCK OVDE

}

ID PCB::getID()
{
	return myID;
}

Thread* PCB::getThread()
{
	return thread;
}
