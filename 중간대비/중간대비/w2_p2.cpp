// ### Correct Code ###
#include <iostream>
#include <string>

using namespace std;


class Node {
public:
	Node(int X) {
		value = X;
		next = NULL;
	}
	int value;
	Node* next;
};

class stack {

public:
	stack() {
		this->head = NULL;
		this->tail = NULL;
	}
	bool empty() {
		if (head == NULL && tail == NULL) return 1;
		else return 0;
	}
	void addFront(int X) {
		
			Node* a = new Node(X);
			a->next = this->head;
			this->head = a;
		
	}
	void removeFront() {
		if (empty()) cout << -1 << endl;
		else {
			int tmp = head->value;
			Node* nxthead = head->next;
			this->head = nxthead;
			cout << tmp << endl;
		}
	}
	void front() {
		if (empty()) cout << -1 << endl;
		else cout << head->value << endl;
	}


private:
	Node* head; 
	Node* tail;

};

int main() {
	stack L;
	int N;
	cin >> N;
	string command;

	while (N--) {
		cin >> command;
		if (command == "addFront") {
			int X;
			cin >> X;
			L.addFront(X);
		}
		else if (command == "removeFront") {
			L.removeFront();
		}
		else if (command == "front") {
			L.front();
		}
		else if (command == "empty")	{
			cout << L.empty() << endl;
		}
	}

	return 0;
}