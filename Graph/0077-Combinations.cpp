class Solution {
public:
    vector<vector<int>> ans;
    void solution(vector<int> &arr,int i,int g,int j,int n)
    {
        if(arr.size()==g)
        {
            ans.push_back(arr);
            return;
        }
        for(int k=n+1;k<=i;k++)
        {
            arr.push_back(k);
            solution(arr,i,g,j+1,k);
            arr.pop_back();
        }
    }
    vector<vector<int>> combine(int n,int k) 
    {
        vector<int> arr;
        solution(arr,n,k,0,0);
        return ans;
    }
};
