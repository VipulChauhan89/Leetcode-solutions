class Solution {
public:
    string countOfAtoms(string formula) {
        stack<unordered_map<string,int>> st;
        st.push({});
        int i=0,n=formula.length();
        while(i<n) 
        {
            if(formula[i]=='(') 
            {
                st.push({});
                i++;
            } 
            else if(formula[i]==')') 
            {
                unordered_map<string,int> top=st.top();
                st.pop();
                i++;
                int start=i;
                while(i<n && isdigit(formula[i])) 
                {
                    i++;
                }
                int multiplier=start<i?stoi(formula.substr(start,i-start)):1;
                for(auto &kv:top) 
                {
                    st.top()[kv.first]+=kv.second*multiplier;
                }
            } 
            else 
            {
                int start=i++;
                while(i<n && islower(formula[i])) 
                {
                    i++;
                }
                string element=formula.substr(start,i-start);
                start=i;
                while(i<n && isdigit(formula[i])) 
                {
                    i++;
                }
                int count=start<i?stoi(formula.substr(start,i-start)):1;
                st.top()[element]+=count;
            }
        }
        unordered_map<string,int> result=st.top();
        vector<string> elements;
        for(auto &kv:result) 
        {
            elements.push_back(kv.first);
        }
        sort(elements.begin(),elements.end());
        string ans;
        for(const auto &element:elements) 
        {
            ans+=element;
            if(result[element]>1) 
            {
                ans+=to_string(result[element]);
            }
        }
        return ans;
    }
};
