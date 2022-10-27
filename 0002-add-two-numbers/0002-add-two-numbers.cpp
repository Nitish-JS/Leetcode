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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* temp1=l1;
        ListNode* temp2=l2;
       int len1=0,len2=0;
        while(temp1){
            len1++;
            temp1=temp1->next;
        }
        while(temp2){
            len2++;
            temp2=temp2->next;
        }
        vector<int> sum(max(len1,len2)+1);
        temp1=l1,temp2=l2;
        int i=0;
        while(temp1){
            sum[i++]=temp1->val;
            temp1=temp1->next;
        }
        i=0;
        while(temp2){
            sum[i++]+=temp2->val;
            temp2=temp2->next;
        }
        for(int i=0;i<sum.size()-1;i++){
            if(sum[i]>9){
                sum[i]-=10;
                sum[i+1]+=1;
            }
        }
        if(sum.back()==0){
            sum.pop_back();
        }
        ListNode* answer=new ListNode(sum[0]);
        ListNode* temp=answer;
        for(int i=1;i<sum.size();i++){
            ListNode* newnode=new ListNode(sum[i]);
            temp->next=newnode;
            temp=temp->next;
        }
        return answer;
    }
};