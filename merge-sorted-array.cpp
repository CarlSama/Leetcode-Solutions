#include<iostream>
#include<vector>
using namespace std;

class Solution {
		int len1;
public:
		void  copy_to_last(vector<int> & nums1,int m){
				//we need backward-copy
				len1 = nums1.size();
				int from = m - 1,to = len1 - 1;
				while(from >= 0) {
						nums1[to] = nums1[from];
						--from;	--to;
				}
		}

	    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
				if(n == 0)	return; 

				if(nums1[m-1] <= nums2[0]) {//just paste to end of nums1
						for(int i=0 ; i<n ; ++i) {
								nums1[m + i] = nums2[i];
						}
						return;
				}

				copy_to_last(nums1, m);
				int mi = len1-m , ni = 0, idx = 0;
				while(mi < len1 && ni < n) {
						if(nums1[mi] < nums2[ni]) {
								nums1[idx] = nums1[mi];
								++mi;
						}else{
								nums1[idx] = nums2[ni];
								++ni;
						}
						++idx;
				}

				while(mi < len1){
					nums1[idx] = nums1[mi];
					++idx;	++mi;
				}
				while(ni < n){
					nums1[idx] = nums2[ni];
					++idx;	++ni;
				}
		}
};
int main(){
		int arr1[9] = {2,3,9,1,1,1,1,1,1};
		int arr2[4] = {1,2,4};

		vector<int> v1(arr1,arr1+9);
		vector<int> v2(arr2, arr2+3);
		Solution s;
		s.merge(v1,3,v2,3);
		for(int i=0;i<6;++i)
				cout<<v1[i]<<" ";
		cout<<endl;
}
