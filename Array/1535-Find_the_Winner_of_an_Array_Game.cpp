class Solution {
public:
    int getWinner(vector<int> &arr,int k) 
    {
        if(k==1)
        {
            return max(arr[0],arr[1]);
        }
        if(k>=arr.size())
        {
            return *max_element(arr.begin(),arr.end());
        }
        int current_winner=arr[0],consecutive_wins=0;
        for(int i=1;i<arr.size();i++)
        {
            if(current_winner>arr[i])
            {
                consecutive_wins++;
            }
            else
            {
                current_winner=arr[i];
                consecutive_wins=1;
            }
            if(consecutive_wins==k)
            {
                return current_winner;
            }
        }
        return current_winner;
    }
};
