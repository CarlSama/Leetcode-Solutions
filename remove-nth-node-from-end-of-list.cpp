#include<iostream>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
		ListNode* newHead = new ListNode(0);
		newHead->next = head;

		ListNode* slow = newHead, *fast = newHead;
		while(n--)
			fast = fast->next;

		while(fast->next) {
			fast = fast->next;
			slow = slow->next;
		}

		ListNode* toBeDelete = slow->next;
		slow->next = toBeDelete->next;
		delete toBeDelete;

		return newHead->next;
	}
};

void show(ListNode* head) {
	while(head) {
		cout<<head->val<<endl;
		head = head->next;
	}
}
int main() {
	ListNode* l1 = new ListNode(1);
	ListNode* l2 = new ListNode(2);
	ListNode* l3 = new ListNode(3);
	ListNode* l4 = new ListNode(4);
	l1->next = l2;
	l2->next = l3;
	l3->next = l4;

	Solution s;
	show(s.removeNthFromEnd(l1,4));
}
