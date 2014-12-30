#include<iostream>
#include"../listnode.h"
using namespace std;

/*
 * Given a linked list and a value x, partition it such that all nodes less than x come before nodes greater
 * than or equal to x.
 * You should preserve the original relative order of the nodes in each of the two partitions.
 * For example, Given 1->4->3->2->5->2 and x = 3, return 1->2->2->4->3->5.
 */
ListNode* partition(ListNode* head, int x) {	
	ListNode *lessHead = new ListNode(0), *less=lessHead;
	ListNode *unlessHead = new ListNode(0), *unless = unlessHead;
	ListNode *idx = head;

	while(idx){
		if(idx->val < x){
			less->next = idx;
			less = less->next;
		}else{
			unless->next = idx;
			unless = unless->next;
		}
		idx = idx->next;
	}

	less->next = unlessHead->next;
	return lessHead->next;
}
