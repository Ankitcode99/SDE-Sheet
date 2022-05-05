// Rotate a linked list by k steps to right
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL || head->next==NULL ||k==0) return head;
        
        ListNode* temp = head;
        int len = 1;
        while(temp->next!=NULL){
            len+=1;
            temp = temp->next;
        }
        
        temp->next = head;
        
        k%=len;
        
        int end = len-k;
        
        while(end--) temp=temp->next;
            
        head = temp->next;
        temp->next = NULL;
        return head;
    }
};