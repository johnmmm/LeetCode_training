#include <vector>
#include <unordered_map>
#include <iostream>
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

    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) 
    {
        ListNode* newone;
        ListNode* head = new ListNode(0);
        *head = *newone;
        if (l1 == NULL && l2 != NULL)
            return l2;
        else if (l1 != NULL && l2 == NULL)
            return l1;
        else if (l1 == NULL && l2 == NULL)
            return NULL;
        else
        {
            ListNode* tmp1 = new ListNode(0);
            ListNode* tmp2 = new ListNode(0);
            ListNode* tmpans = new ListNode(0);
            *tmp1 = *l1;
            *tmp2 = *l2;
            if (tmp1->val >= tmp2->val)
            {
                ListNode* newone = new ListNode(tmp2->val);
                head->next = newone;
                tmpans = newone;
                tmp2 = tmp2->next;
            }
            else
            {
                ListNode* newone = new ListNode(tmp1->val);
                head->next = newone;
                tmpans = newone;
                tmp1 = tmp1->next;
            }
            while (tmp1 != NULL || tmp2 != NULL)
            {
                if (tmp1 == NULL)
                {
                    ListNode* newone = new ListNode(tmp2->val);
                    tmpans->next = newone;
                    tmpans = newone;
                    tmp2 = tmp2->next;
                }
                else if (tmp2 == NULL)
                {
                    ListNode* newone = new ListNode(tmp1->val);
                    tmpans->next = newone;
                    tmpans = newone;
                    tmp1 = tmp1->next;
                }
                else
                {
                    if (tmp1->val >= tmp2->val)//2
                    {
                        ListNode* newone = new ListNode(tmp2->val);
                        tmpans->next = newone;
                        tmpans = newone;
                        tmp2 = tmp2->next;
                    }
                    else
                    {
                        ListNode* newone = new ListNode(tmp1->val);
                        tmpans->next = newone;
                        tmpans = newone;
                        tmp1 = tmp1->next;
                    }
                }
            }
            return head->next;
        }
    }
};

int main()
{
    
    // ListNode* newlist;
    // newlist = new ListNode(1);
    ListNode* head1 = new ListNode(0);
    ListNode* head2;
    //ListNode* tmpnode(head);
    ListNode* tmpone1 = new ListNode(0);
    ListNode* tmpone2;
    printf("???\n");
    int examples1[3] = {1,2,4};
    int examples2[3] = {1,3,4};
    for (int i = 0; i < 3; i ++)
    {
        ListNode* newone1;
        newone1 = new ListNode(examples1[i]);
        if (i == 0)
        {
            printf("???\n");
            head1->next = newone1;
            printf("???\n");
            tmpone1 = newone1;
            printf("???\n");
        }
        else
        {
            tmpone1->next = newone1;
            tmpone1 = newone1;
        }
    }

    Solution solution;
    ListNode* result = new ListNode(0);
    *result = *solution.mergeTwoLists(head1, head2);
    *result = *head1;
    while (result != NULL)
    {
        //printf("???\n");
        //cout << result->val << endl;
        printf("%d->", result->val);
        result = result->next;
    }
    printf("\n");
    return 0;
}