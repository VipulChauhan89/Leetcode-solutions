class Solution {
public:
    int totalMoney(int n) 
    {
        int week_count=n/7,remaining=n%7;
        int total=((week_count *(week_count-1))/2)*7;
        total+=week_count*28;
        total+=((remaining*(remaining+1))/2)+(week_count*remaining);
        return total;
    }
};
