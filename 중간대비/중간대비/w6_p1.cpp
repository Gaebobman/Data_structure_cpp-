//### Correct Code ###
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Node {
public:
	int element;
	Node* parent;
	vector <Node*>chi_v;
	Node(int X) {
		element = X;
		parent = NULL;
	}

	void setParent(Node* node) {
		this->parent = node;
	}

	void insertChild(Node* child) {
		chi_v.push_back(child);
	}

	void delChild(Node* node) {
		for (int i = 0; i < chi_v.size(); i++) {
			if (chi_v[i] == node) {
				chi_v.erase(chi_v.begin() + i);
			}
		}
	}
};

class Tree {
public:
	Tree(int X) {
		root = new Node(X);
		node_list.push_back(root);
	}

	int size() { return node_list.size(); }

	void insertNode(int par, int chi) {

		for (int i = 0; i < size(); i++) {
			if (node_list[i]->element == par) {
				Node* ch_node = new Node(chi);

				ch_node->setParent(node_list[i]);
				node_list[i]->insertChild(ch_node);
				node_list.push_back(ch_node);
				return;

			}
		}
	}

	void delNode(int X) {
		Node* nownode;
		Node* par_;

		for (int i = 0; i < size(); i++) {
			if (node_list[i]->element == X) {
				nownode = node_list[i];
				if (nownode == root) { return; }
				par_ = nownode->parent;
				for (int j = 0; j < nownode->chi_v.size(); j++) {
					par_->insertChild(nownode->chi_v[j]);
					nownode->chi_v[j]->setParent(par_);
				}
				par_->delChild(nownode);
				node_list.erase(node_list.begin() + i);
				
			}
		}
		return;
	}

	void printChi(int X) {
		for (int i = 0; i < size(); i++) {
			if (node_list[i]->element == X) {
				if (node_list[i]->chi_v.size() == 0) {
					cout << 0 << endl;
					return;
				}

				for (int j = 0; j < node_list[i]->chi_v.size(); j++) {

					cout << node_list[i]->chi_v[j]->element << " ";
					
				}
				cout << endl;
				return;
				
			}
		}
		cout << 0 << endl;
	}
	void printSib(int X) {}


private:
	Node* root;
	vector <Node*> node_list;
};


int main() {
	int N;
	cin >> N;
	string com;
	Tree T(1);

	while (N--) {
		cin >> com;
		if (com == "insert") {
			int par, chi;
			cin >> par >> chi;
			T.insertNode(par, chi);
		}
		else if (com == "print" ) {
			int par;
			cin >> par;
			T.printChi(par);

		}
	
		else if (com == "delete") {
			int x;
			cin >> x;
			T.delNode(x);
		}
	}
	return 0;
}