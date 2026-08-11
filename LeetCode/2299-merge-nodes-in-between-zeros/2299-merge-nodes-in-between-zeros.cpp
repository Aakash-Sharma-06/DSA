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
    ListNode* mergeNodes(ListNode* head) {
        ListNode* temp1=head;
        ListNode* dummy = new ListNode(0);
        ListNode* tail = dummy;

        while(temp1->next!=NULL){
            int sum=0;
            temp1=temp1->next;
            while(temp1->val!=0){
                sum+=temp1->val;
                temp1=temp1->next;
            }
            ListNode* temp2 = new ListNode(sum);
            tail->next = temp2;
            tail = temp2;
        }
        return dummy->next;
    }
};