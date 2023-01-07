class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) 
    {
        int total_Gas=0,current_Gas=0,ans=0;
        for(int i=0;i<gas.size();i++)
        {
            current_Gas+=gas[i]-cost[i];
            total_Gas+=gas[i]-cost[i];
            if(current_Gas<0)
            {
                current_Gas=0;
                ans=i+1;
            }
        }
        return (total_Gas<0)?-1:ans;
    }
};
