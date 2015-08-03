#include<iostream>
#include<stack>
#include<vector>
using namespace std;

/*struct Info {
	int idx;
	int height;
	Info(int i,int h) : idx(i),height(h) {}
};*/

class Solution {
	public:
		void show(int* v,int n){
			for(int i=0;i<n;++i)
				cout<<v[i];
			cout<<endl;
		}

		int maximalRectangle(vector<vector<char> > &matrix) {
			if(matrix.empty()) return 0;

			const int m = matrix.size();
			const int n = matrix[0].size();
			int left[n], right[n], height[n];
			fill_n(left,n,0); fill_n(right,n,n); fill_n(height,n,0);
			int maxA = 0;
			for(int i=0; i<m; i++) {
				int cur_left=0, cur_right=n; 
				for(int j=0; j<n; j++) { // compute height (can do this from either side)
					if(matrix[i][j]=='1') height[j]++; 
					else height[j]=0;
				}
				show(height,n);

				for(int j=0; j<n; j++) { // compute left (from left to right)
					if(matrix[i][j]=='1') left[j]=max(left[j],cur_left);
					else {left[j]=0; cur_left=j+1;}
				}
				show(left,n);

				// compute right (from right to left)
				for(int j=n-1; j>=0; j--) {
					if(matrix[i][j]=='1') right[j]=min(right[j],cur_right);
					else {right[j]=n; cur_right=j;}    
				}
				show(right,n);
				cout<<endl;

				// compute the area of rectangle (can do this from either side)
				for(int j=0; j<n; j++)
					maxA = max(maxA,(right[j]-left[j])*height[j]);
			}
			return maxA;
		}
};
/*
class Solution {
	public:
		int getMaxArea(vector<int>& steps) {
			stack<Info> st;
			st.push(Info(0,0));

			int maxArea = 0;
			steps.push_back(0);
			for(int i=0;i<steps.size();++i) {
				if(st.empty() || steps[i] >= st.top().height)
					st.push(Info(i+1,steps[i]));
				else {
					while(!st.empty() && steps[i] < st.top().height) {
						//the last 0 would clear all the front
						Info tinfo = st.top();
						st.pop();

						maxArea = max(maxArea, (i-st.top().idx) * tinfo.height);
					}
					st.push(Info(i+1,steps[i]));
				}
			}
			return maxArea;
		}

		int maximalRectangle(vector<vector<char> >& matrix) {
			int cols = matrix.size();
			if(cols == 0)	return 0;
			int rows = matrix[0].size();
			if(rows == 0)	return 0;

			vector<int> steps(rows,0);

			int maxArea = 0;
			for(int i=0;i<cols;++i) {
				for(int j=0;j<rows;++j) {
					if(matrix[i][j] == '0')
						steps[j] = 0;
					else
						steps[j] += 1;
				}
				maxArea = max(maxArea, getMaxArea(steps));
			}
			return maxArea;
		}
};*/
int main(){
	char arr1[4] = {'0','1','1','0'};
	char arr2[4] = {'1','0','1','0'};
	char arr3[4] = {'0','1','1','1'};
	char arr4[4] = {'0','1','1','1'};
	vector<char> v1(arr1,arr1+4);
	vector<char> v2(arr2,arr2+4);
	vector<char> v3(arr3,arr3+4);
	vector<char> v4(arr4,arr4+4);
	vector<vector<char> > v;
	v.push_back(v1);	
	v.push_back(v2);	
	v.push_back(v3);	
	v.push_back(v4);	

	Solution s;
	cout<<s.maximalRectangle(v)<<endl;
}
