#include <iostream>
#include <string>
using namespace std;
bool isOper(char item);
bool isNum(char item);
int getOper_order(char op);
int compareOper(char op1, char op2);

class arrStack {
public:
	arrStack() {
		S = new int[101];
		t = -1;
	}

	bool empty() {
		return (t == -1);
	}

	void push(char X) {
		t = t + 1;
		S[t] = X;
	}

	int pop() {

		return S[t--];

	}

private:
	int* S;
	int t;

};

int main() {
	int N;
	string arg;
	arrStack S;
	cin >> N;
	while (N--) {
		cin >> arg;

		for (int i = 0; i < arg.size(); i++) {
			if (isNum(arg[i])) {
				S.push(arg[i]);
			}
			else if (arg[i] = '(') {	 // 5개가 한 세트
				i++;
				S.push(arg[i]);
				i = i + 2;
				S.push(arg[i]);
				i = i - 1;
				S.push(arg[i]);
				i = i + 2;
			}
			else if (isOper(arg[i]))
			{
				
			}
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

int getOper_order(char op) {
	switch (op) 
	{
	case '*':
		return 2;
	case '+':
		return 1;
	case '-':
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