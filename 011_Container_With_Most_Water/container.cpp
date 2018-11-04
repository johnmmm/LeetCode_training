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

    int calculate(int place1, int place2, int height1, int height2)
    {
        return min(height1, height2) * (place2 - place1);
    }

    int maxArea(vector<int>& height) 
    {
        int size = height.size();
        if (size == 0 || size == 1)
            return 0;
        
        int ans = 0;

        int l = 0, r = size-1;
        int flag = true;
        while (l < r)
        {
            int tmpans = calculate(l, r, height[l], height[r]);
            if (tmpans > ans)
                ans = tmpans;
            
            if (height[l] > height[r])
                flag = true;
            else if (height[l] < height[r])
                flag = false;

            if (flag)
                r--;
            else 
                l++;
        }

        return ans;
    }
};

int main()
{
    FILE *fp = fopen("./in.txt", "r");
    fread(buf, 1, bufN, fp);

    int num = getint();
    vector<int> arrays;
    for (int i = 0; i < num; i++)
    {
        arrays.push_back(getint());
    }

    Solution solution;
    int ans = solution.maxArea(arrays);

    printf("%d\n", ans);

    return 0;
}