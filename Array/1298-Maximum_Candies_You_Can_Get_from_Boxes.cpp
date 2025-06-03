class Solution {
public:
    int maxCandies(vector<int> &status,vector<int> &candies,vector<vector<int>> &keys,vector<vector<int>> &containedBoxes,vector<int> &initialBoxes) 
    {
        bool open=true;
        int total=0;
        while(!initialBoxes.empty() && open)
        {
            open=false;
            vector<int> next;
            for(auto &i:initialBoxes)
            {
                if(status[i])
                {
                    open=true;
                    next.insert(next.end(),containedBoxes[i].begin(),containedBoxes[i].end());
                    for(auto &j:keys[i])
                    {
                        status[j]=1;
                    }
                    total+=candies[i];
                }
                else
                {
                    next.push_back(i);
                }
            }
            swap(initialBoxes,next);
        }
        return total;
    }
};
