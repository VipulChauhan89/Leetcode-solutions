class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>> &mat,int k) 
    {
        vector<pair<int,int>> m;
        for(int i=0;i<mat.size();i++) 
        {
            m.push_back({accumulate(mat[i].begin(),mat[i].end(),0),i});
        }
        sort(m.begin(),m.end());
        vector<int> ans;
        for(int i=0;i<k;i++) 
        {
            ans.push_back(m[i].second);
        }
        return ans;
    }
};
