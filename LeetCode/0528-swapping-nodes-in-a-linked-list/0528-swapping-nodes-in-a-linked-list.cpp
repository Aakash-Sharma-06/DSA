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
        ListNode* temp = head; 
        ListNode* temp2 = head; 
        int len = 0;
        while(temp){ 
            len ++; 
            temp = temp->next; 
        }
        int i = k-1;
        int j = len-k;
        temp = head;  
        while(i--){  
            temp = temp->next;
        }
        while(j--){ 
            temp2 = temp2->next; 
        }
        swap(temp->val, temp2->val); 
        return head; 
    } 
};