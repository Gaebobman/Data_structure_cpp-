#include <iostream>
#include <string>

using namespace std;
int compare(int a, int b);

class arrQ {
public:
	arrQ(int NumofCard) {
		this->Q = new int[NumofCard];
		this->f = 0;
		this->r = -1;

	}

	void enqueue(int X) {
		r = (r + 1);
		Q[r] = X;
	}
	int dequeue() {
		f = (f + 1);
		return Q[f - 1];
	}
	void addFront(int X) {
		f = f - 1;
		Q[f] = X;
	}
	int front() {
		return Q[f];
	}
private:
	int* Q;
	int f;
	int r;
	int capacity;
};

int main() {
	int T, N;
	cin >> T;
	while (T--) {
		cin >> N;
		arrQ p1(N);
		arrQ p2(N);
		int score1 = 0;
		int score2 = 0;
		for (int i = 0; i < N; i++) {
			int X;
			cin >> X;
			p1.enqueue(X);
		}
		for (int i = 0; i < N; i++) {
			int X;
			cin >> X;
			p2.enqueue(X);
		}

		while (N--) {
			int num1 = p1.dequeue();
			int num2 = p2.dequeue();
			int tmp = 0;
			switch (compare(num1, num2))
			{
			case 1:
				score1++;
				tmp = p2.dequeue() + num1 - num2 - 1;
				p2.addFront(tmp);
				break;
			case 2:
				score2++;
				tmp = p1.dequeue() + num2 - num1 - 1;
				p1.addFront(tmp);
				break;
			case 3:
				break;
			}
		}

		cout << compare(score1, score2) << endl;


	}
	return 0;
}

int compare(int a, int b) {
	if (a > b)
		return 1;
	if (a < b)
		return 2;
	if (a == b)
		return 0;
}