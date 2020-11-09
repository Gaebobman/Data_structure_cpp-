#include <iostream>
#include <string>
/*
   0 1 2 3 4 5 6 7 8 9 
   & & & &     & & & &
	     r	   f

size = r - f + 1 + capacity % capacity

r= r+1 % cap

f = f+1 % capacity

*/
using namespace std;

class arrQ {
public:
	arrQ(int max) {
		Q = new int[max];
		this->f = 0;
		this->r = -1;
		this->capacity = max;
	}
	bool isEmpty() {
		return ((r + 1) % capacity == f);
	}
	int size() {
		return ((r - f + 1 + capacity) % capacity);
	}
	void enqueue(int X) {
		if (size() == capacity-1) cout << "Full" << endl;
		else{
			r = (r + 1 ) % capacity;
			Q[r] = X;
		}
	}
	void dequeue() {
		if (size() == 0) cout << "Empty" << endl;
		else {
			cout << Q[f] << endl;
			f = (f + 1 )% capacity;
			return;
		}
	}
	void front() {
		if (isEmpty()) cout << "Empty" << endl;
		else cout << Q[f] << endl;
	}
	void rear() {
		if (isEmpty()) cout << "Empty" << endl;
		else cout << Q[r] << endl;
	}
private:
	int* Q;
	int f;
	int r;
	int capacity;
};

int main() {
	int S, N;
	string com;
	cin >> S >> N;
	arrQ Q(S+1);
	while (N--) {
		cin >> com;

		if (com == "enqueue") {
			int X;
			cin >> X;
			Q.enqueue(X);
		}
		else if (com == "dequeue") {
			Q.dequeue();
		}
		else if (com == "size") {
			cout << Q.size() << endl;
		}
		else if (com == "isEmpty") {
			cout << Q.isEmpty() << endl;
		}
		else if (com == "front") {
			Q.front();
		}
		else if (com == "rear") {
			Q.rear();
		}

	}
	return 0;
}