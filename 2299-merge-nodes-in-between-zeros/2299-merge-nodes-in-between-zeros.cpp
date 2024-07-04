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
        ListNode* p1 = head->next;
        ListNode* p2 =head->next;
        int sum = 0;
        while(p2){
            if(p2->val == 0){
                // means one interval is found
                p1->val = sum;
                p2 = p2->next;
                p1->next = p2;
                p1 = p1->next;
                sum = 0;
            }
            else{
                sum = sum + p2->val;
                p2 = p2->next;
            }          
        }
        return head->next;
    }
};