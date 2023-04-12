class Solution {
public:
    string simplifyPath(string path) 
    {
        stringstream ss(path);
        string dir;
        stack<string> dirs;
        while(getline(ss, dir, '/')) 
        {
            if(dir=="" || dir==".") 
            {
                continue;
            }
            if(dir=="..") 
            {
                if(!dirs.empty()) 
                {
                    dirs.pop();
                }
                continue;
            }
            dirs.push(dir);
        }
        string result;
        while(!dirs.empty()) 
        {
            result="/"+dirs.top()+result;
            dirs.pop();
        }
        return result.empty()?"/":result;
    }
};
