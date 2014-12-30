#include<iostream>
#include"../listnode.h"
using  namespace std;
/*
 * Reverse a linked list from position m to n. Do it in-place and in one-pass.
 * For example: 
 *		Given 1->2->3->4->5->nullptr, m = 2 and n = 4,
 *		return 1->4->3->2->5->nullptr.
 * Note: Given m, n satisfy the following condition: 1 ≤ m ≤ n ≤ length of list.
 */

ListNode *reverseBetween(ListNode *head, int m, int n) {
	ListNode *newHead = new ListNode(0), *idx = newHead;
	idx->next = head;

	if(m == n)
		return head;

	int i=1;
	while(i < m){
		idx = idx->next;
		i++;
	}
	ListNode *prev = idx, *tail = idx->next; 
	ListNode *subHead = new ListNode(0);//This is the node at m-1
	idx = idx->next;
	while(i <= n){
		ListNode *tmp = idx;
		idx = idx->next;

		tmp->next = subHead->next;
		subHead->next = tmp;
		i++;
	}

	prev->next = subHead->next;
	tail->next = idx;
	return newHead->next;
}

int main(){
	ListNode *l0 = new ListNode(0);
	ListNode *l1 = new ListNode(1);
	ListNode *l2 = new ListNode(2);
	ListNode *l3 = new ListNode(3);
	ListNode *l4 = new ListNode(4);

	l0->next = l1;
	l1->next = l2;
	l2->next = l3;
	l3->next = l4;

	l0 = reverseBetween(NULL,1,2);
	while(l0){
		cout<<l0->val<<endl;
		l0 = l0->next;
	}

	return 0;
}
