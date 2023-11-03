class Solution {
public:
    vector<string> buildArray(vector<int> &target,int n) 
    {
        vector<string> op;
        stack<int> s;
        int targetIndex=0;
        for(int i=1; i<=n;i++)
        {
            if(targetIndex==target.size())
            {
                break;
            }
            if(target[targetIndex]==i)
            {
                op.push_back("Push");
                targetIndex++;
            }
            else
            {
                op.push_back("Push");
                op.push_back("Pop");
            }
        }
        return op;
    }
};
