/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        // approach 1
//         ListNode *temp1=headA;
//         ListNode *temp2=headB;
//         int len1=0,len2=0;
//         while(temp1){
//             len1++;
//             temp1=temp1->next;
//         }
//         while(temp2){
//             len2++;
//             temp2=temp2->next;
//         }
//         temp1=headA;
//         temp2=headB;
//         int difference=abs(len1-len2);
//         if(len1>len2){
//             while(difference){
//                 temp1=temp1->next;
//                 difference--;
//             }
//         }
//         else if(len1<len2){
//             while(difference){
//                 temp2=temp2->next;
//                 difference--;
//             }
//         }
//         while(temp1){
//              if(temp1==temp2)
//                 return temp1;
//             temp1=temp1->next;
//             temp2=temp2->next;
           
//         }
//         return NULL;
        
        
//         approach 2 
        if(!headA || !headB)
            return NULL;
        ListNode *tempA=headA;
        ListNode *tempB=headB;
        while(tempA!=tempB){
            tempA=tempA==NULL?headB:tempA->next;
            tempB=tempB==NULL?headA:tempB->next;
        }
        return tempA;
        
        
        
       
    }
};