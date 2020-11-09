// ### Correct Code ###
// f와 r의 연산을 잘 보자
// 메인에서 객체 생성 할 때 빈 칸 하나 추가해줬다.
#include <iostream>
#include <string>

using namespace std;

class arrQueue {
public:
	arrQueue(int capacity_) {
		this->Q = new int[capacity_];
		this->f = 0;
		this->r = -1;
		this->capacity = capacity_;
	
	}
	void enqueue(int X) {
		if (size() == capacity-1) cout << "Full" << endl;
		else {
			r = (r + 1) % capacity;
			Q[r] = X;
		}
	}

	void dequeue() {
		if (isEmpty()) cout << "Empty" << endl;
		else {
			cout << Q[f] << endl;
			Q[f] = 0;
			f = (f + 1) % capacity;
			
		}
	}
	int size() {
		return (r - f + 1 + capacity) % capacity;
	}

	bool isEmpty() {
		if ((r + 1) % capacity == f) return 1;
		else return 0;
	}

	void front() {
		if (isEmpty()) cout << "Empty" << endl;
		else {
			cout << Q[f] << endl;
		}
	}

	void rear() {
		if (isEmpty()) cout << "Empty" << endl;
		else {
			cout << Q[r] << endl;
		}
	}

private:
	int f;	//index of front element
	int r;	//index of rear 바로 다음 element
	int* Q;
	int capacity;
};



int main() {
	int S, N;
	string com;
	cin >> S >> N;
	arrQueue Q(S+1);
	while (N--) {
		cin >> com;
		if (com == "enqueue") {
			int X;
			cin >> X;
			Q.enqueue(X);
		}else if(com == "dequeue") {
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
}
