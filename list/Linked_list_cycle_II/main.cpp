#include<iostream>
#include"../listnode.h"

using namespace std;

ListNode *detect(ListNode *head, ListNode *fast){
	while(head != fast){
		head = head->next;
		fast = fast->next;
	}
	return head;
}

ListNode *detectCycle(ListNode *head) {
	ListNode *slow = head, *fast = head;
	while(fast && fast->next){
		slow = slow->next;
		fast = fast->next->next;

		if(fast == slow)
			return detect(ListNode *head,ListNode *fast);
	}
	return 0;
}

int main(){
	return 0;
}
