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

	/*void delNode(int par) {
		Node* nownode;
		Node* parnode;

		for (int i = 0; i < size(); i++) {
			if (nodelist[i]->elem == par) {
				nownode = nodelist[i];
				if (nownode == root) { return; }
				parnode = nownode->parent;
				for (int j = 0; j < nownode->chi_v.size(); j++) {
					parnode->insertChild(nownode->chi_v[j]);
					nownode->chi_v[j]->setParent(parnode);
				}
				parnode->delChild(nownode);
				nodelist.erase(nodelist.begin() + i);
			}
		}
		return;
	}
	void print(int X) {
		for (int i = 0; i < size(); i++) {
			if (nodelist[i]->elem == X) {
				if (nodelist[i]->chi_v.size() == 0) {
					cout << 0 << endl;
					return;
				}

				for (int j = 0; j < nodelist[i]->chi_v.size(); j++) {
					cout << nodelist[i]->chi_v[j]->elem << " ";
				}
				cout << endl;
				return;
			}
		}
	}*/

	void pre(Node* node) {
		if (!node) return;
		cout << node->elem << " ";
		for (int i = 0; i < node->chi_v.size(); i++) {
			
			pre(node->chi_v[i]);
		}
	}

	Node* getroot() { return this ->root; }
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
		T.pre(T.getroot());
		cout << endl;
	}
	
	
	return 0;
}