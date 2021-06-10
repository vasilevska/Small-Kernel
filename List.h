#ifndef _List_h_
#define _List_h_
#include "iterator"

using namespace std;

template <class T> class List {
public:
	struct Node {
		T data;
		Node* next;
		Node* previous;
		Node(T d, Node* nn, Node* prev) {
			data = d;
			next = nn;
			previous = prev;
		}
	};

private:
	Node* front;
	Node* back;
	volatile int count;

public:
	List() {
		front = nullptr;
		back = nullptr;
		count = 0;
	}
	~List() {
		deleteList();
	}
	Node* getFront() { return front; }
	void addFront(T dat);
	void addBack(T dat);
	T removeFront(T dat);
	T removeBack(T dat);
	int count() { return count; }
	void deleteList();

	

};


#endif // !_List_h_

template<class T>
inline void List<T>::addFront(T dat)
{
	if (!count) {
		front = back = new Node(dat, nullptr, nullptr);
	}
	else {
		front = new Node(dat, front, nullptr);
		front->next->previous = front;
	}
	count++
}

template<class T>
inline void List<T>::addBack(T dat)
{
	if (!count) {
		front = back = new Node(dat, nullptr, nullptr);
	}
	else {
		back = new Node(dat, nullptr, back);
		back->previous->next = back;
	}
	count++;
}

template<class T>
inline T List<T>::removeFront(T dat)
{
	if (!count) return nullptr;
	Node* cur = front;
	count--;
	front = front->next;
	if (!count) back = nullptr;
	else front->previous = nullptr;
	
	T dat = cur->data;
	delete cur;
	return dat;
}

template<class T>
inline T List<T>::removeBack(T dat)
{
	if (!count) return nullptr;
	Node* cur = back;
	count--;
	back = back->previous;
	if (!count) front = nullptr;
	else back->next = nullptr;
	T dat = cur->data;
	delete cur;
	return dat;
}

template<class T>
inline void List<T>::deleteList()
{
	if (!count) return;
	else {
		Node* cur = front;
		for (int i = 0; i < count; i++) {
			Node* tmp = cur;
			cur = cur->next;
			delete tmp;
		}
		front = back = nullptr;
		count = 0;
	}
}

