class Solution {
public:
	long long minimumReplacement(vector<int> &nums) 
	{
		int n=nums.size(),prev=nums[n-1];
		long long res=0;
		for(auto i=n-2;i>=0;i--)
    {
			int tmp=((long long)nums[i]+prev-1)/prev;
			if(nums[i]%prev)
      {
				prev=nums[i]/tmp;
			}
			res+=tmp-1;
		}
		return res;
	}
};
