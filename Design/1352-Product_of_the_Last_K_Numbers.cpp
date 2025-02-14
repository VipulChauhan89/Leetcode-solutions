class ProductOfNumbers {
public:
    vector<long long> arr;
    long long product=1;
    ProductOfNumbers() {}
    
    void add(int num) 
    {
        if(num==0)
        {
            arr.clear();
            product=1;
        }
        else
        {
            product*=num;
            arr.push_back(product);
        }
    }
    
    int getProduct(int k) 
    {
        if(arr.size()<k)
        {
            return 0;
        }
        if(arr.size()==k)
        {
            return arr.back();
        }
        return arr.back()/arr[arr.size()-k-1];
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */
