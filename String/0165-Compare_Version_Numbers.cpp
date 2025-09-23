class Solution {
public:
    int compareVersion(string version1,string version2)
    {
        stringstream s1(version1),s2(version2);
        string t1,t2;
        while(true)
        {
            t1.clear();
            t2.clear();
            bool ok1=static_cast<bool>(getline(s1,t1,'.')),ok2=static_cast<bool>(getline(s2,t2,'.'));
            if(!ok1 && !ok2)
            {
                break;
            }
            int num1=t1.empty()?0:stoi(t1),num2=t2.empty()?0:stoi(t2);
            if(num1<num2)
            {
                return -1;
            }
            else if(num1>num2)
            {
                return 1;
            }
        }
        return 0;
    }
};
