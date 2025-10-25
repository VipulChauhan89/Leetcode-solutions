class Solution {
public:
    int ap(int lead,int last,int terms)
    {
        return (lead+last)*terms/2;
    }
    int totalMoney(int n)
    {
        auto [q,r]=div(n,7);
        return ap(28,28+(q-1)*7,q)+ap(q+1,q+r,r);
    }
};
