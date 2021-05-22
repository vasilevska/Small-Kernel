#ifndef _kernSem_h_
#define _kernSem_h_

class KernelSem {
	int value; //volatile?

public:
	KernelSem(int init) {

	}
	~KernelSem();
	int wait(Time maxTimeToWait);
	void signal();
	int val() const;
};

#endif // !_kernSem_h_
