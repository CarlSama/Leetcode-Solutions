#include<iostream>
#include<vector>
#include<unordered_set>
#include<unordered_map>
#include<climits>
#include<algorithm>
using namespace std;
    
/*
 * DFS
 */
//这道题不能这么做,对于较短小数据(2位),这样子不合适
bool canTrans(string src,string dest){
	int diff = 0;
	int len = src.size();

	for(int i=0;i<len;i++)
		diff += (src[i]!=dest[i]);
	
	return diff==1;
}

int pathLen;
vector<string> path;
vector<vector<string> > res;

bool noExist(string str){
	for(int i=0;i<path.size();i++){
		if(str == path[i])
			return false;
	}
	return true;
}

void solve(string curr,string end,unordered_set<string> &dict){
	if(curr == end){
		path.push_back(end);
		if(path.size() < pathLen){
			pathLen = path.size();
			res.clear();
			res.push_back(path);
		}else if(path.size() == pathLen){
			res.push_back(path);
		}else{
			//ignore the longer case
		}

		path.pop_back();
		return ;
	}


	/*
	 * 非常朴素的回溯方法,会造成TLE
	 * 原因分析 :
	 */
	if(path.size() == pathLen)
		return ;
	for(int i=0;i<curr.size();i++){
		for(char c='a';c<='z';c++){
			if(c != curr[i]){
				string to = curr;
				to[i] = c;

				if(dict.find(to) != dict.end() && noExist(to)){
					path.push_back(curr);
					solve(to,end,dict);
					path.pop_back();
				}
			}
		}
	}
}

vector<vector<string>> findLadders_dfs(string start, string end, unordered_set<string> &dict) {
	if(dict.find(end) == dict.end())
		dict.insert(end);
	pathLen = INT_MAX;
	solve(start,end,dict);
	return res;
}


/*
 * BFS
 * 1)可以使用层次限制,避免多余搜索
*  2)可以保证每个对象只会被访问一次
*  3)使用儿子->父亲存储法,可以非常有针对性的获取路径
 */

void reverse_dfs(string start,string curr,unordered_map<string,vector<string> > &parent,vector<string> &path,vector<vector<string> > &res){
	if(curr == start){
		path.push_back(curr);
		res.push_back(path);
		reverse(res.back().begin(), res.back().end());// 这么做是为了避免对Path做reverse操作后,影响回溯代码的结构
		path.pop_back();
	}else{
		for(auto prev : parent[curr]){
			path.push_back(curr);
			reverse_dfs(start,prev,parent,path,res);
			path.pop_back();
		}
	}
}

vector<vector<string>> findLadders_bfs(string start, string end, unordered_set<string> &dict) {
	unordered_set<string> myDict = dict;
	myDict.insert(end);
	unordered_map<string, vector<string> > parent;
	bool lastLevel = false;
	unordered_set<string> level[2];//避免重复
	int idx = 0;

	level[idx%2].insert(start);
	while(!lastLevel && !level[idx%2].empty()){
		for(auto str : level[idx%2]){
			myDict.erase(str);
		}
		
		for(auto str : level[idx%2]){
			if(str == end){
				lastLevel = true;
				break;
			}

			for(int i=0;i<str.size();i++){
				for(char c = 'a';c<='z';c++){
					string to = str;
					to[i] = c;

					if(myDict.find(to) != myDict.end()){
						parent[to].push_back(str);
						level[(idx+1)%2].insert(to);
					}
				}
			}
		}
		level[idx%2].clear();
		idx++;
	}

	cout<<start<<end<<endl;
	vector<string> path;
	vector<vector<string> > res; 
	if(lastLevel)
		reverse_dfs(start,end,parent,path,res);
	return res;
}

int main(){
	unordered_set<string> dict;
	dict.insert("hot");
	dict.insert("cog");
	dict.insert("dog");
	dict.insert("tot");
	dict.insert("hog");
	dict.insert("hop");
	dict.insert("pot");
	dict.insert("dot");
	vector<vector<string> > res = findLadders_bfs("hot","dog",dict);

	for(int i=0;i<res.size();i++){
		for(int j=0;j<res[i].size();j++)
			cout<<res[i][j]<<" ";
		cout<<endl;
	}
	return 0;
}
	

