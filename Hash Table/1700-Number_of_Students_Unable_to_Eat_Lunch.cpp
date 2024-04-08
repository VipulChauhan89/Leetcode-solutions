class Solution {
public:
    int countStudents(vector<int> &students,vector<int> &sandwiches) 
    {
        vector<int> c(2,0);
        for(auto i:students)
        {
            c[i]++;
        }
        int rem=sandwiches.size();
        for(auto i:sandwiches)
        {
            if(c[i]==0 || rem==0)
            {
                break;
            }
            c[i]--;
            rem--;
        }
        return rem;
    }
};
