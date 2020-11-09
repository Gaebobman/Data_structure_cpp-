// ### Correct Code ###

#include <iostream>
#include <string>

using namespace std;

class Array{
public:
	Array() {
		for (int i = 0; i < 10001; i++) { 
			arr[i] = 0; 
		}
	}

	void at(int idx) {cout << arr[idx] << endl;}

	void set(int idx, int X) { 
		if (arr[idx] == 0) cout << arr[idx] << endl;
		else {
			arr[idx] = X;
		}
	}
	
	void add(int idx, int X) {
		if (arr[idx] == 0) {
			for (int i = 0; i < idx; i++) {
				if (arr[i] == 0) {
					arr[i] = X;
					break;
				}
			}
		}
		else {
			int tmp=0;
			for (int i = idx; i < 10001; i++) {
				tmp = arr[i];
				arr[i] = X;
				X = tmp;
			}
		}
	}
private:
	int arr[10001];
	
};

int main() {
	Array a;
	int M;
	cin >> M;
	string command;
	while (M--) {
		cin >> command;

		if (command == "at") {
			int i;
			cin >> i;
			a.at(i);
		}
		else if (command == "set") {
			int i, X;
			cin >> i >> X;
			a.set(i, X);
		}
		else if (command == "add") {
			int i, X;
			cin >> i >> X;
			a.add(i, X);
		}
	}
}