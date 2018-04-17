class Solution {
public:
	int maxArea(vector<int>& height) {
		int ans = 0;
		int i=0,j=height.size()-1;
		while(i<j){
			ans = max(ans,(j-i)*min(height[j],height[i]));
			if(height[i]<height[j]) i++;
			else j--;
		}
		
		return ans;
	}
};
/*
- from both side to the middle ,ok
- I can't find the transform condition
- why height[i]<height[j] is just fine?
*/