#include<iostream>
#include"../listnode.h"
using namespace std;

struct RandomListNode {
	int label;
	RandomListNode *next, *random;
	RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
};

		RandomListNode *copyRandomList(RandomListNode *head) {
			RandomListNode *newHead = new RandomListNode(0), *idx = newHead;
			idx->next = head;

			while(idx){
				RandomListNode *tmp = new RandomListNode(idx->label); tmp->next = idx->next;
				idx->next = tmp;
				tmp->random = idx;

				idx = idx->next->next;
			}

			idx = newHead;
			while(idx){
				idx->next->random = idx->random?idx->random->next:0;
				idx = idx->next->next;
			}

			idx = newHead;
			while(idx){
				RandomListNode *idxNext = idx->next->next;
				idx->next->next = idx->next->next?idx->next->next->next:0;
				idx->next = idxNext;

				idx = idx->next;
			}
			return newHead->next;
		}


int main(){
	RandomListNode *head  = new RandomListNode(-1);

	copyRandomList(head);
	return 0;
}
