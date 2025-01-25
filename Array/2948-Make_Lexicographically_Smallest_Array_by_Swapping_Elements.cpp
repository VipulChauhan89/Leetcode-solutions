class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int> &nums,int limit) 
    {
        int n=nums.size(),gn=0;
        unordered_map<int,queue<int>> m1;
        unordered_map<int,int> m2;
        vector<int> temp=nums;
        sort(temp.begin(),temp.end());
        m2[temp[0]]=gn;
        m1[gn].push(temp[0]);
        for(int i=1;i<n;i++)
        {
            if(abs(temp[i]-temp[i-1])<=limit)
            {
                m1[gn].push(temp[i]);
                m2[temp[i]]=gn;
            }
            else
            {
                gn++;
                m1[gn].push(temp[i]);
                m2[temp[i]]=gn;
            }
        }
        for(int i=0;i<n;i++)
        {
            int num=nums[i];
            nums[i]=m1[m2[nums[i]]].front();
            m1[m2[nums[i]]].pop();
        }
        return nums;
    }
};
