#include<iostream>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    void deleteNode(ListNode* node) {
		node->val = node->next->val;

		ListNode* newNext = node->next->next;
		delete node->next;

		node->next = newNext;
    }
};

int main() {
}
