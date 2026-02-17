class Solution {
public:
    vector<string> readBinaryWatch(int turnedOn)
    {
        vector<string> ans;
        for(int hour=0;hour<12;hour++)
        {
            for(int minute=0;minute<60;minute++)
            {
                
                if(__builtin_popcount(hour)+__builtin_popcount(minute)==turnedOn)
                {
                    string time=to_string(hour)+":";
                    if(minute<10)
                    {
                        time+="0";
                    }
                    time+=to_string(minute);
                    ans.push_back(time);
                }
            }
        }
        return ans;
    }
};
