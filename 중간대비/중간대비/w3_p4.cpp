#include <iostream>
#include <string>

using namespace std;

bool isOper(char item);
bool isNum(char item);
int getOper_order(char op);
int compareOper(char op1, char op2);

class Node {
public:
	Node(char X) {
		this->prev = NULL;
		this->element = X;
	}
	Node* prev;
	char element;
};

class stack {
public:
	stack() {
		this->t = NULL;
	}

	void push(char X) {
		Node* nxt = new Node(X);
		nxt->prev = this->t;
		this->t = nxt;
	}

	char pop() {
		if (this->t != NULL) {
			Node* crt = this->t;
			Node* nxt = this->t->prev;
			char tmp = crt->element;
			delete crt;
			return tmp;
		}
	}
private:
	Node* t;
	
};


int main() {
	int N;
	string arg;

	cin >> N;

	while (N--) {
		cin >> arg;
		
		for (int i = 0; i < arg.size(); i++) {

		}
	}

}



bool isOper(char item) {
	if (item == '+' || item == '-' || item == '*') {
		return true;
	}
	else return false;
}

bool isNum(char item) {
	int i;
	if (typeid(item - '0') == typeid(int)) {
		return true;
	}
	else return false;
}

int getOper_order(char op)
{
	switch (op) {
	case '*':
		return 2;
	case'+':
		return 1;
	case'-':
		return 1;
	}
}

int compareOper(char op1, char op2) {

	int op1Prec = getOper_order(op1);
	int op2Prec = getOper_order(op2);

	if (op1Prec > op2Prec)
		return 1;
	else if (op1Prec < op2Prec)
		return -1;
	else
		return 0;

}










