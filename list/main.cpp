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

	l0 = reverseBetween(NULL,1,2);
	while(l0){
		cout<<l0->val<<endl;
		l0 = l0->next;
	}

	return 0;
}
