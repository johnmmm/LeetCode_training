#include <vector>
#include <unordered_map>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(NULL) {}
};
ListNode* head = new ListNode;
ListNode* tail = new ListNode;

void buildList()
{
    //int example[10] = {3, 45, 23, 9, 100, 32, 43, 54, 92, 18};
    int example[10] = {9,1,8,7,6,5,5,3,2,1};
    int length = sizeof(example) / sizeof(example[0]);
    ListNode* tmpnode = new ListNode;
    head->val = example[0];
    tmpnode = head;

    for (int i = 1; i < length; i++)
    {
        ListNode* newone = new ListNode;
        newone->val = example[i];
        tmpnode->next = newone;
        tmpnode = newone;
    }
    tail = tmpnode;
}

ListNode* getListPartion(ListNode* beginNode, ListNode* endNode)
{
    int key = beginNode->val;
    int tmp = 0;
    ListNode* beginOne = beginNode;
    ListNode* iNode = beginOne;
    ListNode* jNode = iNode->next;

    if (jNode->next == NULL)
    {
        if (iNode->val > jNode->val)
        {
            //swap
            tmp = iNode->val;
            iNode->val = jNode->val;
            jNode->val = tmp;
        }
        return iNode;
    }

    while (jNode != NULL)
    {
        if (jNode->val < key)
        {
            if (iNode->val > key)
            {
                //swap
                tmp = iNode->val;
                iNode->val = jNode->val;
                jNode->val = tmp;
            }
            else if (iNode == jNode)
            {
                if (jNode->next == NULL)
                    break;
                jNode = jNode->next;
            }
            else
            {
                iNode = iNode->next;
            }
        }
        else
        {
            if (jNode->next == NULL)
                break;
            jNode = jNode->next;
        }
    }
    while (iNode->next != NULL)
    {
        if (iNode->next->val < key)
            iNode = iNode->next;
        else
            break;
    }

    //swap 
    tmp = beginNode->val;
    beginNode->val = iNode->val;
    iNode->val = tmp;

    return iNode;
}

void listQuickSort(ListNode* beginNode, ListNode* endNode)
{
    if (beginNode != endNode)
    {
        ListNode* partion = getListPartion(beginNode, endNode);
        listQuickSort(beginNode, partion);
        if (partion != endNode)
            listQuickSort(partion->next, endNode);
    }
}

void display(ListNode* listhead)
{
    ListNode* tmpnode = new ListNode;
    tmpnode = listhead;
    while(tmpnode != NULL)
    {
        printf("%d->", tmpnode->val);
        tmpnode = tmpnode->next;
        // if (tmpnode->next != NULL)
        //     tmpnode = tmpnode->next;
        // else
        //     tmpnode = NULL;
    }
    printf("\n");
}

int getIntPartion(int arr[], int begin, int end)
{
    int key = arr[begin];
    int i = begin;
    int j = end;
    int tmp = 0;

    if (j - i == 1)
    {
        if (arr[i] > arr[j])
        {
            //swap
            tmp = arr[i];
            arr[i] = arr[j];
            arr[j] = tmp;
        }
        return i;
    }

    while(i < j)
    {
        if (arr[j] > key)
            j--;
        else if (arr[i] <= key)
            i++;
        else
        {
            //swap
            tmp = arr[i];
            arr[i] = arr[j];
            arr[j] = tmp;
        } 
    }

    //swap
    tmp = arr[i];
    arr[i] = arr[begin];
    arr[begin] = tmp;

    return i;
}

void quickSort(int arr[], int begin, int end)
{
    if (begin != end)
    {
        int partion = getIntPartion(arr, begin, end);
        //printf("%d\n", partion);
        quickSort(arr, begin, partion);
        if (partion != end)
            quickSort(arr, partion+1, end);
    }
}

int main ()
{
    buildList();
    display(head);
    listQuickSort(head, tail);
    display(head);

    int arr[10] = {9,1,8,7,6,5,5,3,2,1};
    int length = sizeof(arr) / sizeof(arr[0]);
    quickSort(arr, 0, 9);
    for (int i = 0; i < length; i++)
    {
        printf("%d->", arr[i]);
    }
    printf("\n");
    return 0;
}