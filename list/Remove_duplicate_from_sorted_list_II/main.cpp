#include<iostream>
#include"../listnode.h"
using namespace std;

/*
 * Given a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers
 * from the original list.
 * For example,
 * Given 1->2->3->3->4->4->5, return 1->2->5.
 * Given 1->1->1->2->3, return 2->3.
 */

ListNode *deleteDuplicates(ListNode *head){
	if(!head)
		return head;

	ListNode *newHead = new ListNode(head->val-1), *idx = newHead;
	idx->next = head;

	while(idx && idx->next && idx->next->next){
		if(idx->next->val == idx->next->next->val){
			ListNode *tmp = idx->next->next->next;
			while(tmp && tmp->val == idx->next->val){
				ListNode *discard = tmp;
				tmp = tmp->next;
				delete discard;
			}
			idx->next = tmp; 
		}else{
			idx = idx->next;
		}
	}

	return newHead->next;
}


int main(){
	ListNode *l0 = new ListNode(1);
	ListNode *l1 = new ListNode(1);
	ListNode *l2 = new ListNode(2);
	ListNode *l3 = new ListNode(3);
	ListNode *l4 = new ListNode(3);

	l0->next = l1;
	l1->next = l2;
	l2->next = l3;
	l3->next = l4;

	l0 = deleteDuplicates(l0);
	while(l0){
		cout<<l0->val<<endl;
		l0 = l0->next;
	}

	return 0;
}
