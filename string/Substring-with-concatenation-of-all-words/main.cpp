#include<iostream>
#include<unordered_set>
#include<vector>

using namespace std;

/*
 * Backtracking
 *  :(
 */
int subLen;
unordered_set<string> visited;

void dfs(int start,int curr,string S, vector<string> &L,vector<int> &res){
	if(visited.size() == L.size()){
		res.push_back(start);
		return ;
	}

	if(curr <= S.size()){
		for(auto str:L){
			//We may have duplicate in L?
			cout<<curr<<"+"<<subLen<<"-1 <="<<S.size()<<"-1"<<endl;
			if(visited.find(str) == visited.end() && curr+subLen-1<=S.size()-1 && S.substr(curr,subLen) == str){
				visited.insert(str);
				dfs(start,curr+subLen,S,L,res);
				visited.erase(str);
			}
		}

		dfs(curr+1,curr+1,S,L,res);//Gets wrong here ! 
		//只有完全判断完成之后,才能进行下一步.
		//不过在直接的回溯中,中间状态就可能产生向后的移动.不符合题目的要求.
	
		/*
		 * 对于粗略的回溯,最要不要针对大状态包含多个中间状态的情况.不然在一个大状态的判断中,可能就由于小状态而向后产生了移动.
		 * 破坏了大结果的完整性
		 */
	}
}

vector<int> findSubstring_bt(string S, vector<string> &L) {
	vector<int> res;

	if(S.size() && L.size()==0)
		return res;

	subLen = L[0].size();

	dfs(0,0,S,L,res);

	return res;
}

/*
 * Iteration
 * Move after finish
 */
bool hasStr(string str,vector<string> &L,vector<bool> &visited){
	for(int i=0;i<L.size();i++){
		if(str == L[i] && !visited[i]){
			visited[i] = true;
			return true;
		}
	}
	return false;
}
bool allVisited(vector<bool> &visited){
	for(auto v:visited)
		if(!v)
			return false;
	return true;
}

vector<int> findSubstring(string S, vector<string> &L) {
	vector<int> res;
	if(S.size()==0 || L.size()==0)
		return res;

	int subLen = L[0].size();
	int dictNum = L.size();
	int dictLen = dictNum * subLen;
	for(int i=0 ; i+dictLen<=S.size() ; i++){
		vector<bool > visited(L.size(),false);
		int j = i;
		while(j+subLen<=S.size()){
			string str = S.substr(j,subLen);
			if(hasStr(str,L,visited)){
				j += subLen;
			}else{
				break;
			}
		}

		if(allVisited(visited))
			res.push_back(i);

	}

	return res;
}

		


int main(){
	string s("lingmindraboofooowingdingbarrwingmonkeypoundcake");
	vector<string> l;
	l.push_back("fooo");
	l.push_back("barr");
	l.push_back("ding");
	l.push_back("wing");
	l.push_back("wing");

	vector<int> res = findSubstring(s,l);
	for(auto i:res)
		cout<<i<<" ";
	cout<<endl;

	return 0;
}





