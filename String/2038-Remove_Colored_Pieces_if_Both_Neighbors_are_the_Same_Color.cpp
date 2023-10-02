class Solution {
public:
    bool winnerOfGame(string colors) 
    {
        int aliceScore=0,bobScore=0;
        for(int i=1;i<colors.size()-1;i++) 
        {
            char currentColor=colors[i],prevColor=colors[i-1],nextColor=colors[i+1];
            if(currentColor=='A' && prevColor=='A' && nextColor=='A')
            {
                aliceScore++;
            }
            else if(currentColor=='B' && prevColor=='B' && nextColor=='B')
            {
                bobScore++;
            }
        }
        return aliceScore>bobScore;
    }
};
