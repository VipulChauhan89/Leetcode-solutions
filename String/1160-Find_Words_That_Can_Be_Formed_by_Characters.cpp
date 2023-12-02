class Solution {
public:
    int countCharacters(vector<string> &words,string chars) 
    {
        int ans=0;
        for(auto &i:words)
        {
            string temp=chars;
            bool found=true;
            for(auto j:i)
            {
                size_t pos=temp.find(j);
                if(pos!=string::npos)
                {
                    temp.erase(pos,1);
                }
                else
                {
                    found=false;
                    break;
                }
            }
            ans+=(found==true)?i.length():0;
        }   
        return ans;   
    }
};
