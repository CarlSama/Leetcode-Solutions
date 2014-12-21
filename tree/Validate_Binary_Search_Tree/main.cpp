#include<iostream>
using  namespace std;

struct TreeNode{
	int val;
	TreeNode *left,*right;
	TreeNode(int v):val(v),left(NULL),right(NULL){}
};

/*
 *				Iteration Method
 *In iteration method, we only need to compare nodes 
 *with its predecessor to ensure validation.
 *So, the whole code looks like inorder traversal :)
 */
bool isValidBST_1(TreeNode *root) {
	TreeNode *curr = root, *prev = 0;
	stack<TreeNode *> st;

	while(!st.empty() || curr){
		if(curr){
			st.push(curr);
			curr = curr->left;
		}else{
			curr = st.top();
			st.pop();

			if(prev && prev->val > curr->val)
				return false;

			prev = curr;
			curr = curr->right;
		}
	}
	
	return true;
}

/*
 *			Recusion  Method
 *Compare each node with its left or right child is useless, 
 *because they mayn't be its predecessor or successor.
 *Getting the predecessor can be trickey : if the tree is binary search,
 *then the node with biggest val in one's left must be its predecessor.
 *So, if each node can greater than the biggest node in its left, and less than the biggest node in its right, then bingo !
 */
bool err;
pair<int,int> checkBound(TreeNode *root){
	pair<int,int> bound;
	int lBound=root->val,rBound=root->val;
	if(root->left){
		bound = checkBound(root->left);
		if(bound.second <= root->val){
			err = true;
		}
		lBound = bound.first;
	}
	if(root->right){
		bound = checkBound(root->right);
		if(bound.first >= root->val){
			err = true;
		}
		rBound = bound.second;
	}
	return make_pair(lBound,rBound);
}

bool isValidBST_2(TreeNode *root) {
	if(nullptr == root)
		return true;
	err = false;
	checkBound(root);
	return err;
}

bool check(TreeNode *root,int min, int max){
	if(nullptr == root)
		return true;

	return (root->val > min) && (root->val < max) && check(root->left,min,root->val) && check(root->right,root->val,max);	
}

bool isValidBST_3(TreeNode *root) {
	return check(root,INT_MIN,INT_MAX);
}
