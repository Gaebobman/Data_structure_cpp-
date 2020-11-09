// ### Correct Code ###
#include <iostream>
#include <string>

using namespace std;

class arrstack {
public:
	arrstack(int capacity) {
		this->Stack = new int[10000];
		this->t = -1;
		this-> capacity = capacity;

		for (int i = 0; i < 10000; i++) {
			Stack[i] = 0;
		}
	}

	bool empty(){
		if (t == -1 )return 1;
		else return 0;
	}

	void top(){
		if (empty()) cout << -1 << endl;
		else
			cout << Stack[t] << endl;
	}

	void push(int X) { 
		if(t+1 >= capacity) Stack[t] = X;
		else {
			Stack[++t] = X;
		}
		
	
	}

	void pop() {
		if (empty()) cout << -1 << endl;
		else {
			cout << Stack[t--] << endl;
		}
	}

	void size() {
		cout << t + 1 << endl;
	}
private:
	int* Stack;
	int t;
	int capacity;
};


int main() {
	arrstack a(10000);
	int N;
	cin >> N;

	string command;
	while (N--) {
		cin >> command;

		if (command == "empty") {
			cout << a.empty() << endl;
		}
		else if (command == "top") {
			a.top();
		}
		else if (command == "push") {
			int X;
			cin >> X;
			a.push(X);
		}
		else if (command == "pop") {
			a.pop();
		}
		else if (command == "size") {
			a.size();
		}
	}
	return 0;
}