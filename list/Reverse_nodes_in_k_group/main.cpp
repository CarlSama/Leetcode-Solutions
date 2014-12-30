#include<iostream>
#include"../listnode.h"

using namespace std;

/*
 * Given a linked list, 
 *		reverse the nodes of a linked list k at a time and return its modified list.
 * If the number of nodes is not a multiple of k then left-out nodes in the end should remain as it is.
 *
 * You may not alter the values in the nodes, only nodes itself may be changed.
 *
 * Only constant memory is allowed.
 *
 * For example,
 * Given this linked list: 1->2->3->4->5
 *
 * For k = 2, you should return: 2->1->4->3->5
 *
 * For k = 3, you should return: 3->2->1->4->5
 */

ListNode *reverse(ListNode *head, int k){
	ListNode *idx = head->next, *begin = head->next;
	ListNode *newBegin = new ListNode(0);
	while(k--){
		ListNode *tmp = idx;
		idx = idx->next;

		tmp->next = newBegin->next;
		newBegin->next = tmp;
	}
	//Now the idx points to first elem of next k.
	//	  the begin points to last elem of this k.
	head->next = newBegin->next;
	begin->next = idx;
	return begin;
}

ListNode *reverseKGroup(ListNode *head, int k) {
	if(!k || !head)
		return head;
	ListNode *newHead = new ListNode(0), *idx = newHead;
	idx->next = head;

	int times;
	ListNode *check;
	while(idx){
		times = k;
		check = idx->next;
		while(times-- && check)  {
			// Warnning ! the times-- needs to appears before check, in case times not reach -1 because check==null(the &&)
			check = check->next;
		}
		if(times!=-1)//which means the remain elems are less than k.
			return newHead->next;

		//We get k elem begins at idx, let's reverse them
		idx = reverse(idx,k);
	}

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

	l0 = reverseKGroup(l0,0);
	while(l0){
		cout<<l0->val<<endl;
		l0 = l0->next;
	}

	return 0;
}

