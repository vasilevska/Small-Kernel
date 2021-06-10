#ifndef _PCB_h_
#define _PCB_h_

#include "thread.h"
#include "List.h"

class PCB {

private:
	static ID curID;
	static PCB* running;
	static List<PCB*> allPCBs;

	ID myID;
	Time timeSlice;
	Time time;
	Thread* thread;

	unsigned* stack;  							
	unsigned ss;     		   
	unsigned sp;				    
	unsigned bp;		

	PCB(ID idK);

	
public:
	static ID getRunningId();
	static Thread* getThreadById(ID id);


	PCB(Thread* th, StackSize s, Time t);

	ID getID();
	Thread* getThread();
	void start();
	void waitToComplete();

	static ID fork();
	static void exit();
	static void waitForForkChildren();

	virtual Thread* clone() const;

	 ~PCB();

};

#endif // !_PCB_h_
