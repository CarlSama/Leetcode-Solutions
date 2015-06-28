#include<iostream>
#include<vector>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
	public:
		TreeNode* invertTree(TreeNode* root) {
			if(root == NULL)
				return root;

			TreeNode *left = root->left;
			root->left = root->right;
			root->right = left;

			invertTree(root->left);
			invertTree(root->right);
			return root;
		}
};

void inor(TreeNode* root) {
	if(root) {
		inor(root->left);
		cout<<root->val<<endl;
		inor(root->right);
	}
}

int main(){
	TreeNode * l1 = new TreeNode(1);
	TreeNode * l2 = new TreeNode(2);
	TreeNode * l3 = new TreeNode(3);
	TreeNode * l4 = new TreeNode(4);
	TreeNode * l5 = new TreeNode(5);
	TreeNode * l6 = new TreeNode(6);
	TreeNode * l7 = new TreeNode(7);

	l4->left = l2;
	l4->right = l6;
	l2->left = l1;
	l2->right = l3;
	//l6->left = l5;
	//l6->right = l7;

	Solution s;
	inor(s.invertTree(l4));
}
