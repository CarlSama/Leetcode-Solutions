#ifndef _list_node_
#define _list_node_

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(0) { }
};

void print(ListNode *head, string info = ""){
	cout<<"Print List "<<info<<endl;
	while(head){
		cout<<head->val<<" "<<endl;
		head = head->next;
	}
	cout<<endl;
}
#endif
