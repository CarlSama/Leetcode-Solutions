#include<iostream>
#include"../listnode.h"
using namespace std;

/*
 * Given a list, rotate the list to the right by k places, where k is non-negative.
 * For example: Given 1->2->3->4->5->nullptr and k = 2, return 4->5->1->2->3->nullptr.
 */
ListNode *rotateRight(ListNode *head, int k){
	if(!head)
		return head;

	ListNode *idx = head;
	int len = 1;
	while(idx->next){
		idx = idx->next;
		len++;
	}
	k = len - k%len;
	idx->next = head;
	while(k--){
		idx = idx->next;
	}
	head = idx->next;
	idx->next = 0;
	return head;
}

int main(){
	ListNode *l1 = new ListNode(1);
	ListNode *l2 = new ListNode(2);
	ListNode *l3 = new ListNode(3);
	ListNode *l4 = new ListNode(4);
	ListNode *l5 = new ListNode(5);
	l1->next = l2;
	l2->next = l3;
	l3->next = l4;
	l4->next = l5;
	l1 = rotateRight(l1,5);
	while(l1){
		cout<<l1->val<<endl;
		l1 = l1->next;
	}
	return 0;
}


