#include<iostream>
#include<vector>

using namespace std;

/*
 * Stack
 * We can use stack to store incieasing ladders, and when it runs into a smalller ladder, it spoil the rising. 
 * So, stop and calculate the existing height until previous ladder is smaller the this one.
 * After this, we move on.
 *
 * As to the two elements in stack, this means height[i] < height[i+1] and their middle are all above them.
 */
int largestRectangleArea(vector<int> &height) {
	stack<int> st;
	height.push_back(0);

	int maxArea;
	for(int i=0;i<height.size();i++){
		if(st.empty() || height[i] >= height[st.top()]){
			st.push(i);
		}else{
			int top = st.top();
			st.pop();

			maxArea = max(maxArea, st.empty() ? i : i-st.top() - 1);
		}
	}

	return maxArea; 
}

int main(){
	vector<int> height;
	height.push_back(2);
	height.push_back(1);
	height.push_back(5);
	height.push_back(6);
	height.push_back(2);
	height.push_back(3);

	cout<<largestRectangleArea(height)<<endl;
	return 0;
}
