#include<iostream>
#include<vector>
using namespace std;

/*
 * ��Ϊֻ�������ĸ߶Ⱥ��ʣ�����һ��Ͱ�����ܻ���ˮ��
 * 1�� ����Ѱ����ߵ�λ�ú�������λ�ö���������������ˮ��
 * 2�� ÿ�αȽϵ�ǰleft��right�Ľ�Сֵ����Ϊ�����Сֵ���ܺ��Ѵ��ڱ����max�ͽϴ�ֵ����ɵ��塣�����и�Ǳ�ڵ���������Ϊÿ�δ���Ķ��ǽ�С�ķ������Ե�height[left] < height[right]ʱ��maxLeftһ����С��heigth[right]��
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
