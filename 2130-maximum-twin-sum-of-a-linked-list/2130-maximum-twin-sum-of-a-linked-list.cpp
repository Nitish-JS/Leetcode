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
    int pairSum(ListNode* head) {
        ListNode* slow=head;
        ListNode *fast=head;
        while(fast && fast->next){
            slow=slow->next;
            fast=fast->next->next;
        }
        ListNode *ahead=slow;
        slow=head;
        ListNode *curr=NULL;
        ListNode *prev=NULL;
        while(ahead){
            prev=curr;
            curr=ahead;
            ahead=ahead->next;
            curr->next=prev;
        }
        int ans=INT_MIN;
        while(curr){
            ans=max(ans,curr->val+slow->val);
            slow=slow->next;
            curr=curr->next;
        }
        return ans;
    }
};