class Solution {
public:
    int backtrack(string &tiles,vector<bool> &visited)
    {
        int n=tiles.size(),count=0;
        for(int i=0;i<n;i++)
        {
            if(visited[i] || (i>0 && tiles[i]==tiles[i-1] && !visited[i-1]))
            {
                continue;
            }
            visited[i]=true;
            count+=1+backtrack(tiles,visited);
            visited[i]=false;
        }
        return count;
    }
    int numTilePossibilities(string tiles) 
    {
        sort(tiles.begin(),tiles.end());
        vector<bool> visited(tiles.size(),false);
        return backtrack(tiles,visited);
    }
};
