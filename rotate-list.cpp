#include<iostream>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};
 
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
		if(head==0)	return head;

		ListNode* fast=head, *slow = head;
		int len = 1, k_back = k;

		while(k && fast->next) {//让快指针先前进k步
			--k;
			++len;
			fast = fast->next;
		}

		if(k > 0) { // 此时Ｋ大于链表的长度 
			k = k_back;
			k = k % len;
			fast = head;
			while(k-- && fast->next) {//让快指针先前进k步
				++len;
				fast = fast->next;
			}
		}

		while(fast->next) {
			slow = slow->next;
			fast = fast->next;
		}

		fast->next = head;
		ListNode* newHead = slow->next;
		slow->next = 0;

		return newHead;
    }
};

void show(ListNode* l0) {
	while(l0) {
		cout<<l0->val<<" ";
		l0 = l0->next;
	}
}

int main() {
	ListNode* l1 = new ListNode(1);
	ListNode* l2 = new ListNode(2);
	ListNode* l3 = new ListNode(3);
	ListNode* l4 = new ListNode(4);
	ListNode* l5 = new ListNode(5);
	l1->next = l2;
	l2->next = l3;
	l3->next = l4;
	l4->next = l5;

	Solution s;
	show(s.rotateRight(l4,2));
}
