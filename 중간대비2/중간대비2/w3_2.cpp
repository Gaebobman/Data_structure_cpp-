#include <iostream>
#include <string>

using namespace std;

class Node {
public:
	Node(int X) {
		this->elem = X;
		this->next = NULL;
	}
	int elem;
	Node* next;
};

class list {
public:
	list() {
		this->head = NULL;
		this->tail = NULL;
		this->n = 0;
	}

	bool empty(){
		return (this->n == 0);
	}
	void top() {
		if (empty()) cout << -1 << endl;
		else {
			cout << this->head->elem << endl;
		}
	}
	void push(int X) {
		Node* A = new Node(X);
		A->next = this->head;
		this->head = A;
		n++;
	}
	void pop() {
		if (empty()) cout << -1 << endl;
		else {
			Node* tmp = head;
			cout << tmp->elem << endl;
			this->head = tmp->next;
			delete tmp;
			n--;
		}
		return;
	}
	void size() {
		cout << n << endl;
	}
private:
	Node* head;
	Node* tail;
	int n;
};


int main() {
	int N;
	string com;
	list L;
	
	cin >> N;
	while (N--) {
		cin >> com;
		if (com == "empty") {
			cout << L.empty() << endl;
		}
		else if (com == "top") {
			L.top();
		}
		else if (com == "push") {
			int X;
			cin >> X;
			L.push(X);
		}
		else if (com == "pop") {
			L.pop();
		}
		else if (com == "size") {
			L.size();
		}

	}
	
	return 0;
}















