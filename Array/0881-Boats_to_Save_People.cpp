class Solution {
public:
    int numRescueBoats(vector<int> &people,int limit) 
    {
        sort(people.begin(),people.end());
        int l=0,h=people.size()-1;
        int numBoats=0;
        while(l<=h)
        {
            if(people[l]+people[h]<=limit)
            {
                l++;
            }
            h--;
            numBoats++;
        }
        return numBoats;
    }
};
