#include<iostream>
#include<cmath>

using namespace std;

struct TreeNode {
	int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

/*
 * 复杂度lg(n) * lg(n)
 *
 * 需要充分的利用完全二叉树的性质，当是一个满树时，可以依据高度来计算出全部节点树
 */
class Solution {
public:
    int countNodes(TreeNode* root) {
		if(root==NULL)
			return 0;
		int lHeight = 0, rHeight = 0;//包含root本身

		TreeNode* lRoot = root;
		while(lRoot) {
			++lHeight;
			lRoot = lRoot->left;
		}
		TreeNode* rRoot = root;
		while(rRoot) {
			++rHeight;
			rRoot = rRoot->right;
		}

		if(lHeight == rHeight)
			return pow(2, lHeight) - 1;
		else 
			return countNodes(root->left) + countNodes(root->right) + 1;
    }
};

int main() {
	TreeNode* t1 = new TreeNode(1);
	TreeNode* t2 = new TreeNode(2);
	TreeNode* t3 = new TreeNode(3);
	TreeNode* t4 = new TreeNode(4);

	t1->left = t2;
	t1->right = t3;
	t2->left = t4;
	Solution s;
	cout<<s.countNodes(t1)<<endl;
}
