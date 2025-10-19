class Solution {
public:
    string findLexSmallestString(string s,int a,int b)
    {
        unordered_set<string> visited;
        string smallest=s;
        queue<string> q;
        q.push(s);
        visited.insert(s);
        while(!q.empty())
        {
            string current=q.front();
            q.pop();
            if(current<smallest)
            {
                smallest=current;
            }
            string added=current;
            for(int i=1;i<added.size();i+=2)
            {
                added[i]=((added[i]-'0'+a)%10)+'0';
            }
            if(!visited.count(added))
            {
                visited.insert(added);
                q.push(added);
            }
            string rotated=current.substr(current.size()-b)+current.substr(0,current.size()-b);
            if(!visited.count(rotated))
            {
                visited.insert(rotated);
                q.push(rotated);
            }
        }
        return smallest;
    }
};
