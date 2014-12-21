#include<iostream>
#include<stack>
#include<vector>
#include<cmath>
#include<climits>
#include<deque>
using namespace std;

struct TreeNode {
    int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int numTrees(int n) {
	vector<int> res;
	res.push_back(1);

	int tmp;
	for(int i=1;i<=n;i++){//We have i elemets and the root would takes 1.
		int tmp;//Arrange the rest i-1 elements
		for(int j=0;j<=i-1;j++){//has j elements in the left and i-1-j in the right
			tmp += res[j]*res[i-1-j];
		}
		res.push_back(tmp);
	}
	return res.back();
}

/*vector<vector<vector<TreeNode *> > > res;
void dfs(int left, int right){
	if(left>right)
		res.push_back(NULL);
		return   


vector<vector<TreeNode *> > generateTrees(int n){
	dfs(1,n);
	return res;
}*/

/*
 * level Order
 */
//Use sentinals to indicate reaching the end of one layer.
//We only allocate two rolling sentinals here , 
//because there would be at most two layer in the queue at any time.
vector<vector<int> > levelOrder_sential(TreeNode *root){
	vector<vector<int> > res;
	vector<int> path;
	TreeNode *nil[2];
	nil[0] = new TreeNode(0);
	nil[1] = new TreeNode(0);

	deque<TreeNode *> que;
	que.push_back(root);
	que.push_back(nil[0]);

	int canUse = 1;//The nil[1] can be used as sentinal now.
	while(!que.empty()){
		TreeNode * front = que.front();
		que.pop_front();

		if(front == nil[(canUse+1)%2]){//The sentinal for previous layer
			//Here means the ending of one layer.		
			res.push_back(path);
			if(que.empty())
				break;
			path.clear();
			que.push_back(nil[canUse%2]);
			canUse++;
		}else{
			path.push_back(front->val);
			if(front->left)
				que.push_back(front->left);
			if(front->right)
				que.push_back(front->right);
		}
	}
	return res;
}

//Use two deque to store differ level
vector<vector<int> > levelOrder_ddque(TreeNode *root){
	vector<vector<int> >res;
	vector<int> path;

	deque<TreeNode *> dq[2];
	dq[0].push_back(root);

	int canUse = 1;
	while(!dq[(canUse+1)%2].empty()){
		int curr = (canUse+1)%2;
		int next = canUse%2;

		TreeNode *front = dq[curr].front();
		dq[curr].pop_front();

		path.push_back(front->val);
		if(dq[curr].empty()){
			canUse++;
			res.push_back(path);
			path.clear();
		}
		if(front->left)
			dq[next].push_back(front->left);
		if(front->right)
			dq[next].push_back(front->right);
	}

	return res;
}
			
//Use recurssion method : we explicit assign the level.
void recurr(TreeNode *root,int level,vector<vector<int> > &res){
	if(NULL==root)
		return ;
	if(level+1>res.size())
		res.push_back(vector<int>());
	
	res[level].push_back(root->val);
	recurr(root->left,level+1,res);
	recurr(root->right,level+1,res);
}
vector<vector<int> > levelOrder_recurr(TreeNode *root){
	vector<vector<int> > res;
	recurr(root,0,res);
	return  res;
}


TreeNode *sortedArrayToBST(vector<int> &num) {

}



/*
 * Same Tree
 */
bool isSameTree_recurr(TreeNode *p, TreeNode *q){
	return (NULL==p&&NULL==q) || (p && q && (p->val==q->val) && (isSameTree_recurr(p->left,q->left)) && (isSameTree_recurr(p->right,q->right)));
}
bool isSameTree_iter(TreeNode *p,TreeNode *q){
	stack<TreeNode *> st;
	st.push(p);
	st.push(q);

	while(!st.empty()){
		p = st.top(); st.pop();
		q = st.top(); st.pop();

		if(NULL==p && NULL==q) continue;
		if(p && q && p->val==q->val){
			st.push(p->left);
			st.push(q->left);
			st.push(p->right);
			st.push(q->right);
		}else
			return false;
	}
	return true;
}

/* 
 * Symmetric Tree
 */
bool symmetric(TreeNode *left,TreeNode *right){
	if(NULL==left && NULL==right) return true;
	return (left && right && left->val==right->val && symmetric(left->left,right->right) && symmetric(left->right,right->left));
}

bool isSymmetric_curr(TreeNode *root) {
	if(!root)return true;
	return symmetric(root->left,root->right);
}

//Inorder preorder postorder
//Just visit every elements and check
bool isSymmetric_iter(TreeNode *root) {
	stack<TreeNode *> st;
	TreeNode *curr=root,*prev=0;

	while(!st.empty() || curr){
		if(curr){
			st.push(curr);
			curr = curr->left;
		}else{
			curr = st.top();
			st.pop();
			if(prev == curr->right){
				if((NULL==curr->left&&NULL==curr->right)||(curr->left && curr->right && curr->left->val==curr->right->val)){
					prev = curr;
				}else{
					return false;
				}
			}else{
				curr = curr->right;
			}
		}
	}
	return true;
}

/*
 * Balance binary tree
 */
//We need the height of each sons to determine.
//So recurrsion method is quit straightforward.
//How about iteration ? 
//the height need to be stored and linked to each node, hash may help.
int height(TreeNode *p){
	if(NULL==p)  return 0;
	int l = height(p->left) ;
	int r = height(p->right) ;
	if(l < 0 || r < 0 || std::abs(l-r)>0)
		return -2;
	return max(l,r)+1;
}
		
bool isBalanced_recurr(TreeNode* root) {
	return (height(root)>0);
}

/*
 * flattern
 */
void flatten_iter(TreeNode *root) {
	stack<TreeNode *> st;
	st.push(root);

	TreeNode *curr;
	while(!st.empty()){
		curr = st.top();
		st.pop();

		if(curr){
			st.push(curr->right);
			st.push(curr->left);

			curr->left = NULL;
			if(!st.empty())
				curr->right = st.top();
		}
	}
}

//Like moris
void flattern_recurr(TreeNode *root){
	if(NULL==root) return ;
	flattern_recurr(root->left);
	flattern_recurr(root->right);

	if(NULL==root->left) return;//flattern

	TreeNode *tmp = root->left;
	while(tmp->right){
		tmp = tmp->right;
	}
	tmp->right = root->right;
	root->right = root->left;
	root->left = NULL;
}

int maxPath = 0;
int checkMax(TreeNode *root){
	if(!root) return 0;
	int l = checkMax(root->left);
	int r = checkMax(root->right);
	int currMax = max(l+root->val,max(r+root->val,max(root->val,l+r+root->val)));
	maxPath = maxPath>currMax?maxPath:currMax;
	return max(l+root->val,max(root->val,r+root->val));
}
int maxPathSum(TreeNode *root) {
	checkMax(root);
	return maxPath;
}
int main(){
	TreeNode *t0 = new TreeNode(5);
	TreeNode *t1 = new TreeNode(4);
	TreeNode *t2 = new TreeNode(8);

	TreeNode *t3 = new TreeNode(11);
	TreeNode *t4 = new TreeNode(13);
	TreeNode *t5 = new TreeNode(4);
	TreeNode *t6 = new TreeNode(7);
	TreeNode *t7 = new TreeNode(2);
	TreeNode *t8 = new TreeNode(1);
	
	t0->left = t1;
	t0->right = t2;
	t1->left = t3;
	t3->left = t6;
	t3->right = t7;
	t2->left = t4;
	t2->right = t5;
	t5->right = t8;
	cout<<maxPathSum(t0)<<endl;
	/*for(int i=0;i<res.size();i++){
		for(int j=0;j<res[i].size();j++){
			cout<<res[i][j]<<"  ";
		}
		cout<<endl;
	}*/
	/*for(int i=0;i<res.size();i++)
		cout<<res[i]<< "  ";
	cout<<endl;*/
	return 0;
}
