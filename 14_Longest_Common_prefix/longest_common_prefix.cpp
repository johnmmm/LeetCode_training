#include <vector>
#include <unordered_map>
#include <string>
using namespace std;

const int bufN = 10000;
char buf[bufN], *p = buf;

inline int getint()
{
	while (*p < 48 || *p > 57)
		++p;

	int res = 0;
	while (*p > 47 && *p < 58)
		res = res * 10 + *p++ - 48;
	return res;
}

inline string getstring()
{
    string res;
    while(*p == ' ' || *p == '\n')
        ++p;
    while(*p != ' ' && *p != '\n')
		res += *p++;
    return res;
}

class Solution
{
public:
    Solution(){}

    string longestCommonPrefix(vector<string>& strs) 
    {
        string ans = "";
        if (strs.empty())
            return ans;
        int strsize = strs.size();
        vector<string> tmpstr = strs;
        bool flag = false;

        for (int i = 0; i < strsize; i++)
        {
            if (strs.at(i).size() == 0)
                flag = true;
        }

        while (!flag)
        {
            char tmpchar = tmpstr.at(0)[0];
            tmpstr.at(0) = tmpstr.at(0).substr(1);
            //printf("%c\n", tmpchar);
            for (int i = 1; i < strsize; i++)
            {
                if (tmpstr.at(i)[0] != tmpchar)
                {
                    flag = true;
                    break;
                }
                tmpstr.at(i) = tmpstr.at(i).substr(1);
            }
            if (!flag)
                ans += tmpchar;
            for (int i = 0; i < strsize; i++)
            {
                if (tmpstr.at(i).size() == 0)
                    flag = true;
            }
        }
        return ans;
    }
};

int main ()
{
    Solution solution;
    FILE *fp = fopen("./in.txt", "r");
    fread(buf, 1, bufN, fp);

    int n = getint();
    vector<string> strs;
    for (int i = 0; i < n; i++)
    {
        string tmp = getstring();
        strs.push_back(tmp);
    }
    string ans = solution.longestCommonPrefix(strs);
    printf("%s\n", ans.c_str());

    return 0;
}