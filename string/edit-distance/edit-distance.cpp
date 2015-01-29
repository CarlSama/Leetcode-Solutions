#include<iostream>
#include<string>
#include<climits>
#include<algorithm>
#include<vector>

using namespace std;

/*
 * distance[i][j] means we manage word1[1~i] and word2[1~j]
 */
int minDistance(string word1, string word2){
	int len1 = word1.size();
	int len2 = word2.size();

	cout<<word1<<word2<<endl;
	vector<vector<int> > distance(len1+1, vector<int>(len2+1, 0));
	for(int i=1;i<=len1;i++)
		distance[i][0] = i;
	for(int i=1;i<=len2;i++)
		distance[0][i] = i;

	for(int i=1;i<=len1;i++){
		for(int j=1;j<=len2;j++){
			cout<<word1[i]<<word2[j]<<endl;
			if(word1[i-1] == word2[j-1]){
				distance[i][j] = distance[i-1][j-1];
			}else{
				//Insert after i ; delete i; replace i
				distance[i][j] = min(distance[i][j-1]+1,min(distance[i-1][j]+1,distance[i-1][j-1]+1));
			}
		}
	}
	return distance[len1][len2];
}
int main(){
	cout<<minDistance("a","b");
	return 0;
}
