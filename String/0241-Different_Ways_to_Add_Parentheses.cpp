class Solution {
public:
    int solve(int x,int y,char z)
    {
        if(z=='+')
        {
            return x+y;
        }
        else if(z=='-')
        {
            return x-y;
        }
        else if(z=='*')
        {
            return x*y;
        }
        return 0;
    }
    vector<int> diffWaysToCompute(string expression) 
    {
        vector<int> ans;
        bool isNumber=true;
        for(int i=0;i<expression.size();i++)
        {
            if(!isdigit(expression[i]))
            {
                isNumber=false;
                vector<int> l=diffWaysToCompute(expression.substr(0,i)),r=diffWaysToCompute(expression.substr(i+1));
                for(auto j:l)
                {
                    for(auto k:r)
                    {
                        ans.push_back(solve(j,k,expression[i]));
                    }
                }
            }
        }
        if(isNumber)
        {
            ans.push_back(stoi(expression));
        }
        return ans;
    }
};
