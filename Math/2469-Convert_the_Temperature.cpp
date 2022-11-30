class Solution {
public:
    vector<double> convertTemperature(double celsius) 
    {
        vector<double> v;
        v.push_back(celsius+273.15);
        v.push_back((celsius*9/5)+32);
        return v;
    }
};
