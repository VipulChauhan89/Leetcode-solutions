class Solution {
public:
    int countSeniors(vector<string>& details) 
    {
        int count=0;
        for(string s:details)
        {
            if(atoi(s.substr(11, 2).c_str())>60)
            {
                count++;
            }
            
        }
        return count;
    }
};
