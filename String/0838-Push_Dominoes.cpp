class Solution {
public:
    string pushDominoes(string dominoes) 
    {
        dominoes=dominoes+'R';
        char last='L';
        int n=dominoes.size(),lastIndex=-1;
        for(int i=0;i<n;i++) 
        {
            if(dominoes[i]=='L') 
            {
                if(last=='R') 
                {
                    int l=lastIndex+1,r=i-1;
                    while(l<r) 
                    {
                        dominoes[l++]='R';
                        dominoes[r--]='L';
                    }
                } 
                else if(last=='L') 
                {
                    for(int j=lastIndex+1;j<i;j++) 
                    {
                        dominoes[j]='L';
                    }
                }
                last='L';
                lastIndex=i;
            } 
            else if(dominoes[i]=='R') 
            {
                if(last=='R') 
                {
                    for(int j=lastIndex+1;j<i;j++) 
                    {
                        dominoes[j]='R';
                    }
                }
                last='R';
                lastIndex=i;
            }
        }
        return dominoes.substr(0,n-1);
    }
};
