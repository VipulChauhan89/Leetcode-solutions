class Solution {
public:
    int longestBalanced(vector<int>& nums) {
        int BLOCK_SIZE=200,n=nums.size(),numBlocks=(n+BLOCK_SIZE-1)/BLOCK_SIZE,maxLength=0;
        vector<int> lazyBlockAdd(numBlocks,0),prefixBalance(n,0);
        vector<vector<int>> blockFirstIndex(numBlocks,vector<int>(n*2+1,(int)1e9));
        unordered_map<int,int> lastSeenIndex;
        for(int right=0;right<n;right++)
        {
            int left=lastSeenIndex.count(nums[right])?lastSeenIndex[nums[right]]+1:0;
            int balanceDelta=(nums[right]%2?-1:+1),leftBlock=left/BLOCK_SIZE,rightBlock=right/BLOCK_SIZE;
            for(int block=leftBlock;block<=rightBlock;block++)
            {
                if(block==leftBlock || block==rightBlock)
                {
                    for(int i=min(block*BLOCK_SIZE+BLOCK_SIZE-1,n-1);i>=block*BLOCK_SIZE;i--)
                    {
                        blockFirstIndex[block][prefixBalance[i]+n]=1e9;
                    }
                    for(int i=min(block*BLOCK_SIZE+BLOCK_SIZE-1,n-1);i>=block*BLOCK_SIZE;i--)
                    {
                        if(i>=left && i<=right)
                        {
                            prefixBalance[i]+=balanceDelta;
                        }
                        blockFirstIndex[block][prefixBalance[i]+n]=i;
                    }
                }
                else
                {
                    lazyBlockAdd[block]+=balanceDelta;
                }
            }
            for(int block=0;block<=rightBlock;block++)
            {
                int targetIndex=-lazyBlockAdd[block]+n;
                maxLength=max(maxLength,right-blockFirstIndex[block][targetIndex]+1);
            }
            lastSeenIndex[nums[right]]=right;
        }
        return maxLength;
    }
};

