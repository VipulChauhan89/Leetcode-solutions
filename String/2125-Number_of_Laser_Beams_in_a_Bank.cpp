class Solution {
public:
    int numberOfBeams(vector<string> &bank) 
    {
        int prevRowCount=0,total=0;
        for(auto row:bank) 
        {
            int curRowCount=calc(row);
            if(curRowCount==0)
            {
                continue;
            }
            total+=curRowCount*prevRowCount;
            prevRowCount=curRowCount;
        }
        return total;
    }
    int calc(string &s) 
    {
        int count=0;
        for(auto c:s)
        {
            count+=c-'0';
        }
        return count;
    }
};
