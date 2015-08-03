#include<iostream>
#include<vector>
#include<queue>

using namespace std;

class Stack {
	int idx = 0;
	queue<int> que[2];
public:
    // Push element x onto stack.
    void push(int x) {
		que[idx].push(x);
    }

    // Removes the element on top of the stack.
    void pop() {
		while(!que[idx].empty()) {
			int fr = que[idx].front();
			que[idx].pop();

			if(!que[idx].empty())
				que[1-idx].push( fr );
		}
		idx = 1 - idx;
    }

    // Get the top element.
    int top() {
		int fr = 0;
		while(!que[idx].empty()) {
			fr = que[idx].front();
			que[idx].pop();
			que[1-idx].push(fr);
		}
		idx = 1 - idx;
		return fr;
    }

    // Return whether the stack is empty.
    bool empty() {
		return que[idx].empty();
    }
};
int main() {
	test t;
	cout<<t.i<<endl;
}
