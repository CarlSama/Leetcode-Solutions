#include<iostream>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
		ListNode* newHead = new ListNode(0);
		newHead->next = head;

		int count=0;
		ListNode* beforeFront = newHead;
		ListNode* front,* tail;

		while(tail) {
			count = 0;
			front = beforeFront->next;
			tail = beforeFront;

			while(tail && count < k) {
				tail = tail->next;
				++count;
			}

			if(count == k && tail) { 
				// 存在Ｋ个元素可以反转,需要反转[front,tail]内的元素
				while(--count > 0) {
					ListNode* curr = front->next;
					front->next = curr->next;
					curr->next = beforeFront->next;
					beforeFront->next = curr;
				}
				beforeFront = front;
			}else{
				break;
			}
		}

		return newHead->next;
    }

	void show(ListNode* head) {
		while(head) {
			cout<<head->val<<" ";
			head = head->next;
		}
		cout<<endl;
	}
};

int main() {
	ListNode* l1 = new ListNode(1);
	ListNode* l2 = new ListNode(2);
	ListNode* l3 = new ListNode(3);
	ListNode* l4 = new ListNode(4);
	l1->next = l2;
	l2->next = l3;
	l3->next = l4;

	Solution s;
	s.show(s.reverseKGroup(l1,2));
}
