#include<iostream>
#include<vector>
#include<stack>
using namespace std;
struct Info {
		int idx;
		int front;//向前延伸到的位置
		int ht;
		Info(int i,int h,int f) : idx(i),ht(h),front(f) {}
};

class Solution {
	int len;
public:
	int largestRectangleArea(vector<int>& height) {
		stack<Info> st;
		st.push(Info(0,0));//替代frontLen,总是可以依次来

		int maxArea = 0;
		height.push_back(0);//这样就可以清空st
		len = height.size();

		for(int idx=0;idx<len;++idx) {
			if(st.empty() || st.top().ht <= height[idx]) {
				st.push(Info(idx,height[idx]));
			}else{//一直弹出到>=
				while(!st.empty() && st.top().ht >= height[idx]) {
					Info front = st.top();
					st.pop();

					if(!st.empty()) 
						maxArea = max(( idx - st.top().idx )*front.ht, maxArea);
					else
						maxArea = max(( idx - front.idx )*front.ht, maxArea);
				}
				if(st.empty()) 
					st.push(Info(newFront, height[idx]));
				else
					st.push(Info(idx, height[idx]));//这里应该是实际位置+1
			}
		}
		return maxArea;
   	}
};

int main() {
	int arr[6] = {4,2,0,3,2,5};
	vector<int> v(arr,arr+6);
	Solution s;
	cout<<s.largestRectangleArea(v)<<endl;
}
