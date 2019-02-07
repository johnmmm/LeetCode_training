#include <vector>
#include <unordered_map>
#include <string>
#include <queue>
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

    vector<string> generateParenthesis(int n)
    {
        vector<string> strs;

        queue<string> tmp_strs;
        queue<int> tmp_len;
        queue<int> tmp_min;

        tmp_strs.push("(");
        tmp_len.push(1);
        tmp_min.push(1);

        while(tmp_len.front() < 2 * n && tmp_len.size() > 0)
        {
            string oldstr = tmp_strs.front();
            int oldlen = tmp_len.front();
            int oldmin = tmp_min.front();

            if (oldmin == 0)//平手
            {
                string newstr = oldstr + "(";
                tmp_strs.push(newstr);
                tmp_strs.pop();
                tmp_len.push(oldlen+1);
                tmp_len.pop();
                tmp_min.push(oldmin+1);
                tmp_min.pop();
                continue;
            }
            else if (oldlen + oldmin == n * 2)//结束
            {
                string newstr = oldstr;
                for (int i = 0; i < oldmin; i++)
                {
                    newstr = newstr + ")";
                }
                strs.push_back(newstr);
                //printf("%s , len: %d, min: %d\n", newstr.c_str(), oldlen, oldmin);
                tmp_strs.pop();
                tmp_len.pop();
                tmp_min.pop();
                continue;
            }
            else//平常增广
            {
                string newstr1 = oldstr + "(";
                tmp_strs.push(newstr1);
                tmp_len.push(oldlen+1);
                tmp_min.push(oldmin+1);
                
                string newstr2 = oldstr + ")";
                tmp_strs.push(newstr2);
                tmp_len.push(oldlen+1);
                tmp_min.push(oldmin-1);
                tmp_strs.pop();
                tmp_len.pop();
                tmp_min.pop();
                continue;
            }
        }

        return strs;
    }

};

int main ()
{
    Solution solution;
    FILE *fp = fopen("./in.txt", "r");
    fread(buf, 1, bufN, fp);

    int n = getint();
    vector<string> ans;
    ans = solution.generateParenthesis(n);
    // printf("%d\n", n);
    for (int i = 0; i < ans.size(); i++)
    {
        printf("%s\n", ans.at(i).c_str());
    }

    return 0;
}