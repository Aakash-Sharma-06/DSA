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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* temp1=head;
        ListNode* beforeLeft=nullptr;
        
        for(int i = 1; i < left; i++){
            beforeLeft = temp1;
            temp1 = temp1->next;
            }

        int dif=right-left+1;
            ListNode* prev=nullptr;
            ListNode* curr=temp1;
             while(dif!=0){
                ListNode* temp=curr->next;
                curr->next=prev;
                prev=curr;
                curr=temp;
                dif--;
        }
        if(beforeLeft)
            beforeLeft->next = prev;
        else
            head = prev;

        temp1->next = curr;
        

        return head;
    }
};