class Fancy {
public:
    long MOD=1e9+7;
    vector<long> raw;
    long mult=1,add=0;

    long modinv(long x)
    {
        long ans=1,p=MOD-2;
        while(p)
        {
            if(p&1)
            {
                ans=ans*x%MOD;
            }
            x=x*x%MOD;
            p>>=1;
        }
        return ans;
    }

    Fancy() {
        
    }
    
    void append(int val)
    {
        long base=(val-add)%MOD;
        base=base*modinv(mult)%MOD;
        raw.push_back((base+MOD)%MOD);
    }
    
    void addAll(int inc)
    {
        add=(add+inc)%MOD;
    }
    
    void multAll(int m)
    {
        mult=mult*m%MOD;
        add=add*m%MOD;
    }
    
    int getIndex(int idx)
    {
        if(idx>=raw.size())
        {
            return -1;
        }
        return (raw[idx]*mult+add)%MOD;
    }
};

/**
 * Your Fancy object will be instantiated and called as such:
 * Fancy* obj = new Fancy();
 * obj->append(val);
 * obj->addAll(inc);
 * obj->multAll(m);
 * int param_4 = obj->getIndex(idx);
 */
