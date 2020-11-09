//### Correct Code ###
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Node {
public:
	Node(int X) {
		this->par = NULL;
		this->element = X;
	}

	void setParent(Node* par_) {
		this->par = par_;
	}

	void insertChild(Node* chi) {
		this->chi_v.push_back(chi);
	}

	void delChild(Node* chi) {
		for (int i = 0; i < chi_v.size(); i++) {
			if (this->chi_v[i] == chi) {
				this->chi_v.erase(chi_v.begin() + i);
			}
		}
	}
	Node* par;
	int element;
	vector<Node*> chi_v;
};

class Tree {
public:
	Tree(int X) {
		root = new Node(X);
		node_list.push_back(root);
	}

	int size() {
		return node_list.size();
	}

	void insert(int par, int child) {
		for (int i = 0; i < size(); i++) {
			if (par == node_list[i]->element) {
				Node* node = new Node(child);
				node->setParent(node_list[i]);
				node_list[i]->insertChild(node);
				node_list.push_back(node);
				return;
			}
		}
		
	}
	void pre(Node* node) {
		if (!node ) return;

		cout << node->element << " ";
		for (int i = 0; i < node->chi_v.size(); i++) {
			pre(node->chi_v[i]);
		}
	}
	Node* getRoot() {
		return root;
	}
private:
	Node* root;
	vector<Node*> node_list;
};

int main() {
	
	int N ,M;
	cin >> N;

	while (N--) {
		cin >> M;
		Tree T(1);

		while (M--) {
			int X, Y;
			cin >> X >> Y;
			T.insert(X, Y);
		}

		T.pre(T.getRoot());

	}
}