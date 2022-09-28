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
    ListNode* swapNodes(ListNode* head, int k) {
        vector<int> arr;
        ListNode *temp=head;
        while(temp){
            arr.push_back(temp->val);
            temp=temp->next;
        }
        swap(arr[k-1],arr[arr.size()-k]);
        // cout<<arr[k-1]<<" "<<arr[arr.size()-k];
        head=new ListNode(arr[0]);
        temp=head;
        for(int i=1;i<arr.size();i++){
            temp->next=new ListNode(arr[i]);
            temp=temp->next;
        }
        return head;
    }
};