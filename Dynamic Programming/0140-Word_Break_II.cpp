class Solution {
public:
    void backtrack(string s,unordered_set<string> &words,string sentence, vector<string> &ans,int start,int offset) 
    {
        string sub=s.substr(start,offset);
        if(start+offset==s.length()) 
        {
            if(words.find(sub)!=words.end()) 
            {
                sentence+=sub;
                ans.push_back(sentence);
            }
            return;
        }
        if(words.find(sub)!=words.end()) 
        {
            string newSentence=sentence+sub+" ";
            backtrack(s,words,newSentence,ans,start+offset,1);
        }
        backtrack(s,words,sentence,ans,start,offset+1);
    }
    vector<string> wordBreak(string s,vector<string> &wordDict) 
    {
        vector<string> ans;
        unordered_set<string> words(wordDict.begin(),wordDict.end());
        backtrack(s,words,"",ans,0,1);
        return ans;
    }
};
