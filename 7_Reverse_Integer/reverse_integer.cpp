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

    int reverse(int x)
    {
        int tmpx = x;
        if (x > 0)
        {
            is_mine = true;
        }
        else if (x < 0)
        {
            is_mine = false;
            if (x == -2147483648)
                return 0;
            else
                tmpx = -tmpx;
        }
        else
            return 0;
        
        int num_array[30];
        int ans = 0;
        int array_long = 0;
        while(tmpx > 0)
        {
            num_array[array_long++] = tmpx % 10;
            tmpx /= 10;
            //printf("tmpx:%d\n", tmpx);
        }
        //若判定成功
        int tmp_ans = 0;
        for (int i = 0; i < array_long; i++)
        {
            tmp_ans = ans;
            ans *= 10;
            if (ans / 10 != tmp_ans)
                return 0;
            ans += num_array[i];
        }
        if (!is_mine)
            ans = -ans;
        return ans;
    }

private:
    bool is_mine;
};

int main ()
{
    FILE *fp = fopen("./in.txt", "r");
    fread(buf, 1, bufN, fp);

    int total_num = 0;
    total_num = getint();
    Solution solution;
    int ans = 0;
    for (int i = 0; i < total_num; i++)
    {
        ans = solution.reverse(getint());
        printf("%d\n", ans);
    }
    ans = solution.reverse(-1233211231);
    printf("%d\n", ans);
    return 0;
}