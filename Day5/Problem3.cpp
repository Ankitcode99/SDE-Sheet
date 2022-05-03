// Merge 2 sorted linked lists
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1 == NULL) return list2;
        if(list2 == NULL) return list1;
        
        ListNode *ptr1 =list1, *ptr2=list2, *temp;
        
        if(ptr1->val > ptr2->val) swap(ptr1,ptr2);
        
        ListNode* res = ptr1;
        while(ptr1!=NULL and ptr2!=NULL){
            while(ptr1!=NULL and ptr1->val <= ptr2->val){
                temp = ptr1;
                ptr1 = ptr1->next;
            }
            
            temp->next = ptr2;
            swap(ptr1, ptr2);
        }
        return res;
    }
};