#include<iostream>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
		ListNode* newHead = new ListNode(0);
		newHead->next = head;

		ListNode* curr = newHead, *checkDuplicate;
		while(curr) {
			checkDuplicate = curr->next;
			
			if(checkDuplicate && checkDuplicate->val == curr->next->val) {
				ListNode* toBeDeleted;
				while(checkDuplicate && checkDuplicate->val == curr->next->val) {
					toBeDeleted = checkDuplicate;
					checkDuplicate = checkDuplicate->next;
					delete toBeDeleted;
				}
				toBeDeleted = curr->next;
				delete toBeDeleted;

				curr->next = checkDuplicate;
				curr = checkDuplicate;
			}else{
				curr = curr->next;
			}
		}
		return newHead->next;
    }
};
void show(ListNode* head) {
	while(head) {
		cout<<head->val<<endl;
		head = head->next;
	}
}

int main() {
	ListNode* l0 = new ListNode(1);
	ListNode* l1 = new ListNode(1);
	ListNode* l2 = new ListNode(2);
	ListNode* l3 = new ListNode(3);
	ListNode* l4 = new ListNode(3);
	l0->next = l1;
	l1->next = l2;
	l2->next = l3;
	l3->next = l4;

	Solution s;
	show(s.deleteDuplicates(l0));
}
