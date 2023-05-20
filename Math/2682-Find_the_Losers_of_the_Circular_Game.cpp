class Solution {
public:
    vector<int> circularGameLosers(int n, int k) 
    {
        vector<bool> visited(n+1);
        vector<int> ans;
        int current=1,turn=1;
        while(true)
        {
            visited[current]=true;
            int next=(current+k*turn)%n;
            if(next==0)
            {
                next=n;
            }
            if(visited[next]==true)
            {
                break;
            }
            current=next;
            turn++;
        }
        for(int i=1;i<=n;i++)
        {
            if(visited[i]==false)
            {
                ans.push_back(i);
            }
        }
        return ans;
        
    }
};
