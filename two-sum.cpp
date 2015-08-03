#include<iostream>
#include<algorithm>
#include<vector>
#include<unordered_map>
using namespace std;

class Solution {
	public:
		vector<int> twoSum(vector<int>& nums, int target) {
			vector<int> res;
			unordered_map<int,int> hashmap;

			//record the idx and the value its needed
			/*for(int i=0;i<nums.size();++i)
				hashmap.insert(pair<int,int>(target - nums[i], i+1));

			for(int i=0;i<nums.size();++i){
				auto iter = hashmap.find(nums[i]);
				if(iter != hashmap.end()){
					if(i+1 != iter->second){
						if(i+1 < iter->second){
							res.push_back(i+1);
							res.push_back(iter->second);
							break;
						}else{
							res.push_back(iter->second);
							res.push_back(i+1);
							break;
						}
					}
				}
			}*/
			for(int i=0;i<nums.size();++i){
				auto iter = hashmap.find(nums[i]);

				if(iter == hashmap.end()){
					hashmap.insert(pair<int,int>(target - nums[i], i+1));
				}else{
					if(i+1 < iter->second){
						res.push_back(i+1);	res.push_back(iter->second);
					}else{
						res.push_back(iter->second);	res.push_back(i+1);
					}
				}
			}

			return res;
		}
};
int main(){
	int arr[4] = {3,2,4,1};
	vector<int> nums(arr,arr+4);
	Solution s;;
	vector<int> res = s.twoSum(nums,6);
	cout<<res[0]<<res[1]<<endl;
}
