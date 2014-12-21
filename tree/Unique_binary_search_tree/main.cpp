#include<iostream>
using namespace std;

/*
 *		Unique binary search tree
 *When computing the situation that m elements in the left,
 *we can treat m element as sub-problem which have been calculate previous.
 *Dynamic programming !
 */
int numTrees(int n){
	vector<int> num(n+1,0);
	num[0] = 1;

	for(int i=1;i<=n;i++){//We have i elements 
		int sum = 0;
		for(int j=0;j<i;j++){
			sum += num[j][i-1-j];
		}
		num[i] = sum;
	}

	return num[n];
}

/*
 *     Unique binary search tree
 * Even if tree have same branch pos, the num in each node may differ. 
 * Can we use a global vector to store the n's situation ?
 * No, the value in each node may differ although the case num is the same.
 */
vector<TreeNode *> dfs(int left,int right){
	vector<TreeNode *> res;
	if(right < left){
		res.push_back(nullptr);
		return res;
	}

	for(int i=left;i<=right;i++){//Use i as root
		vector<TreeNode *> lSub = dfs(left,i-1);
		vector<TreeNode *> rSub = dfs(i+1,right);
		for(auto j : lSub){
			for(auto k : rSub){
				TreeNode *root = new TreeNode(i);
				root->left = j;
				root->right = k;
				res.push_back(root);
			}
		}
	}

	return res;
}
		
vector<TreeNode *> generateTrees(int n){
	return dfs(1,n);
}

