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
        int n=lists.size();
        if(n==0) return nullptr;
        multiset<int> ms;
        
        for(int i=0;i<n;i++){
            ListNode* temp=lists[i];

            while(temp!=NULL){
                ms.insert(temp->val);
                temp=temp->next;
            }
        }

        ListNode* dummy = new ListNode(0);
        ListNode* curr=dummy;

        for(auto x:ms){
            curr->next=new ListNode(x);
            curr=curr->next;
        }
        return dummy->next;

    }
};