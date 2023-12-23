class Solution {
public:
    bool isPathCrossing(string path) {
        unordered_map<char,pair<int,int>> m;
        m['N']={0,1};
        m['S']={0,-1};
        m['W']={-1,0};
        m['E']={1,0};
        unordered_set<string> visited;
        visited.insert("0,0");
        int x=0,y=0;
        for(auto i:path)
        {
            pair<int,int> current=m[i];
            x+=current.first;
            y+=current.second;
            string s=to_string(x)+','+to_string(y);
            if(visited.find(s)!=visited.end())
            {
                return true;
            }
            else
            {
                visited.insert(s);
            }
        }
        return false;
    }
};
