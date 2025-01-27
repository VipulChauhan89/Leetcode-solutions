class Solution {
public:
    vector<bool> checkIfPrerequisite(int numCourses,vector<vector<int>> &prerequisites,vector<vector<int>> &queries) 
    {
       vector<vector<bool>> G(numCourses,vector<bool>(numCourses,false));
        vector<bool> ans;
        for(auto &i:prerequisites) 
        {
            G[i[0]][i[1]]=true;
        }
        for(int i=0;i<numCourses;i++) 
        {
            for(int src=0;src<numCourses;src++) 
            {
                for(int target=0;target<numCourses;target++) 
                {
                    G[src][target]=G[src][target] || (G[src][i] && G[i][target]);
                }
            }
        }
        for(auto &i:queries) 
        {
            ans.push_back(G[i[0]][i[1]]);
        }
        return ans;
    }
};
