#include<iostream>
#include"../listnode.h"

using  namespace std;

/*
 * Given a linked list, swap every two adjacent nodes and return its head.
 *
 * For example,
 * Given 1->2->3->4, you should return the list as 2->1->4->3.
 *
 * Your algorithm should use only constant space. 
 * You may not modify the values in the list, 
 *		only nodes itself can be changed.
 */
ListNode *swapPairs(ListNode *head) {
	ListNode *newHead = new ListNode(0), *idx = newHead;
	idx->next = head;

	while(idx && idx->next && idx->next->next){
		ListNode *nnnext  = idx->next->next->next;
		idx->next->next->next = idx->next;
		idx->next = idx->next->next;
		idx->next->next->next = nnnext;

		idx = idx->next->next;
	}

	return newHead->next;
}

int main(){
	ListNode *l0 = new ListNode(0);
	ListNode *l1 = new ListNode(1);
	ListNode *l2 = new ListNode(2);
//	ListNode *l3 = new ListNode(3);
	l0->next = l1;
	l1->next = l2;
//	l2->next = l3;
	l0 = swapPairs(0);
	while(l0){
		cout<<l0->val<<endl;
		l0 = l0->next;
	}
	return 0;
}

