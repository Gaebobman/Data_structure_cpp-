#include<iostream>
#include<string>
using namespace std;

template <typename E>
class Array_Stack {
public:
    E* Stack;
    int capacity;
    int t;

    Array_Stack(int capacity) {
        this->capacity = capacity;
        this->Stack = new E[capacity];
        this->t = -1;
    }

    int size() const {
        return this->t + 1;
    }

    bool empty() {
        return (t == -1);
    }

    E top() {
        if (t == -1) {
            return -1;
        }
        else {
            return Stack[t];
        }
    }

    void push(E e) {
    
           ++t;
           Stack[t] = e;
      

    }

    E pop() {
        if (t == -1) {
            return -1;
        }
        else {
            E x = Stack[t];
            --t;
            return x;
        }
    }

};

int getoper(char op) {
    switch (op)
    {
    case '*':
        return 5;
    case '+':
        return 3;
    case '-':
        return 3;
    case '$':
        return 1;
    }
}
int operation(int a, int b, char op) {
    switch (op)
    {
    case '*':
        return (a * b);
    case '+':
        return (a + b);
    case '-':
        return (a - b);
    }
}


int calPostfix(string exp) {
    Array_Stack<int> val(100);
    Array_Stack<char> op(100);
    string postfix = exp;
    int n = postfix.size();
    char testch = 'a';

    for (int i = 0; i < n; i++) {
        testch = exp.at(i);
        if (testch - '0' >= 0 && testch - '0' <= 9) {
            val.push(testch - '0');
        }
        else if (testch == '*' || testch == '+' || testch == '-') {
            while (val.size() > 1 && getoper(testch) <= getoper(op.top())) {
                int x = val.pop();
                int y = val.pop();
                char oper = op.pop();
                int k = operation(y, x, oper);
                val.push(k);
            }
            op.push(testch);
        }


    }
    char dollar = '$';
    while (val.size() > 1 && getoper(dollar) <= getoper(op.top())) {
        int x = val.pop();
        int y = val.pop();
        char oper = op.pop();
        int k = operation(y, x, oper);
        val.push(k);
    }

    return val.top();
}

int main() {
    int N = 0;
    string operate;
    cin >> N;
    while (N--) {
        cin >> operate;
        cout << calPostfix(operate) << endl;
    }
    return 0;
}