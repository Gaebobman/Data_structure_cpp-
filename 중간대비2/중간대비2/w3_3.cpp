#include <iostream>
#include <string>
using namespace std;

class arrStack {
public:
	arrStack() {
		S = new int[101];
		t = -1;
	}

	bool empty() {
		return (t == -1);
	}

	void push(int X) {
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
			if (0 <= arg[i] - '0' && 9 >= arg[i] - '0')
			{
				S.push(arg[i] - '0');
			}
			else {
				int a = S.pop();
				int b = S.pop();

				switch (arg[i])
				{
				case'+': S.push(a + b);
					break;
				case'-': S.push(b - a);
					break;
				case'*': S.push(a * b);
					break;
				}
			}
			
		}
		cout << S.pop() << endl;
	}
}