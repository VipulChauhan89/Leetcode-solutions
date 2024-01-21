class Solution {
public:
    int minimumPushes(string word) 
    {
        unordered_map<char,int> m;
        vector<char> v;
        int push=0,pos=1,num=2;
        for(auto i:word) 
        {
            m[i]++;
        }
        for(auto &i:m) 
        {
            v.push_back(i.first);
        }
        sort(v.begin(),v.end(),[&](char a,char b) {
            return m[a]>m[b];
        });
        for(auto i:v) 
        {
            push+=m[i]*pos;
            if(num<9) 
            {
                num++;
            } 
            else 
            {
                num=2;
                pos++;
            }
        }
        return push;
    }
};
