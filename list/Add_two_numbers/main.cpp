#include<iostream>
#include"../listnode.h"

using namespace std;

/*
 * You are given two linked lists representing two non-negative numbers. 
 * The digits are stored in reverse order and each of their nodes contain a single digit. 
 * Add the two numbers and return it as a linked list.
 * Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
 * Output: 7 -> 0 -> 8
 */
ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
	int carry = 0;
	ListNode *ll1 = l1, *ll2 = l2;
	ListNode *head = new ListNode(0), *idx = head;//We use sentinal head
	while(ll1 || ll2 || carry){
		int left = (!ll1)?0:ll1->val;
		int right = (!ll2)?0:ll2->val;
		idx->next = new ListNode((left + right + carry)%10);
		carry = (left + right + carry )/10;

		idx = idx->next;
		ll1 = ll1->next;
		ll2 = ll2->next;
	}	
	

	return head->next;
}
