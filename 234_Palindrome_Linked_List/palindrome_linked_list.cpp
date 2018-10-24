#include <vector>
#include <unordered_map>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution 
{ 
public:
    Solution(){}

    bool isPalindrome(ListNode* head) 
    {
        if (head == NULL)
            return true;
        
        short linkedList[10000];
        int place = 0;
        ListNode* tmpnode;
        tmpnode = new ListNode(0);
        *tmpnode = *head;
        linkedList[place++] = head->val;
        while(tmpnode->next != NULL)
        {
            (*tmpnode) = (*tmpnode->next);
            linkedList[place++] = tmpnode->val;
        }

        bool flag = true;
        for (int i = 0; i < place; i++)
        {
            if (linkedList[i] != linkedList[place-i-1])
                flag = false;
        }


        return flag;
    }
};

int main()
{
    
    printf("???\n");
    ListNode* newlist;
    printf("???\n");
    newlist = new ListNode(1);
    printf("???\n");
    ListNode* head(newlist);
    printf("???\n");
    //ListNode* tmpnode(head);
    ListNode* tmpone;
    tmpone = new ListNode(0);
    int examples[3] = {2,3,4};
    printf("???\n");
    for (int i = 0; i < 3; i ++)
    {
        ListNode* newone;
        newone = new ListNode(examples[i]);
        if (i == 0)
        {
            head->next = newone;
            tmpone = newone;
        }
        else
        {
            tmpone->next = newone;
            tmpone = newone;
        }
    }

    printf("%d\n", tmpone->val);
    Solution solution;
    solution.isPalindrome(head);

    return 0;
}