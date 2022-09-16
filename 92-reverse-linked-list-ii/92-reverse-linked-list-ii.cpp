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
    ListNode* reverseBetween(ListNode* head, int start, int end) {
       if(!head || start==end)
           return head;
        ListNode temp(0);
        temp.next=head;
        ListNode* nodeBeforeReverse=&temp;
        int pos=1;
        while(pos<start){
            nodeBeforeReverse=nodeBeforeReverse->next;
            pos++;
        }
        ListNode* workingPtr=nodeBeforeReverse->next;
        while(start<end){
            ListNode* nodeExtracted=workingPtr->next;
            workingPtr->next=nodeExtracted->next;
            nodeExtracted->next=nodeBeforeReverse->next;
            nodeBeforeReverse->next=nodeExtracted;
            start++;
            
        }
        return temp.next;
    }
};