#include<iostream>
#include<vector>
using namespace std;

/*
 * 因为只有两个的高度合适，构成一个桶，才能积攒水。
 * 1） 可以寻找最高的位置后，其他的位置都能依赖它而积攒水分
 * 2） 每次比较当前left，right的较小值，因为这个最小值可能和已存在本侧的max和较大值来组成挡板。这里有个潜在的条件，因为每次处理的都是较小的方向，所以当height[left] < height[right]时，maxLeft一定是小于heigth[right]的
 */

class Solution {
		int len;
public:
        /*
         * Because the water was constrained by two side of flap
         * It's covenient to get the max height, which means the other height can depend on it 
         */
	    int trap(vector<int>& height) {
			len = height.size();
			if(len == 0)	return 0;

			int MaxheightIdx = 0;//Get the max height for safety
			int currMaxHeight = height[0];
			for(int idx = 1;idx < len;++idx){
					if(currMaxHeight < height[idx]){
							currMaxHeight = height[idx];
                            MaxheightIdx = idx;
                    }
            }

            int result = 0;

            //we check the front part
            int partlyMaxHeight = height[0];
            int containedWater = 0;
            for(int idx = 1;idx <= MaxheightIdx; ++idx){
                    if(height[idx] < partlyMaxHeight)
                            containedWater += partlyMaxHeight - height[idx];
                    else{
                            result += containedWater;
                            containedWater = 0;
                            partlyMaxHeight = height[idx];
                    }
            }

            //we then check the back part
            partlyMaxHeight = height[len-1];
            containedWater = 0;
            for(int idx = len-2; idx >= MaxheightIdx; --idx){
                    if(height[idx] < partlyMaxHeight)
                            containedWater += partlyMaxHeight - height[idx];
                    else{
                            result += containedWater;
                            containedWater = 0;
                            partlyMaxHeight = height[idx];
                    }
            }
            return result;
    	}
};
int main(){
		int  arr[12] = {0,1,0,2,1,0,1,3,2,1,2,1};
		vector<int> v(arr,arr+12);
		Solution s;
		cout<<s.trap(v);
}
