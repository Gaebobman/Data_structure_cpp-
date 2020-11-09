// ### correct code ###
#include <iostream>
#include <string>

using namespace std;

class Node {
public:
	Node(int X) {
		this->element = X;
		this->next = NULL;
	}
	int element;
	Node* next;
};

class Linked_Stack {
public:
	Linked_Stack() {
		this->t = NULL;
		this->sizeofstack = 0;
	}
	bool empty() {
		if (this->sizeofstack == 0) return 1;
		else return 0;
	}

	void top() {
		if (empty()){ 
			cout << -1 << endl;
		}
		else {
			cout << t->element << endl;
		}
	}
	void push(int X) {
		Node* top = new Node(X);
		top->next = t;
		this->t = top;
		sizeofstack++;
	}

	void pop() {
		if (empty()) cout << -1 << endl;
		else {
			Node* tmp = this->t;
			Node* nxt = tmp->next;
			int elem = tmp->element;
			this->t = nxt;
			delete tmp;
			sizeofstack--;

			cout << elem << endl;
		}
	}

	int size() {
		return sizeofstack;
	}
private:
	Node* t;
	int sizeofstack;
};


int main() {
	Linked_Stack S;
	int N;
	string com;
	cin >> N;

	while (N--) {

		cin >> com;

		if (com == "empty") {
			cout << S.empty() << endl;
		}
		else if(com == "top") {
			S.top();
		}
		else if(com == "push"){
			int X;
			cin >> X;
			S.push(X);
		}
		else if (com == "pop") {
			S.pop();
		}
		else if (com == "size") {
			cout << S.size() << endl;
		}
		
	}
	return 0;
}