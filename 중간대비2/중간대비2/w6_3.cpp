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

	void delNode(int par) {
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
	/*void printchild(int X) {
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
	}
	*/
	/*void printsib(int X) {
		for (int i = 0; i < size(); i++) {

			if (nodelist[i]->elem == X) {

				if (nodelist[i] == root) {
					cout << root->elem << endl;
					return;
				}
				Node* par_ = nodelist[i]->parent;

				for (int j = 0; j < par_->chi_v.size(); j++) {
					cout << par_->chi_v[j]->elem << " ";
				}
				cout << endl;
				return;
			}

		}
		cout << 0 << endl;
	}
	*/
	void depth(int X) {
		Node* node=NULL;
		int dep = 0;
		for (int i = 0; i < size(); i++) {
			if (nodelist[i]->elem == X) {
				node = nodelist[i];
				break;
			}
		}
		while (node != root) {
			node = node->parent;
			dep++;
		}
		cout << dep << endl;
	}
private:
	Node* root;
	vector <Node*> nodelist;
};

int main() {
	int N, M;
	cin >> N>> M;
	string com;
	Tree T(1);
	while (N--) {
		int par, chi;
		cin >> par >> chi;
		T.insertNode(par, chi);
	}
	while (M--) {
		int X;
		cin >> X;
		T.depth(X);
	}
	
	return 0;
}