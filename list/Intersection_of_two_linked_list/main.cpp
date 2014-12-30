#include<iostream>
#include"../listnode.h"

using namespace std;

ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
	ListNode *idxA = headA, *idxB = headB;
	int timesA = 1, timesB = 1;
	while(idxA || idxB || timesA==1 || timesB==1){
		if(!idxA){
			if(timesA==1){
				idxA = headB;
				timesA++;
			}else
				break;
		}

		if(!idxB){
			if(timesB==1){
				idxB = headA;
				timesB++;
			}else
				break;
		}

		//This appears before move(times==2 is important)
		if(idxA == idxB && timesA==2 && timesB==2)
			return idxA;

		idxA = idxA?idxA->next:idxA;
		idxB = idxB?idxB->next:idxB;
	}

	return 0;
}

int main(){
	return 0;
}
