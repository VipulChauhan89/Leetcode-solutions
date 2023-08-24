class Solution {
public:
    vector<string> fullJustify(vector<string> &words,int maxWidth) 
    {
        vector<string> res,cur;
        int num_of_letters=0;
        for(auto word:words) 
        {
            if(word.size()+cur.size()+num_of_letters>maxWidth) 
            {
                for(int i=0;i<maxWidth-num_of_letters;i++) 
                {
                    cur[i%(cur.size()-1?cur.size()-1:1)]+=' ';
                }
                res.push_back("");
                for(auto s:cur)
                {
                    res.back()+=s;
                } 
                cur.clear();
                num_of_letters=0;
            }
            cur.push_back(word);
            num_of_letters+=word.size();
        }
        string last_line="";
        for(auto s:cur)
        {
            last_line+=s+' ';
        } 
        last_line=last_line.substr(0,last_line.size()-1);
        while(last_line.size()<maxWidth)
        {
            last_line+=' ';
        } 
        res.push_back(last_line);
        return res;
    }
};
