#include<iostream>
#include"../listnode.h"

using namespace std;

ListNode *removeNthFromEnd(ListNode *head, int n) {
	if(!n || !head)
		return head;
	ListNode *newHead = new ListNode(0),*idx = newHead;
	idx->next = head;

	ListNode *slow = idx, *fast = idx;
	while((n--)>=0)
		fast = fast->next;
	
	while(fast){
		slow = slow->next;
		fast = fast->next;
	}
	//slow is point to before N
	slow->next = slow->next->next;
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

	l0 = removeNthFromEnd(l0,0);
	while(l0){
		cout<<l0->val<<endl;
		l0 = l0->next;
	}

	return 0;
}


