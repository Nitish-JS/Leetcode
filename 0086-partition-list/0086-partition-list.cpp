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
    ListNode* partition(ListNode* head, int x) {
        vector<int> less;
        vector<int> great;
        ListNode* temp=head;
        while(temp){
            if(temp->val<x)
                less.push_back(temp->val);
            else
                great.push_back(temp->val);
            temp=temp->next;
        }
        ListNode* ans=new ListNode();
        temp=ans;
        for(int i:less){
            ListNode* newNode=new ListNode(i);
            temp->next=newNode;
            temp=temp->next;
        }
        for(int i:great){
            ListNode* newNode=new ListNode(i);
            temp->next=newNode;
            temp=temp->next;
        }
        return ans->next;
        
    }
};