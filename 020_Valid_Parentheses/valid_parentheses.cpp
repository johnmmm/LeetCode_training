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

    bool isValid(string s) 
    {
        int num1 = 0, num2 = 0, num3 = 0;
        int nums = s.size();
        short parstack[10000];
        int stackplace = 0;
        for (int i = 0; i < nums; i++)
        {
            if (s.c_str()[i] == '(' || s.c_str()[i] == '{' || s.c_str()[i] == '[')
            {
                int marks = 0;
                if (s.c_str()[i] == '(')
                    marks = 1;
                if (s.c_str()[i] == '{')
                    marks = 2;
                if (s.c_str()[i] == '[')
                    marks = 3;
                parstack[stackplace++] = marks;
            }

            if (s.c_str()[i] == ')' || s.c_str()[i] == '}' || s.c_str()[i] == ']')
            {
                if (stackplace == 0)
                    return false;
                int marks = 0;
                if (s.c_str()[i] == ')')
                    marks = 1;
                if (s.c_str()[i] == '}')
                    marks = 2;
                if (s.c_str()[i] == ']')
                    marks = 3;
                if (marks != parstack[stackplace-1])
                    return false;
                else
                    parstack[--stackplace] = 0;
            }
        }
        if (stackplace == 0)
            return true;
        return false;
    }
};

int main ()
{
    Solution solution;
    FILE *fp = fopen("./in.txt", "r");
    fread(buf, 1, bufN, fp);

    int n = getint();
    for (int i = 0; i < n; i++)
    {
        string tmp = getstring();
        bool isvalid = solution.isValid(tmp);
        printf("%d\n", isvalid);
    }

    return 0;
}