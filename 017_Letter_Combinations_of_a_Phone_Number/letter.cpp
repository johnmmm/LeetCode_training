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

    vector<string> letterCombinations(string digits) 
    {
        int size = digits.size();
        vector<string> ans;
        if (size == 0)
            return ans;
        
        vector<string> conststr;
        conststr.push_back("abc");
        conststr.push_back("def");
        conststr.push_back("ghi");
        conststr.push_back("jkl");
        conststr.push_back("mno");
        conststr.push_back("pqrs");
        conststr.push_back("tuv");
        conststr.push_back("wxyz");
        int totalsize[size];
        int tmpsize[size];
        int intstr[size];
        
        for (int i = 0; i < size; i++)
        {
            if (digits.c_str()[i] == '7' || digits.c_str()[i] == '9')
                totalsize[i] = 4;
            else
                totalsize[i] = 3;
            tmpsize[i] = 0;
            intstr[i] = digits.c_str()[i] - 48 - 2;
        }
        while (tmpsize[0] < totalsize[0])
        {
            string tmpans = "";
            for (int i = 0; i < size; i++)
            {
                tmpans += conststr[intstr[i]].c_str()[tmpsize[i]];
            }
            tmpsize[size-1]++;
            ans.push_back(tmpans);
            for (int i = size-1; i > 0; i--)
            {
                if (tmpsize[i] == totalsize[i])
                {
                    tmpsize[i] = 0;
                    tmpsize[i-1]++;
                }
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

    string digits = getstring();
    vector<string> ans = solution.letterCombinations(digits);
    for (int i = 0; i < ans.size(); i++)
        printf("%s ", ans[i].c_str());
    printf("\n");

    return 0;
}