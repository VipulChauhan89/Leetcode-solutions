class Solution {
public:
    bool find132pattern(vector<int> &nums) 
    {
        int length=nums.size(),maxThirdElement=INT_MIN;;
        if(length<3)
        {
            return false;
        }
        stack<int> decreasingStack;
        for(int i=length-1;i>=0;i--) 
        {
            int currentNumber=nums[i];
            if(currentNumber<maxThirdElement)
            {
                return true; 
            }
            while(!decreasingStack.empty() && decreasingStack.top()<currentNumber) 
            {
                maxThirdElement=decreasingStack.top();
                decreasingStack.pop();
            }
            decreasingStack.push(currentNumber);
        }
        return false;
    }
};
