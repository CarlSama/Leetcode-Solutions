#include<iostream>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};
 
class Solution {
public:
	ListNode* reverse(ListNode* head, ListNode* newNext) {
		if(head == 0)	return 0;
		ListNode* next = head->next;
		head->next = newNext;
		return reverse(next,head);
	}

    ListNode* reverseList(ListNode* head) {
		return reverse(head,0);
    }
};

int main() {
	ListNode* l0 = new ListNode(0);
	ListNode* l1 = new ListNode(1);
	ListNode* l2 = new ListNode(2);
	l0->next = l1;
	l1->next = l2;

	Solution s;
	l0 = s.reverseList(l3);
	while(l0) {
		cout<<l0->val<<endl;
		l0 = l0->next;
	}
}
