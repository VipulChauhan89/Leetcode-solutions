class Solution {
public:
    bool parseBoolExpr(string expression) 
    {
        stack<char> s;
        for(auto i:expression) 
        {
            if(i==',' || i=='(')
            {
                continue;
            }
            if(i=='t' || i=='f' || i=='!' || i=='&' || i=='|') 
            {
                s.push(i);
            }
            else if(i==')') 
            {
                bool hasTrue=false,hasFalse=false;
                while(s.top()!='!' && s.top()!='&' && s.top()!='|') 
                {
                    char topValue=s.top();
                    s.pop();
                    if(topValue=='t')
                    {
                        hasTrue=true;
                    } 
                    if(topValue=='f')
                    {
                        hasFalse=true;
                    } 
                }
                char op=s.top();
                s.pop();
                if(op=='!') 
                {
                    s.push(hasTrue?'f':'t');
                } 
                else if(op=='&') 
                {
                    s.push(hasFalse?'f':'t');
                } 
                else 
                {
                    s.push(hasTrue?'t':'f');
                }
            }
        }
        return s.top()=='t';
    }
};
