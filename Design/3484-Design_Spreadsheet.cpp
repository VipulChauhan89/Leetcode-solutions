class Spreadsheet {
public:
    unordered_map<string,int> m;
    Spreadsheet(int rows)
    {

    }
    
    void setCell(string cell,int value)
    {
        m[cell]=value;
    }
    
    void resetCell(string cell)
    {
        m[cell]=0;
    }
    
    int getValue(string formula)
    {
        formula=formula.substr(1);
        for(int i=0;i<formula.size();i++)
        {
            if(formula[i]=='+')
            {
                string s1=formula.substr(0,i),s2=formula.substr(i+1);
                int left=s1[0]>='A' && s1[0]<='Z'?m[s1]:stoi(s1);
                int right=s2[0]>='A' && s2[0]<='Z'?m[s2]:stoi(s2);
                return left+right;
            }
        }
        return 0;
    }
};

/**
 * Your Spreadsheet object will be instantiated and called as such:
 * Spreadsheet* obj = new Spreadsheet(rows);
 * obj->setCell(cell,value);
 * obj->resetCell(cell);
 * int param_3 = obj->getValue(formula);
 */
