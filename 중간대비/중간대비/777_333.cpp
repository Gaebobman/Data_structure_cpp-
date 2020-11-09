//### Correct Code ###
#include <iostream>
#include <string>
#include <vector>

using namespace std;


class Node {
public:
	Node(int X) {
		this->value = X;
		this->parent = NULL;
	}

	void setParent(Node* node) {
		this->parent = node;
	}

	void insertChild(Node* node) {
		this->chi_v.push_back(node);
	}

	void delChild(Node* node) {
		for (int i = 0; i < chi_v.size(); i++) {
			if (chi_v[i] == node) {
				chi_v.erase(chi_v.begin() + i);
				return;
			}
		}
	}

	int value;
	Node* parent;
	vector<Node*> chi_v;
};

class Tree {
public:
	Tree(int X) {
		this->root = new Node(X);
		node_list.push_back(root);
	}
	int size() {
		return node_list.size();
	}
	void insertNode(int par_data, int chi_data) {
		for (int i = 0; i < size(); i++) {
			if (node_list[i]->value == par_data) {
				Node* node = new Node(chi_data);
				node_list[i]->insertChild(node);
				node->setParent(node_list[i]);
				node_list.push_back(node);
				return;
			}
		}
	}
	void potrv(Node* n) {

		if (n == NULL) {
			cout << endl;
			return;
		}

		for (int i = 0; i < n->chi_v.size(); i++)
		{
			potrv(n->chi_v[i]);

		}
		cout << n->value << " ";
	}

	Node* getRoot() {
		return this->root;
	}

private:
	Node* root;
	vector <Node*> node_list;

};

int main() {

	int N, M;
	cin >> N;

	while (N--) {
		cin >> M;
		Tree T(1);

		while (M--) {
			int X, Y;
			cin >> X >> Y;
			T.insertNode(X, Y);
		}

		T.potrv(T.getRoot());

	}
}