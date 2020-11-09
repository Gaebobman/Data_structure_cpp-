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
	int recursivedepth(int X) {
		
		for (int i = 0; i < size(); i++) {
			if (node_list[i]->element == X) {
				
				if (node_list[i]->parent == NULL) {
					return 0;
				}
				else {
					return (recursivedepth(node_list[i]->parent->element) + 1);
				}
			}
		}
	}
	/*
	void depth(int X) {
		int N = 1;
		for (int i = 0; i < size(); i++) {
			if (node_list[i]->element == X) {
				if (node_list[i] == root) { 
					cout << 0 << endl; 
					return;
				}
				else {
					Node* node = node_list[i]->parent;
					while (node->parent != NULL) {
						node = node->parent;
						N++;
					}
					cout << N << endl;
				}
				

			}
		}
	}
	*/

private:
	Node* root;
	vector <Node*> node_list;
};


int main() {
	int N, M;
	int par, chi;
	cin >> N >> M;
	string com;
	Tree T(1);

	while (N--) {
		cin >> par >> chi;
		T.insertNode(par, chi);

		
	}

	while (M--) {
		int A;
		cin >> A;
		//T.depth(A);
		cout << T.recursivedepth(A) << endl;
	}
	return 0;
}