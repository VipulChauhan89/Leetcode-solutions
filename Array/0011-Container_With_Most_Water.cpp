class Solution {
public:
    int maxArea(vector<int> &height)
    {
        int n=height.size(),mx=INT_MIN;
        int l=0,r=n-1;
        while(l<r)
        {
            int current=min(height[l],height[r])*(r-l);
            mx=max(mx,current);
            if(height[l]<height[r])
            {
                l++;
            }
            else if(height[l]>height[r])
            {
                r--;
            }
            else
            {
                l++;
                r--;
            }
        }
        return mx;
    }
};
