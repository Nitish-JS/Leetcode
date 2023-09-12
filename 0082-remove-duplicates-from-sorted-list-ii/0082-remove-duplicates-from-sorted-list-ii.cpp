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
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head || !head->next)
            return head;
        ListNode *temp=head;
        ListNode* ans=new ListNode(0);
        ListNode* ansTemp=ans;
        bool flag=false;
        while(temp && temp->next){
            while(temp && temp->next && temp->val==temp->next->val){
                flag=true;
                temp->next=temp->next->next;
            }
            if(flag){
                ansTemp->next=temp->next;
                flag=false;
            }
            else{
                ansTemp->next=temp;
                ansTemp=ansTemp->next;
            }
            temp=temp->next;
        }
        return ans->next;
    }
};