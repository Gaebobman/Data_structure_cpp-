// ### Correct Code ###
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


class stack {
public:
	stack() {
		this->head = NULL;
	}

	void addFront(int X) {
		Node* a = new Node(X);
		a->next = head;
		this->head = a;
	}

	int removeFront() {
		Node* curr = this->head;
		Node* nxt = curr->next;
		int tmp = curr->element;
		delete curr;
		this->head = nxt;
		return tmp;
	}

private:
	Node* head;
};

bool isint(char ch) {
	if (ch - '0' >= 0 && ch - '0' <= 9)
		return 1;
	else return 0;
}
int main() {
	int N;
	stack L;
	string arg;
	cin >> N;

	while (N--) {
		cin >> arg;
		for (int i = 0; i < arg.size(); i++) {
			if (isint(arg[i])) { //숫자일 경우
				L.addFront(arg[i] - '0');
			}
			else {				// 연산자일 경우
				int a2 = L.removeFront();
				int a1 = L.removeFront();

				switch (arg[i])
				{
				case '+':
					L.addFront(a1 + a2);
					break;
				case '-':
					L.addFront(a1 - a2);
					break;
				case '*':
					L.addFront(a1 * a2);
					break;
				}
			}
		}
		cout << L.removeFront() << endl;
	}

	return 0;
}