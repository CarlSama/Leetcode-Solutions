#include<iostream>
#include<deque>
using namespace std;

struct TreeLinkNode{
	int val;
	TreeLinkNode *left,*right,*next;
	TreeLinkNode(int x):val(x),left(NULL),right(NULL),next(NULL){}
};
/*
 * seems like level traversal
 */
void connect(TreeLinkNode *root){
		if(nullptr == root)
			return ;

		deque<TreeLinkNode *> dq[2];
		dq[0].push_back(root);
		int idx = 1;
	    while(!dq[(idx+1)%2].empty()){
			TreeLinkNode *top = dq[(idx+1)%2].front();
			dq[(idx+1)%2].pop_front();
			if(top->left)
				dq[idx%2].push_back(top->left);
			if(top->right)
			    dq[idx%2].push_back(top->right);

			if(dq[(idx+1)%2].empty())
			    idx++;
			else
			    top->next = dq[(idx+1)%2].front();
		}
}

