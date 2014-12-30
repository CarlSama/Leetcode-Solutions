#include<iostream>
#include<map>
#include<vector>
#include"../listnode.h"
using namespace std;

/*
 * Merge k sorted linked lists and return it as one sorted list. Analyze and describe its complexity.
 */
ListNode *mergeKLists(vector<ListNode *> &lists) {
	//Attention ! we need to use multimap here.
	multimap<int,ListNode *> minHeap;
	for(auto iter=lists.begin(); iter!=lists.end(); iter++){
		if(*iter)
			minHeap.insert(make_pair((*iter)->val,*iter));
	}
	ListNode *head = new ListNode(0), *idx = head;
	while(!minHeap.empty()){
		for(auto iter = minHeap.begin(); iter!=minHeap.end(); iter++)
			cout<<iter->first<<"  ";
		cout<<endl;

		auto minIter = minHeap.begin();
		ListNode *min = minIter->second;
		idx->next = min;
		idx = idx->next;
		minHeap.erase(minIter);

		min = min->next;
		if(min)
			minHeap.insert(make_pair(min->val, min));

	}
	return head->next;
}



int main(){
	ListNode *l0 = new ListNode(1);
	ListNode *l1 = new ListNode(2);
	ListNode *l2 = new ListNode(1);
	ListNode *l3 = new ListNode(1);
	ListNode *l4 = new ListNode(2);

	l0->next = l1;
	l2->next = l3;
	l3->next = l4;

	vector<ListNode *> v;
	v.push_back(l0);
	v.push_back(l2);
	l0 = mergeKLists(v);
	while(l0){
		cout<<l0->val<<endl;
		l0 = l0->next;
	}

	return 0;
}
		        
		    
