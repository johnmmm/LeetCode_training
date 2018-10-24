#include <vector>
#include <unordered_map>
using namespace std;

const int bufN = 1000;
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

class Solution 
{ 
public:
    Solution(){}

    bool isPalindrome(int x) 
    {
        if (x < 0)
            return false;

        int tmpx = x;
        int tmp10 = 10;
        int places = 0;
        for (int i = 1; i < 10; i++)
        {
            if (tmpx == (tmpx % tmp10) )
            {
                places = i;
                break;
            } 
            tmp10 *= 10;
        }  
        if (places == 0)
            places = 10;
        int reverseNum = 0;  
        for (int i = 0; i < places; i++)
        {
            int tmpplace = tmpx % 10;
            tmpx /= 10;
            reverseNum *= 10;
            reverseNum += tmpplace;
        }
        
        //printf("%d\n", reverseNum);
        if (reverseNum == x)
            return true;
        return false;
    }
};

int main()
{
    FILE *fp = fopen("./in.txt", "r");
    fread(buf, 1, bufN, fp);

    Solution solution;
    int num = getint();
    for (int i = 0; i < num; i++)
    {
        int palindrome = getint();
        printf("%d\n", solution.isPalindrome(palindrome));
    }

    return 0;
}