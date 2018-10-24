#include <vector>
#include <unordered_map>
#include <string>
using namespace std;

class Solution
{
public:
    Solution(){}

    int romanToInt(string s)
    {
        int sLong = s.size() - 1;
        int ans = 0;
        // if (s.c_str()[sLong] == 'V')
        //     printf("%c\n", s.c_str()[sLong-1]);
        while(sLong >= 0)
        {
            if (s.c_str()[sLong] == 'I')
            {
                ans += 1;
                sLong--;
                continue;
            }
            else if (s.c_str()[sLong] == 'V')
            {
                if (s.c_str()[sLong-1] == 'I')
                {
                    ans += 4;
                    sLong--;
                    sLong--;
                    continue;
                }
                else
                {
                    ans += 5;
                    sLong--;
                    continue;
                }
            }
            else if (s.c_str()[sLong] == 'X')
            {
                if (s.c_str()[sLong-1] == 'I')
                {
                    ans += 9;
                    sLong--;
                    sLong--;
                    continue;
                }
                else
                {
                    ans += 10;
                    sLong--;
                    continue;
                }
            }
            else if (s.c_str()[sLong] == 'L')
            {
                if (s.c_str()[sLong-1] == 'X')
                {
                    ans += 40;
                    sLong--;
                    sLong--;
                    continue;
                }
                else
                {
                    ans += 50;
                    sLong--;
                    continue;
                }
            }
            else if (s.c_str()[sLong] == 'C')
            {
                if (s.c_str()[sLong-1] == 'X')
                {
                    ans += 90;
                    sLong--;
                    sLong--;
                    continue;
                }
                else
                {
                    ans += 100;
                    sLong--;
                    continue;
                }
            }
            else if (s.c_str()[sLong] == 'D')
            {
                if (s.c_str()[sLong-1] == 'C')
                {
                    ans += 400;
                    sLong--;
                    sLong--;
                    continue;
                }
                else
                {
                    ans += 500;
                    sLong--;
                    continue;
                }
            }
            else if (s.c_str()[sLong] == 'M')
            {
                if (s.c_str()[sLong-1] == 'C')
                {
                    ans += 900;
                    sLong--;
                    sLong--;
                    continue;
                }
                else
                {
                    ans += 1000;
                    sLong--;
                    continue;
                }
            }
            else
                sLong--;
        }
        return ans;
    }
};

int main ()
{
    Solution solution;
    string example = "MMCMXCIV";
    int ans = solution.romanToInt(example);
    printf("%d\n", ans);
    
    return 0;
}