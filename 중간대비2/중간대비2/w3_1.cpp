#include <iostream>
#include <string>
using namespace std;

class arrStack {
public:
	arrStack() {
		S = new int[10000];
		t = -1;
	}
	
	bool empty() {
		return (t == -1);
	}

	void top() {
		if (empty()) cout << -1 << endl;
		else {
			cout << S[t] << endl;
		}
	}

	void push(int X) {
		t = t + 1;
		S[t] = X;
	}

	void pop() {
		if (empty()) cout << -1 << endl;
		else {
			cout << S[t] << endl;
			t--;
		}
	}
	void size() {
		cout << t + 1 << endl;
	}
private:
	int* S;
	int t;
	
};

int main() {
	int N;
	string com;
	arrStack A;
	cin >> N;

	while (N--)
	{
		cin >> com;
		if (com == "empty") {
			cout << A.empty() << endl;
		}
		else if (com == "top") {
			A.top();
		}
		else if (com == "push") {
			int X;
			cin >> X;
			A.push(X);
		}
		else if (com =="pop") {
			A.pop();
		}
		else if (com == "size") {
			A.size();
		}


	}
	return 0;
}