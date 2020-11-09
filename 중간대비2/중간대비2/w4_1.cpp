#include <iostream>
#include <string>

using namespace std;

class Node {
public:

	Node(int X)
	{
		this->elem = X;
		this->next = NULL;
	}

	int elem;
	Node* next;
};

class linked_Q {
public:
	linked_Q(int max) {
		this->head = NULL;
		this->tail = NULL;
		this-> Qsize = 0;
		this->capacity = max;
	}
	bool isEmpty() {
		return (Qsize == 0);
	}
	void front() {
		if (isEmpty()) cout << "Empty" << endl;
		else cout << head->elem << endl;
	}
	void rear() {
		 if(isEmpty())cout << "Empty" << endl;
		 else cout <<tail->elem << endl;
	}
	void enqueue(int X) {
		if (Qsize == capacity)
		{
			cout << "Full" << endl;
			return;
		}
		if (Qsize == 0) {
			Node* tmp = new Node(X);
			this->tail = tmp;
			this->head = tmp;
			Qsize++;
		}
		else {
			Node* tmp = new Node(X);
			this->tail->next = tmp;
			this->tail = tmp;
			Qsize++;
		}
	}

	void dequeue() {
		if (isEmpty()) cout << "Empty" << endl;
		else {
			Node* tmp = head;
			cout << tmp->elem << endl;
			this->head = tmp->next;
			delete tmp;
			Qsize--;
		}
	}
	
	void size() {
		cout << Qsize << endl;
		
	}

private:
	Node* head;
	Node* tail;
	int Qsize;
	int capacity;

};


int main() {

	int S, N;
	string com;
	cin >> S >> N;
	linked_Q Q(S);
	while (N--) {
		cin >> com;
		if (com == "enqueue") {
			int X;
			cin >> X;
			Q.enqueue(X);
		}
		else if (com == "dequeue") {
			Q.dequeue();
		}
		else if (com == "size") {
			Q.size();
		}
		else if (com == "isEmpty") {
			cout << Q.isEmpty() << endl;
		}
		else if (com == "front") {
			Q.front();
		}
		else if (com == "rear") {
			Q.rear();
		}

	
		
	}
}













