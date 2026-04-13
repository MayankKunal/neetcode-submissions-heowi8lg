/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
    ListNode*mergeTwoLists(ListNode*l1,ListNode*l2)
    {
        if(!l1) return l2;
        if(!l2) return l1;
    ListNode*temp1=NULL;
    ListNode*temp2=NULL;
   ListNode*head=NULL;
   ListNode*temp=NULL;
    if(l1->val<l2->val)
    {
       temp1=l1->next,temp2=l2;
       head=new ListNode(l1->val);
       temp=head;
    }
    else
    {
      temp1=l1,temp2=l2->next;
      head=new ListNode(l2->val);
      temp=head;
    }
     while(temp1!=NULL && temp2!=NULL)
     {
           if(temp1->val<temp2->val)
           {
               temp->next=new ListNode(temp1->val);
               temp1=temp1->next;
           }
           else
           {
               temp->next=new ListNode(temp2->val);
               temp2=temp2->next;
           }
           temp=temp->next;
     }
     while(temp1!=NULL)
     {
        temp->next=new ListNode(temp1->val);
               temp1=temp1->next;
               temp=temp->next;
     }
     while(temp2!=NULL)
     {
        temp->next=new ListNode(temp2->val);
               temp2=temp2->next;
               temp=temp->next;
     }

     return head;

    }
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        
        ListNode*head=NULL;

        for(auto list:lists)
        {
         head=mergeTwoLists(head,list);
        }

        return head;
        
    }
};
