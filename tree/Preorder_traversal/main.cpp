#include<iostream>
#include<stack>
#include"../treenode.h"
using namespace std;

/*
 * Recurssion method can be quit staightforward
 */
void traversal(TreeNode *root,vector<int> &res){
	if(root){
		res.push_back(root->val);
		traversal(root->left,res);
		traversal(root->right,res);
	}
}

vector<int> preorderTraversal_recurr(TreeNode *root) {
	vector<int> res;
	traversal(root,res);
	return res;
}

/*
 * Iteration method of preorder is easiest, just need stack
 */
vector<int> preorderTraversal_iter(TreeNode *root){
	stack<TreeNode *> st;
	st.push(root);
	vector<int> res;
	TreeNode *curr;
	while(!st.empty()){
		curr = st.top();
		st.pop();
		if(curr){
			res.push_back(curr->val);
			st.push(curr->right);
			st.push(curr->left);
		}
	}
	return res;
}

/*
 * Use mirror to avoid O(lgn) space complexity  :)
 */
vector<int> preorderTraversal_mirror(TreeNode *root){
	vector<int> res;
	TreeNode *curr = root, *node = 0;
	while(curr){
		if(!curr->left){
			res.push_back(curr->val);
			curr = curr->right;
		}else{
			node = curr->left;
			while(node->right && node->right!=curr)
				node = node->right;

			if(!node->right){
				res.push_back(curr->val);
				node->right = curr;
				curr = curr->left;
			}else{
				node->right = NULL;
				curr = curr->right;
			}
		}
	}
	return res;
}


int main(){
	TreeNode *t0 = new TreeNode(8);
	TreeNode *t1 = new TreeNode(7);
	TreeNode *t2 = new TreeNode(12);
	TreeNode *t3 = new TreeNode(5);
	TreeNode *t4 = new TreeNode(9);
	TreeNode *t5 = new TreeNode(18);
	TreeNode *t6 = new TreeNode(2);
	TreeNode *t7 = new TreeNode(6);
	TreeNode *t8 = new TreeNode(20);
	
	t0->left = t1;
	t0->right = t2;
	t1->left = t3;
	t3->left = t6;
	t3->right = t7;
	t2->left = t4;
	t2->right = t5;
	t5->right = t8;
	vector<int> res =preorderTraversal_recurr(t0); 
	showV(res);
	res = preorderTraversal_iter(t0);
	showV(res);
	res = preorderTraversal_mirror(t0);
	showV(res);
		
	return 0;
}
