// Check if linked list is palindrome
class Solution {
public:
    
    ListNode* reverse(ListNode* tempHead){
        ListNode *prev=NULL, *curr=tempHead, *nex=NULL;
        while(curr!=NULL){
            nex = curr->next;
            curr->next = prev;
            prev=curr;
            curr=nex;
        }
        return prev;
    }
    
    bool isPalindrome(ListNode* head) {
        if(head==NULL || head->next==NULL) return true;
        
        ListNode *slow=head, *fast=head;
        while(fast->next!=NULL && fast->next->next!=NULL){
            fast = fast->next->next;
            slow = slow->next;
        }
        
        slow->next = reverse(slow->next);
        slow = slow->next;
        ListNode* dummy = head;
        while(slow!=NULL){
            if(dummy->val!=slow->val){
                return false;
            }
            dummy = dummy->next;
            slow = slow->next;
        }
        return true;
    }
};