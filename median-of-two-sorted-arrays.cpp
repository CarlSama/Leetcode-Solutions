#include<iostream>
#include<vector>
using namespace std;
class Solution {
	int len1,len2;
	public:
		int findKth(vector<int>& nums1,int begin1,vector<int>& nums2,int begin2,int k){
			int nums1Len = nums1.size() - begin1;
			int nums2Len = nums2.size() - begin2;
			if(nums1Len < nums2Len)	return findKth(nums2,begin2,nums1,begin1,k);//let nums1 longger
			if(nums2Len==0)	return nums1[begin1 + k - 1];

			if(k == 1)	return min(nums1[begin1], nums2[begin2]);

			int idx2 = min(nums2Len, k/2);
			int idx1 = k - idx2;
			if(nums1[idx1 + begin1 - 1] > nums2[idx2 + begin2 - 1]){
				return findKth(nums1,begin1,nums2,begin2+idx2,k-idx2);
			}else if(nums1[idx1 + begin1 - 1] < nums2[idx2 + begin2 - 1]){
				return findKth(nums1,begin1+idx1,nums2,begin2,k-idx1);
			}else{
				return nums1[idx1 + begin1 - 1];
			}
		}

		double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
			len1 = nums1.size();	len2 = nums2.size();
			if((len1 + len2) % 2)
				return findKth(nums1,0,nums2,0,(len1+len2)/2+1);
			else{
				return ( findKth(nums1,0,nums2,0,(len1+len2)/2) + findKth(nums1,0,nums2,0,(len1+len2)/2+1) ) / 2.0 ;
			}
		}
};
int main(){
	int arr1[3] = {1,2,3};
	int arr2[4] = {4,5,6,7};
	vector<int> v1(arr1,arr1+3);
	vector<int> v2(arr2,arr2+4);

	Solution s;
	cout<<s.findMedianSortedArrays(v1,v2)<<endl;

}
