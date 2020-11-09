#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Node {
public:
	Node(int X) {
		this->parent = NULL;
		this->elem = X;
	}

	void setParent(Node* node) {
		this->parent = node;
	}

	void insertChild(Node* node) {
		chi_v.push_back(node);
	}
	void delChild(Node* node) {
		for (int i = 0; i < chi_v.size(); i++) {
			if (chi_v[i] == node) {
				chi_v.erase(chi_v.begin() + i);
			}
		}
	}

	int elem;
	Node* parent;
	vector <Node*> chi_v;
};

class Tree {
public:
	Tree(int X) {
		this->root = new Node(X);
		nodelist.push_back(root);
	}
	int size() {
		return nodelist.size();
	}
	void insertNode(int pardata, int chidata) {

		for (int i = 0; i < size(); i++) {
			if (nodelist[i]->elem == pardata) {
				Node* tmp = new Node(chidata);

				tmp->setParent(nodelist[i]);
				nodelist[i]->insertChild(tmp);
				nodelist.push_back(tmp);
				return;
			}
		}
	}
	void myfunc(Node* node,int cnt) {
		if (!node)return;

		if (node->chi_v.size() == 0)
			cout << cnt << " ";
		for (int i = 0; i < node->chi_v.size(); i++) {
			cnt += 1;
			myfunc(node->chi_v[i], cnt);
			cnt = 0;
		}
	}
	Node* getroot() { return this->root; }
private:
	Node* root;
	vector <Node*> nodelist;
};

int main() {
	int N, M;
	cin >> N;
	string com;
	while (N--) {
		cin >> M;
		Tree T(1);
		while (M--) {


			int par, chi;
			cin >> par >> chi;
			T.insertNode(par, chi);

		}
		T.myfunc(T.getroot(), 1);
		cout << endl;
	}


	return 0;
}