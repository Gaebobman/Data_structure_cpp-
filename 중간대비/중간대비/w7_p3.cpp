#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Node {
public:
	Node(int x) {
		this->elem = x;
		this->parent = NULL;
	}

	void setParent(Node* n) {
		this->parent = n;
	}
	
	void insertChild(Node* n) {
		chi_v.push_back(n);
	}

	void delChild(Node* n) {
		for (int i = 0; i < chi_v.size(); i++) {
			if (n == chi_v[i])
			{
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
	Tree(int x) {
		this->root = new Node(x);
		node_list.push_back(root);
	}

	int size() { return node_list.size();}

	void insertNode(int par_, int chi_) {
		for (int i = 0; i < size(); i++) {
			if (node_list[i]->elem == par_) {
				Node* child = new Node(chi_);
				child->setParent(node_list[i]);
				node_list[i]->insertChild(child);
				node_list.push_back(child);
			}
		}
	}

	void call(Node* node, int cnt) {

		if (!node) return;

		if (node->chi_v.size() == 0)
			cout << cnt << " ";

		for (int i = 0; i < node->chi_v.size(); i++) {
			cnt += 1;
			call(node->chi_v[i], cnt);
			cnt = 0;
		}
	}

	Node* getroot() { return this->root; }
private:
	Node* root;
	vector<Node*> node_list;
};

int main() {
	int N,M;
	cin >> N;
	while (N--) {
		cin >> M;
		Tree T(1);
		while (M--) {
			int par, chi;
			cin >> par>> chi;
			T.insertNode(par, chi);
		}
		T.call(T.getroot(),1);
	}
}