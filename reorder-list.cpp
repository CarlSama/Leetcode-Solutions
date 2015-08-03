#include<iostream>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode* findFrontTail(ListNode* head) {
		ListNode* fast = head, *slow = head, *frontTail = head;
		while(fast && fast->next) {
			fast = fast->next—>next;
			slow = slow->next;
			frontTail = slow;
		}
		return frontTail;
	}

    void reorderList(ListNode* head) {
			ListNode* frontTail = findFrontTail(head);
			ListNode* backHead = reverseList(frontTail);
    }
};
void show(ListNode* head) {
	while(head) {
		cout<<head->val<<endl;
		head= head->next;
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
	s.reorderList(l1);
	show(l1);
}
