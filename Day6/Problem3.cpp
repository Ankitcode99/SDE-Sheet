// Reverse linked list in groups of size k
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head==NULL || k==1) return head;
        
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        
        ListNode *curr = dummy, *prev = dummy, *nex = dummy;
        
        int len = 0;
        while(curr->next!=NULL){
            curr = curr->next;
            len+=1;
        }
        
        while(len >= k){
            curr = prev->next;
            nex = curr->next;
            for(int i=1;i<k;i++){
                curr->next = nex->next;
                nex->next = prev->next;
                prev->next = nex;
                nex = curr->next;
            }
            len -= k;
            prev = curr;
        }
        
        return dummy->next;
    }
};