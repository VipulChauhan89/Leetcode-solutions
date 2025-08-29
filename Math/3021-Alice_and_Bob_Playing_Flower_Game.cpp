class Solution {
public:
    long long flowerGame(int n,int m)
    {
        long long odx=(n+1)/2,evx=n/2,ody=(m+1)/2,evy=m/2;
        return (odx*evy)+(evx*ody);
    }
};
