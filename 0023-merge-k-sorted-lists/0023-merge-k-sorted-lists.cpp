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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size()==0)
            return NULL;
        priority_queue<int,vector<int>,greater<int>> pq;
        for(auto nodes:lists){
            ListNode* temp=nodes;
            while(temp){
                pq.push(temp->val);
                temp=temp->next;
            }
        }
        ListNode *head=NULL;
        ListNode *temp;
        if(!pq.empty()){
            temp=new ListNode(pq.top());
            pq.pop();
            head=temp;
        }
        while(!pq.empty()){
            temp->next=new ListNode(pq.top());
            temp=temp->next;
            pq.pop();
        }
        return head;
    }
};