#include <vector>
#include <unordered_map>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
ListNode* head1 = new ListNode(0);
ListNode* head2 = new ListNode(0);
ListNode* head3 = new ListNode(0);

void buildList()
{
    int example1[3] = {2,4,7};
    int example2[6] = {5,6,2,9,9,1};
    int length1 = sizeof(example1) / sizeof(example1[0]);
    int length2 = sizeof(example2) / sizeof(example2[0]);
    ListNode* tmpnode = new ListNode(0);

    head1->val = example1[0];
    tmpnode = head1;
    for (int i = 1; i < length1; i++)
    {
        ListNode* newone = new ListNode(example1[i]);
        tmpnode->next = newone;
        tmpnode = newone;
    }

    head2->val = example2[0];
    tmpnode = head2;
    for (int i = 1; i < length2; i++)
    {
        ListNode* newone = new ListNode(example2[i]);
        tmpnode->next = newone;
        tmpnode = newone;
    }
}

void display(ListNode* listhead)
{
    ListNode* tmpnode = new ListNode(0);
    tmpnode = listhead;
    while(tmpnode != NULL)
    {
        printf("%d->", tmpnode->val);
        tmpnode = tmpnode->next;
    }
    printf("\n");
}

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) 
    {
        ListNode* newhead = new ListNode(0);
        ListNode* tmpnewhead = newhead;
        ListNode* tmpl1 = l1;
        ListNode* tmpl2 = l2;

        int addPlace;
        int valPlace;
        valPlace = (tmpl1->val + tmpl2->val) % 10;
        addPlace = (tmpl1->val + tmpl2->val) / 10;
        newhead->val = valPlace;

        while (tmpl1->next != NULL && tmpl2->next != NULL)
        {
            tmpl1 = tmpl1->next;
            tmpl2 = tmpl2->next;

            valPlace = (tmpl1->val + tmpl2->val + addPlace) % 10;
            addPlace = (tmpl1->val + tmpl2->val + addPlace) / 10;

            ListNode* newone = new ListNode(valPlace);
            tmpnewhead->next = newone;
            tmpnewhead = newone;
        }

        if (tmpl1->next == NULL && tmpl2->next == NULL)
        {

        }
        else if (tmpl1->next == NULL && tmpl2->next != NULL)
        {
            while (tmpl2->next != NULL)
            {
                tmpl2 = tmpl2->next;
                valPlace = (tmpl2->val + addPlace) % 10;
                addPlace = (tmpl2->val + addPlace) / 10;

                ListNode* newone = new ListNode(valPlace);
                tmpnewhead->next = newone;
                tmpnewhead = newone;
            }
        }
        else if (tmpl1->next != NULL && tmpl2->next == NULL)
        {
            while (tmpl1->next != NULL)
            {
                tmpl1 = tmpl1->next;
                valPlace = (tmpl1->val + addPlace) % 10;
                addPlace = (tmpl1->val + addPlace) / 10;

                ListNode* newone = new ListNode(valPlace);
                tmpnewhead->next = newone;
                tmpnewhead = newone;
            }
        }

        if (addPlace != 0)
        {
            ListNode* newone = new ListNode(addPlace);
            tmpnewhead->next = newone;
            tmpnewhead = newone;
        }

        return newhead;
    }
};

int main ()
{
    buildList();
    Solution solution;
    ListNode* ansnode = new ListNode(0);
    head3 = solution.addTwoNumbers(head1, head2);
    display(head3);

    return 0;
}