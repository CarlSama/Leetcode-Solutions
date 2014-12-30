#include<iostream>
#include"../listnode.h"
using namespace std;

/*
 * Merge two sorted linked lists and return it as a new list. 
 * The new list should be made by splicing together the nodes of the first two lists.
 */
ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
	ListNode *newHead = new ListNode(0), *idx = newHead;
	while(l1 || l2){
		if(!l1){
			idx->next = l2;
			break;
		}
		if(!l2){
			idx->next = l1;
			break;
		}
		if(l1->val < l2->val){
			idx->next = l1;
			l1 = l1->next;
		}else{
			idx->next = l2;
			l2 = l2->next
		}
		idx = idx->next;
	}
	return newHead->next;
}
