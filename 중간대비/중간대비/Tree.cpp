#include <iostream>
#include <vector>

using namespace std;

class Node {
public:
	Node(int X){
		elem = X;
		par = NULL;
		left = NULL;
		right = NULL;
	}

	void setP(Node* p) {
		this->par = p;
	}


	void setL(Node* p) {
		this->left = p;

	}

	void setR(Node* p) {
		this->right = p;
	}

	int elem;
	Node* par;
	Node* left;
	Node* right;

};

class Tree {
public:
	Node* root;
	vector<Node*> list;

	Tree(int X) {
		Node* a = new Node(X);
		root = a;
		list.push_back(a);
	}
	Node* getroot() {
		return root;
	}
	void insert(int p, int l, int r) {
		
		for (int i = 0; i < list.size(); i++) {
			if (list[i]->elem == p) {
				Node* l_ = new Node(l);
				Node* r_ = new Node(r);
				list[i]->setL(l_);
				list[i]->setR(r_);
				l_->setP(list[i]);
				r_->setP(list[i]);

				list.push_back(l_);
				list.push_back(r_);
			}
		}
	}

	//18년도 6번
	int getcount(Node* node) {
		int count = 0;
		if (node != NULL) {

			return (1 + getcount(node->left) + getcount(node->right));

		}
		return count;
	}

	//18년도 7번
	int getheight(Node* node) {
		int height = 0;
		if (node != NULL) {
			
			
			int lheight = getheight(node->left);
			int rheight = getheight(node->right);

			if (node == root) {
				height = ( (lheight > rheight ? lheight : rheight));
			}else
			height = (1 + (lheight > rheight ? lheight : rheight));
			
		}
		return height;


	}

};


int main() {
	Tree T(1);
	
		T.insert(1, 2, 3);
		T.insert(2, 4, 5);
		T.insert(5, 6, 7);
		T.insert(3, 8, 9);
		//T.insert(6, 10, 11);
	
		//T.insert(1, 2, 3);
		
	cout << T.getheight(T.getroot()) << endl;
}