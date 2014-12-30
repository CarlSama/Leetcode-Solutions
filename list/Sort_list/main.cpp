#include<iostream>
#include"../listnode.h"

using namespace std;

/*
 * Sort a linked list in O(n log n) time using constant space complexity.
 */

/*
 * Merge Sort : Recurssion method
 */
ListNode *getMid(ListNode *head){
	ListNode *slow = head,*fast = head;
	while(fast && fast->next && fast->next->next){
		slow = slow->next;
		fast = fast->next->next;
	}
	return slow;
}

ListNode *merge(ListNode *left,ListNode *right){
	ListNode *newHead = new ListNode(0), *idx = newHead;
	while(left && right){
		if(left->val < right->val){
			idx->next = left;
			left = left->next;
		}else{
			idx->next = right;
			right = right->next;
		}
		idx = idx->next;
	}
	idx->next = left?left:right;
	return newHead->next;
}

ListNode *sortList(ListNode *head) {
	if(!head || !head->next)	return head;
	ListNode *mid = getMid(head);
	ListNode *right = sortList(mid->next);

	mid->next = 0;
	ListNode *left = sortList(head);

	return merge(left,right);
}


/*
 * Use three list to store different interval val
 * Partition List and Quick Sort ?!
 */
ListNode *sortList(ListNode *head) {
	if(!head)
		return 0;
	ListNode *h0 = new ListNode(0), idx0 = h0;
	ListNode *h1 = new ListNode(1), idx1 = h1;
	ListNode *h2 = new ListNode(2), idx2 = h2;
	int val = head->val;
	while(head){
		if(head->val == val){
			h0 = h0->next = head;
		}else if(head->val < val){
			h1 = h1->next = head;
		}else{
			h2 = h2->next = head;
		}

		head = head->next;
	}
	
	h0->next = h1->next = h2->next = 0;
	idx1->next = sortList(idx1->next);
	ListNode *idx;
	for(idx=idx1;idx->next;idx = idx->next);
	idx->next = idx0->next;
	xxx.next = sortList(idx3->next);	
	return idx1->next;
}

/*
 * Merge Sort : Iteration method
 */
ListNode *mergeSort(ListNode *head){
	if(!head || !head->next)	return head;
	vector<ListNode *> ladder(64,nullptr);//Every level of ladder is sorted
	ListNode *carry = nullptr;
	int fill = 0;
	while(head){
		carry = new ListNode(head->val);
		head = head->next;

		int i=0;
		for(;i<fill && ladder[i];i++){//if ladder[i]==nullptr, then this ladder is enough to contain carry.
			carry = merge(ladder[i],carry);
			ladder[i] = nullptr;
		}
		ladder[i] = carry;
		if(i==fill)
			fill++;
	}
	for(int i=1;i<fill;i++){
		ladder[i] =  merge(ladder[i], ladder[i-1]);
	}
	return ladder[fill-1];
}

int main(){
	ListNode * l0 = new ListNode(2);
	ListNode * l1 = new ListNode(3);
	ListNode * l2 = new ListNode(5);
	ListNode * l3 = new ListNode(1);
	ListNode * l4 = new ListNode(4);
	ListNode * l5 = new ListNode(0);

	l0->next = l1;
	l1->next = l2;
	l2->next = l3;
	l3->next = l4;
	l4->next = l5;

	l0 = sortList(l0);
	while(l0){
		cout<<l0->val<<endl;
		l0 = l0->next;
	}
	return 0;
}

