#include "thread.h"
#include "PCB.h"


void Thread::start()
{
	myPCB->start();
}

void Thread::waitToComplete()
{
	myPCB->waitToComplete();
}

Thread::~Thread()
{
	waitToComplete();
	//lock
	delete myPCB;
}

ID Thread::getID()
{
	return myPCB->getID();
}

ID Thread::getRunningId()
{
	return PCB::getRunningId();
}

Thread* Thread::getThreadById(ID id)
{
	return PCB::getThreadById(id);
}

Thread::Thread(StackSize stackSize, Time timeSlice)
{
	//dodaj lock okolo mozda
	myPCB = new PCB(this, stackSize, timeSlice);
}
