#include<iostream>
#include"../listnode.h"
using namespace std;

struct TreeNode{
	int val;
	TreeNode *left, *right;
	TreeNode(int x=0):val(x),left(0),right(0){}
};

//Because the head is moving, so just len is enough. !
TreeNode *gene(ListNode *&head,int len){
	//Needs to use refer here.
	if(len == 0)	return 0;
	int l = (len - 1) >> 1, r = len - l - 1;
	TreeNode *leftChild = gene(head,l);
	TreeNode *root = new TreeNode(head->val);
	root->left = leftChild;

	head = head->next;
	root->right = gene(head,r);
	return root;
}

TreeNode *gene(ListNode *&head,int left, int right){
	//Needs to use refer here.
	if(right < left)
		return NULL;

	int mid = (right + left) >> 1;
	TreeNode *leftChild = gene(head,left,mid);
	TreeNode *root = new TreeNode(head->val);
	root->left = leftChild;

	head = head->next;
	root->right = gene(head,mid+1,right);
	return root;
}

inline int getLen(ListNode *head){
	int len = 0;
	while(head){
		len++;
		head = head->next;
	}
	return len;
}

TreeNode *sortedListToBST(ListNode *head) {
	int len = getLen(head);
	return gene(head,1,len);
}

int main(){
	return 0;
}


