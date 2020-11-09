// ### Correct Code ###
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Node {
public:
	Node(int x)
	{
		elem = x;
		parent = NULL;
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
	Tree(int x) {
		root = new Node(x);
		nodelist.push_back(root);
	}
	int size() {
		return nodelist.size();
	}

	void insert(int par, int chi) {
		for (int i = 0; i < size(); i++)
		{
			if (nodelist[i]->elem == par) {
				Node* child = new Node(chi);
				nodelist[i]->insertChild(child);
				child->setParent(nodelist[i]);
				nodelist.push_back(child);
			}
		}
	}
	bool isExt(Node* node) {
		if (node->chi_v.size() == 0) return 1;
		else return 0;
	}
	bool isExtint(int idx) {
		for (int i = 0; i < size(); i++) {
			if (nodelist[i]->elem == idx) {
				if (nodelist[i]->chi_v.size()==0)
				{
					return 1;
				}
				else return 0;
			}
		}
	}
	
	/*void gozapodo(int par) {
	
		Node* goza =NULL;
		for (int i = 0; i < size(); i++) {
			if (nodelist[i]->elem == par) {
				goza = nodelist[i];

				for (int j = 0; j < goza->chi_v.size(); j++) {
					if (isExt(goza->chi_v[j]))
						cout << goza->chi_v[j]->elem << " ";
					else
						gozapodo(goza->chi_v[j]->elem);
					
				}
			}
		}
	}*/
	
	void sub(Node* R) {
		if (!R) return;
		
		if (R->chi_v.size() == 0) cout << R->elem<< " ";

		for (int i = 0; i < R->chi_v.size(); i++) {
			sub(R->chi_v[i]);
		}
	}

	Node* findPosition(int i) {
		for (int j = 0; nodelist.size(); j++) {
			if (nodelist[j]->elem == i) return nodelist[j];
		}
		return NULL;
	}

private:
	Node* root;
	vector <Node*> nodelist;
};

int main() {
	int N, M, R;
	cin >> N;
	while (N--) {
		Tree T(1);
		cin >> M>>R;
		while (M--) {
			int par, chi;
			cin >> par >> chi;
			T.insert(par, chi);
		}
		T.sub(T.findPosition(R));
		cout << endl;
		
	}
	return 0;
}












