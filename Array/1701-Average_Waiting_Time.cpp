class Solution {
public:
    double averageWaitingTime(vector<vector<int>> &customers) 
    {
        int n=customers.size(),finished=customers[0][0]+customers[0][1];
        double timeToWait=customers[0][1];
        for(int i=1;i<n;i++)
        {
            vector<int> times=customers[i];
            int arrival=times[0];
            int startCooking=max(arrival,finished);
            int end=startCooking+times[1];
            finished=end;
            timeToWait+=end-arrival;
        }
        return timeToWait/n;
    }
};
