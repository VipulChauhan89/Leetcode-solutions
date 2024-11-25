class Solution {
public:
    int slidingPuzzle(vector<vector<int>> &board) 
    {
        vector<vector<int>> dir={{1,3},{0,2,4},{1,5},{0,4},{1,3,5},{2,4}};
        string target="123450",start="";
        set<string> visited;
        queue<string> q;
        for(auto i:board) 
        {
            for(auto j:i) 
            {
                start+=j+'0';
            }
        }
        q.push(start);
        visited.insert(start);
        int step=0;
        while(!q.empty()) 
        {
            int size=q.size();
            while(size--) 
            {
                string current=q.front();
                q.pop();
                if(current==target)
                {
                    return step;
                } 
                int zero=current.find('0');
                for(auto i:dir[zero]) 
                {
                    string next=current;
                    swap(next[i],next[zero]);
                    if(!visited.count(next)) 
                    { 
                        visited.insert(next);
                        q.push(next);
                    }
                }
            }
            step++;
        }
        return -1;
    }
};
