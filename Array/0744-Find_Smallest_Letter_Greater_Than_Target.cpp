class Solution {
public:
    char nextGreatestLetter(vector<char> &letters, char target) 
    {
        int l=0,h=letters.size()-1;
        while(l<h)
        {
            int mid=l+(h-l)/2;
            if(letters[mid]<=target)
            {
                l=mid+1;
            }
            else
            {
                h=mid;
            }
        }
        return letters[l]>target?letters[l]:letters[0];
        
    }
};
