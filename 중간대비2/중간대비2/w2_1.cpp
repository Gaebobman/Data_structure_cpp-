#include <iostream>
#include <string>

using namespace std;

class arrlist {
public:
	arrlist() {
		A = new int[10000];
		for (int i = 0; i < 10000; i++) {
			A[i] = 0;
		}
	}

	void at(int i) {
		cout << A[i] << endl;
	}

	void set(int i, int x) {
		if (A[i] == 0)
		{
			cout << A[i] << endl;
			return;
		}
		else {
			A[i] = x;
			return;
		}
	}

	void add(int i, int X) {
		if (A[i] == 0) {
			for (int j = 0; j < 10000; j++) {
				if (A[j] == 0) {
					A[j] = X;
					return;
				}
			}
		}
		else {
			int tmp = 0;
			for (int j = i; j < 10000; j++) {
				tmp = A[j];
				A[j] = X;
				X = tmp;
				if (A[j + 1] == 0)
					return;
			}
		}
	}
private:
	int* A;
};

int main() {
	int M;
	string com;
	arrlist A;
	cin >> M;
	while (M--)
	{
	cin >> com;
	if (com == "at") {
		int i;
		cin >> i;
		A.at(i);
	}
	else if (com == "set") {
		int i, x;
		cin >> i >> x;
		A.set(i, x);
	}
	else if (com == "add") {
		int i, x;
		cin >> i >> x;
		A.add(i, x);
	}


	}
}