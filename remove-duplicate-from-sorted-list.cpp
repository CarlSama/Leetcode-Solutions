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
		ListNode* unique = head, *checkDuplicate;
		while(unique) {
			checkDuplicate = unique->next;
			
			//ignore all duplicate elements
			while(checkDuplicate && checkDuplicate->val == unique->val) {
				ListNode* toBeDeleted = checkDuplicate;
				checkDuplicate = checkDuplicate->next;
				delete toBeDeleted;
			}

			unique->next = checkDuplicate;
			unique = unique->next;
		}
		return head;
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
