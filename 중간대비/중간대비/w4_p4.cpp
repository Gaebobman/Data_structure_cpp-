// ### Correct Code ###
// 다시 풀어봐라 긁어온거다.
#include <iostream>
#include <string>

using namespace std;
int bigyo(int, int);

class Queue {

public:
	Queue(int card) :f(0), r(-1), capacity(card) {
		Q = new int[card];
		for (int i = 0; i < card; i++) { Q[i] = 0; }
	}

	int size() {
		return (r - f + 1 + capacity) % capacity;
	}

	bool empty() {
		if ((r + 1) % capacity == f) return true;
		else return false;
	}

	void enqueue(int element) {
		if (size() == capacity - 1) {
			cout << "FULL" << endl;
		}
		else {
			r = (r + 1) % capacity;
			Q[r] = element;
		}
	}

	int dequeue() {
		if (empty()) {
			return -1;
		}
		else {
			int tmp = Q[f];
			Q[f] = 0;
			f = (f + 1) % capacity;
			return tmp;
		}
	}

	void addFront(int element) {
		f--;
		Q[f] = element;



	}

private:
	int f;
	int r;
	int capacity;
	int* Q;
};

int main() {
	int T;
	cin >> T;

	while (T--) {
		int N;
		int p1_score = 0;
		int p2_score = 0;
		cin >> N;

		Queue P1(N + 1);
		Queue P2(N + 1);

		for (int i = 0; i < N; i++) {
			int tmp;
			cin >> tmp;
			P1.enqueue(tmp);
		}

		for (int i = 0; i < N; i++) {
			int tmp;
			cin >> tmp;
			P2.enqueue(tmp);
		} // setting cards
	// N번동안 1. 뽑아서 2. 둘이 비교하고 3. 빼서 4. 돌려줘 5. 점수기록
		while (N--) {

			int p1_tmp = 0;
			int p2_tmp = 0;

			p1_tmp = P1.dequeue();
			p2_tmp = P2.dequeue(); // 1. 뽑아서

			switch (bigyo(p1_tmp, p2_tmp)) {//2. 비교하고
			case 0:
				break;
			case 1:
			{
				int tmp = P2.dequeue() + p1_tmp - p2_tmp - 1; // 3
				P2.addFront(tmp); //4
				p1_score++;//5
			}
			break;
			case 2: {
				int tmp = P1.dequeue() + p2_tmp - p1_tmp - 1; //3 
				P1.addFront(tmp); //4
				p2_score++;//5



			}
				  break;
			}
		}

		cout << bigyo(p1_score, p2_score) << endl;
	}
	return 0;
}

int bigyo(int a, int b) {
	if (a == b) {
		return 0;
	}
	else if (a > b) {
		return 1;
	}
	else if (a < b) {
		return 2;
	}
}