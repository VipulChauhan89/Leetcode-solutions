class Solution {
public:
    vector<bool> checkArithmeticSubarrays(vector<int> &nums,vector<int> &l, vector<int> &r) 
    {
        vector<bool> ans;
        for(int i=0;i<l.size();i++)
        {
            bool check=true;
            int left=l[i],right=r[i];
            vector<int> temp=nums;
            sort(temp.begin()+left,temp.begin()+right+1);
            int diff=abs(temp[left]-temp[++left]);
            for(;left<right;left++)
            {
                if(abs(temp[left]-temp[left+1])!=diff)
                {
                    check=false;
                    break;
                }
            }
            ans.push_back(check);
        }   
        return ans; 
    }
};
