// Starting point of loop in a linked list
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(head==NULL or head->next==NULL) return NULL;
        ListNode *slow=head, *fast=head, *entry=head;
        while(fast->next!=NULL && fast->next->next!=NULL){
            fast = fast->next->next;
            slow = slow->next;
            
            if(fast==slow){
                while(slow!=entry){
                    slow = slow->next;
                    entry = entry->next;
                }
                return slow;
            }
        }
        return NULL;
    }
};