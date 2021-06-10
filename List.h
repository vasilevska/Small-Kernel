#ifndef _List_h_
#define _List_h_

template <class T> class List {
private: 
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
	void addFront(T dat);
	void addBack(T dat);
	T removeFront(T dat);
	T removeBack(T dat);
	int count() { return n; }
	void deleteList();

};


#endif // !_List_h_

template<class T>
inline void List<T>::addFront(T dat)
{
	if (!n) {
		front = back = new Node(dat, nullptr, nullptr);
	}
	else {
		front = new Node(dat, front, nullptr);
		front->next->prev = front;
	}
	n++
}

template<class T>
inline void List<T>::addBack(T dat)
{
	if (!n) {
		front = back = new Node(dat, nullptr, nullptr);
	}
	else {
		back = new Node(dat, nullptr, back);
		back->prev->next = back;
	}
	n++;
}

template<class T>
inline T List<T>::removeFront(T dat)
{
	if (!n) return nullptr;
	Node* cur = front;
	n--;
	front = front->next;
	if (!n) back = nullptr;
	else front->prev = nullptr;
	
	T dat = cur->data;
	delete cur;
	return dat;
}

template<class T>
inline T List<T>::removeBack(T dat)
{
	if (!n) return nullptr;
	Node* cur = back;
	n--;
	back = back->prev;
	if (!n) front = nullptr;
	else back->next = nullptr;
	T dat = cur->data;
	delete cur;
	return dat;
}

template<class T>
inline void List<T>::deleteList()
{
	if (!n) return;
	else {
		Node* cur = front;
		for (int i = 0; i < n; i++) {
			Node* tmp = cur;
			cur = cur->next;
			delete tmp;
		}
		front = back = nullptr;
		n = 0;
	}
}

