/*
给出两个 非空 的链表用来表示两个非负的整数。其中，它们各自的位数是按照 逆序 的方式存储的，并且它们的每个节点只能存储 一位 数字。

如果，我们将这两个数相加起来，则会返回一个新的链表来表示它们的和。

您可以假设除了数字 0 之外，这两个数都不会以 0 开头。
*/
#include <iostream>
#include <algorithm>
 
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
    int get_length(ListNode *l)
    {
        int i=0;
        while(l->next!=NULL)
            i++;
        return i;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) 
    {
        ListNode *head=new ListNode(0);
        int jinwei=0;
        while(l1!=NULL||l2!=NULL)
        {
            int x=(l1!=NULL)?l1->val:0;
            int y=(l2!=NULL)?l2->val:0;
            ListNode *node=new ListNode(0);
            int val=x+y+jinwei;
            node->val=val%10;
            jinwei=val/10;
            //串成一个链表
            head->next=node;
            head=head->next;
            if(l2!=NULL) l2=l2->next;
            if(l1!=NULL) l1=l1->next;
        }
        if(jinwei>0)
        {
            ListNode *node=new ListNode(jinwei);
            head->next=node;
        }
        return head;
     
    }
};
