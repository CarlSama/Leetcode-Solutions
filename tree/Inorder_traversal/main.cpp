#include<iostream>
#include<stack>
#include<vector>
#include"../treenode.h"

using namespace std;

/*
 * Recurssion method
 */
void traversal(TreeNode *root,vector<int> &res){
	if(root){
		traversal(root->left,res);
		res.push_back(root->val);
		traversal(root->right,res);
	}
}
vector<int> inorderTraversal_recurr(TreeNode *root){
	 vector<int> res;
	 traversal(root,res);
	 return res;
}

/*
 * Iteration method
 * Little more complex than preorder, we need to use additional TreeNode*
 */
vector<int> inorderTraversal_iter(TreeNode *root){
	vector<int> res;
	stack<TreeNode *> st;
	TreeNode *curr = root;
	while(!st.empty() || curr){
		if(curr){
			st.push(curr);
			curr = curr->left;
		}else{
			curr = st.top();
			st.pop();

			res.push_back(curr->val);
			curr = curr->right;
		}
	}
	return res;
}

/*
 * Mirror method
 */
vector<int> inorderTraversal_mirror(TreeNode *root){
	vector<int> res;
	TreeNode *curr = root;

	while(curr){
		if(!curr->left){
			res.push_back(curr->val);
			curr = curr->right;
		}else{
			TreeNode *node = curr->left;
			while(node->right && node->right!=curr)
				node = node->right;
			if(!node->right){
				node->right = curr;
				curr = curr->left;
			}else{
				node->right = NULL;
				res.push_back(curr->val);
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
	vector<int> res = inorderTraversal_recurr(t0); 
	showV(res);
	res = inorderTraversal_iter(t0);
	showV(res);
	res = inorderTraversal_mirror(t0);
	showV(res);
		
	return 0;
}


