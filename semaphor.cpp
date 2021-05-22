#include "semaphor.h"

Semaphore::Semaphore(int init)
{
	myImpl = new KernelSem(this, init); //da li lock
}

Semaphore::~Semaphore()
{
	//lock
	delete myImpl;
}

int Semaphore::wait(Time maxTimeToWait)
{
	return myImpl->wait(maxTimeToWait);
}

void Semaphore::signal()
{
	return myImpl->signali();
}

int Semaphore::val() const
{
	return myImpl->val();
}
