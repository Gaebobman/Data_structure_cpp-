#include <iostream>
#include <string>

using namespace std;


class SequenceList {
private:
	struct Node {
		int e;
		Node* prev;
		Node* next;
	};

public:
	class Iterator {
	private:
		Node* v;
		Iterator(Node* u);
	public:
		int& operator*();
		bool operator==(const Iterator& p) const;
		bool operator!=(const Iterator& p) const;
		Iterator& operator++();
		Iterator& operator--();

		friend class SequenceList;
	};

private:
	int n;
	Node* header;
	Node* trailer;
public:
	SequenceList();
	int size() const;
	bool empty() const;
	Iterator begin() const;
	Iterator end() const;
	void insertFront(const int& e);
	void insertBack(const int& e);
	void insert(const Iterator& p, const int& e);
	void eraseFront();
	void eraseBack();
	void erase(const Iterator& p);

	Iterator atIndex(int i) const;
	int indexOf(const Iterator& p)const;
};

SequenceList::SequenceList() {
	n = 0;
	header = new Node;
	trailer = new Node;
	header->next = trailer;
	trailer->prev = header;
}

void SequenceList::insert(const SequenceList::Iterator& p, const int& e) {

	Node* w = p.v;
	Node* u = w->prev;
	Node* v = new Node;
	v->e = e;
	v->next = w; w->prev = v;
	v->prev = u; u->next = v;
	this->n++;
}

void SequenceList::insertFront(const int& e) {

	insert(begin(), e);
}

void SequenceList::insertBack(const int& e) {
	insert(end(), e);
}

void SequenceList::erase(const Iterator& p) {

	Node* v = p.v;
	Node* w = v->next;
	Node* u = v->prev;
	u->next = w; w->prev = u;
	delete v;
	this->n--;
}

void SequenceList::eraseFront()
{
	erase(begin());
}

void SequenceList::eraseBack() {
	erase(--end());
}

int SequenceList::size() const {
	return n;
}

bool SequenceList::empty() const {
	return(n == 0);
}

SequenceList::Iterator::Iterator(Node* u) {

	v = u;
}

SequenceList::Iterator SequenceList::begin() const {

	return Iterator(header->next);
}

SequenceList::Iterator SequenceList::end() const {

	return Iterator(trailer);
}

int& SequenceList::Iterator::operator*() {

	return v->e;
}

bool SequenceList::Iterator::operator==(const Iterator& p) const {

	return v == p.v;
}

bool SequenceList::Iterator::operator!=(const Iterator& p) const {

	return v != p.v;
}

SequenceList::Iterator& SequenceList::Iterator::operator++() {

	v = v->next;
	return *this;
}

SequenceList::Iterator& SequenceList::Iterator::operator--() {

	v = v->prev;
	return *this;
}

SequenceList::Iterator SequenceList::atIndex(int i) const {
	Iterator p = begin();
	for (int j = 0; j < i; j++) {
		++p;
	}
	return p;
}

int SequenceList::indexOf(const Iterator& p) const {

	Iterator q = begin();
	int j = 0;

	while (q != p) {
		++q;
		++j;
	}
	return j;
}


int main() {

	int T;
	cin >> T;

	SequenceList sl;
	SequenceList::Iterator iter = sl.begin();

	for (int i = 0; i < T; i++) {
		string oper;
		cin >> oper;

		if (oper == "insert") {
			int X;
			cin >> X;
			sl.insert(iter, X);
		}
		else if (oper == "erase") {
			if (sl.empty()) {
				cout << "Empty" << endl;
			}
			else sl.erase(iter);
		}
		else if (oper == "begin") {
			iter = sl.begin();
		}
		else if (oper == "end") {
			iter = sl.end();
		}
		else if (oper == "++") {
			++iter;
		}
		else if (oper == "--") {
			--iter;
		}
		else if (oper == "print") {
			if (sl.empty())
			{
				cout << "Empty" << endl;
			}
			else
			{

				for (int i = 0; i < sl.size(); i++) {
					cout << *sl.atIndex(i) << " ";
				}
				cout << endl;
			}
		}
		else if (oper == "size") {
			cout << sl.size() << endl;
		}
		else {
			cout << "Your command is wrong, try again." << endl;
		}
	}
	return 0;
}