#include<iostream>
#include"../listnode.h"

using  namespace std;

/*
 * Given a singly linked list L: L0→L1→…→Ln-1→Ln,
 * reorder it to: L0→Ln→L1→Ln-1→L2→Ln-2→…
 *
 * You must do this in-place without altering the nodes' values.
 *
 * For example,
 * Given {1,2,3,4}, reorder it to {1,4,2,3}.
 */
ListNode *findMid(ListNode *head){
	ListNode *slow = head, *fast = head;
	while(fast && fast->next){
		slow = slow->next;
		fast = fast->next->next;
	}
	return slow;
}

ListNode *reverseList(ListNode *head){
	ListNode *newHead = new ListNode(0), *idx = head;
	while(idx){
		ListNode *tmp = idx;
		idx = idx->next;

		tmp->next = newHead->next;
		newHead->next = tmp;
	}
	return newHead->next;
}

void interMerge(ListNode *head, ListNode *back){
	while(back){
		ListNode *btmp = back;
		back = back->next;
		btmp->next = head->next;
		head->next = btmp;

		head = head->next->next;
	}
}

void reorderList(ListNode *head) {
	if(!head)
		return ;

	ListNode *mid = findMid(head);
	ListNode *back = reverseList(mid->next);
	mid->next = 0;

	interMerge(head,back);
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

	reorderList(l0);
	while(l0){
		cout<<l0->val<<endl;
		l0 = l0->next;
	}

	return 0;
}
