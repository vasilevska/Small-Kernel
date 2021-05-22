#ifndef _PCB_h_
#define _PCB_h_

#include "thread.h"

class PCB {

private:
	static ID curID;
	static PCB* running;

	ID myID;
	Time timeSlice;
	Time time;

	unsigned* stack;  							
	unsigned ss;     		   
	unsigned sp;				    
	unsigned bp;				
	
public:
	static ID getRunningId();
	static Thread* getThreadById(ID id);

	PCB(Thread* th, StackSize s, Time t);

	ID getID();
	void start();
	void waitToComplete();

	static ID fork();
	static void exit();
	static void waitForForkChildren();

	virtual Thread* clone() const;

	~PCB();

};

#endif // !_PCB_h_
