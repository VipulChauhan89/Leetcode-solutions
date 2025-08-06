class Solution {
public:
    int n;
    vector<int> seg;
    void Update(int p)
    {
        seg[p]=max(seg[p<<1],seg[p<<1|1]);
    }

    void Build(int p,int l,int r,vector<int> &b)
    {
        if(l==r)
        {
            seg[p]=b[l];
            return;
        }
        int m=(l+r)>>1;
        Build(p<<1,l,m,b);
        Build(p<<1|1,m+1,r,b);
        Update(p);
    }

    void Assign(int x,int v,int p,int l,int r)
    {
        if(x<l || x>r)
        {
            return;
        }
        if(l==r)
        {
            seg[p]=v;
            return;
        }
        int m=(l+r)>>1;
        Assign(x,v,p<<1,l,m);
        Assign(x,v,p<<1|1,m+1,r);
        Update(p);
    }

    int Find(int v,int p,int l,int r)
    {
        if(seg[p]<v)
        {
            return r+1;
        }
        if(l==r)
        {
            return r;
        }
        int m=(l+r)>>1;
        int lf=Find(v,p<<1,l,m);
        if(lf<=m)
        {
            return lf;
        }
        return Find(v,p<<1|1,m+1,r);
    }
    int numOfUnplacedFruits(vector<int> &f,vector<int> &b)
    {
        n=f.size();
        seg.assign(4 *n+1,0);
        Build(1,0,n-1,b);
        int c=0;
        for(auto x:f)
        {
            int i=Find(x,1,0,n-1);
            if(i==n)
            {
                c++;
            }
            else
            {
                Assign(i,0,1,0,n-1);
            }
        }
        return c;
    }
};
