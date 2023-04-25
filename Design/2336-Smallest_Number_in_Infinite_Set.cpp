class SmallestInfiniteSet {
public:
    vector<bool> v;
    SmallestInfiniteSet() 
    {
        v.resize(1001);
        for(int i=1;i<1001;i++)
        {
            v[i]=true;
        }
    }
    
    int popSmallest() 
    {
        int i=1;
        while(v[i]!=true)
        {
            i++;
        }
        v[i]=false;
        return i;
    }
    
    void addBack(int num) 
    {
        v[num]=true;
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */
