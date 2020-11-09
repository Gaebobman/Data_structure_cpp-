#include <iostream>
#include <string>

using namespace std;

class Node {
public:
	Node(int i) {
		this->elem = i;
		this->next = NULL;
	}

	int elem;
	Node* next;
};


class S_linked {
public:
	S_linked() {
		this->head = NULL;
	}
	bool empty() {
		return (head == NULL);
	}
	void addFront(int X) {
		Node* A = new Node(X);
		A->next = head;
		this->head = A;
	}
	void removeFront() {
		if (empty()) cout << -1 << endl;
		else {
			Node* node = this->head;
			cout << head->elem << endl;
			this->head = node->next;
			delete node;
		}
	}
	void front() {
		if (empty()) cout << -1 << endl;
		else cout << head->elem << endl;
	}
private:
	Node* head;
};

int main() {

	int N;
	string com;
	S_linked S;
	cin >> N;
	while (N--) {
		cin >> com;
		if (com == "addFront") {
			int X;
			cin >> X;
			S.addFront(X);
		}
		else if (com == "removeFront") {
			S.removeFront();
		}
		else if (com == "front") {
			S.front();
		}
		else if (com == "empty") {
			cout << S.empty() << endl;
		}
	}
	return 0;
}