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
    ListNode*reverse(ListNode*l)
    {
        ListNode*prev=NULL;
        ListNode*curr=l;
        ListNode*nxt=NULL;
        while(curr!=NULL)
        {
            nxt=curr->next;
            curr->next=prev;
            prev=curr;
            curr=nxt;
        }
        return prev;
    }
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        ListNode*temp1=l1;
        ListNode*temp2=l2;
        ListNode*ans=NULL;
        ListNode*res=NULL;
        int carry=0;
        int val1=0,val2=0,sum=0,curr;
        while(temp1!=NULL && temp2!=NULL)
        {
             val1=temp1->val;
             val2=temp2->val;
              sum=val1+val2+carry;
              if(res==NULL)
              {
                res=new ListNode(sum%10);
                carry=sum/10;
                ans=res;
              }
              else
              {
                res->next=new ListNode(sum%10);
                carry=sum/10;
                res=res->next;
              }
              temp1=temp1->next;
              temp2=temp2->next;
        }
        while(temp1!=NULL)
        {
              val1=temp1->val;
             val2=0;
              sum=val1+val2+carry;
              if(res==NULL)
              {
                res=new ListNode(sum%10);
                carry=sum/10;
                ans=res;
              }
              else
              {
                res->next=new ListNode(sum%10);
                carry=sum/10;
                res=res->next;
              }
              temp1=temp1->next;
        }

         while(temp2!=NULL)
        {
              val1=0;
             val2=temp2->val;
              sum=val1+val2+carry;
              if(res==NULL)
              {
                res=new ListNode(sum%10);
                carry=sum/10;
                ans=res;
              }
              else
              {
                res->next=new ListNode(sum%10);
                carry=sum/10;
                res=res->next;
              }
              temp2=temp2->next;
        }

        if(carry)
        {
             res->next=new ListNode(carry);
        }
 return ans;
        // return reverse(ans);
    }
};
