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
    ListNode *detectCycle(ListNode *head) {
        if(!head) return NULL;
        ListNode* slow = head;
        ListNode* fast = head;
        bool flag = false;
        while(fast && fast->next){
            
            slow = slow->next;
            fast = fast->next->next;

            if(slow == fast){
                flag = true;
                break;
            }
        }
        if(!flag) return NULL;

        ListNode* temp = head;
        while(slow!=temp){
            temp = temp->next;
            slow = slow->next;
        }
        return slow;
    }
};