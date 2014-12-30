#include<iostream>
#include"../listnode.h"

/*
 * Given a sorted linked list, delete all duplicates such that each element appear only once.
 * For example,
 * Given 1->1->2, return 1->2.
 * Given 1->1->2->3->3, return 1->2->3.
 */

ListNode *deleteDuplicates(ListNode *head){
	if(!head) return 0;

	ListNode *newHead = new ListNode(head->val-1), *idx = newHead;
	idx->next = head;
	while(idx && idx->next){
		if(idx->val == idx->next->val){
			ListNode *discard = idx->next;
			idx->next = idx->next->next;
			delete discard;
		}else{
			idx = idx->next;
		}
	}

	return newHead->next;
}

	
ListNode *deleteDuplicates(ListNode *head){
	if(!head || !head->next)
		return head;

	if(head->val == head->next->val){
		ListNode *discard;
		while(head->next){
			discard = head->next;
			head->next = head->next->next;
			delete discard;
		}
	}
	head->next = deleteDuplicates(head->next);
	return head;
}

