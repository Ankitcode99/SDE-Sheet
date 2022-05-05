// Flatten a linked list with next and bottom pointer
class Solution{
public:
	ListNode *mergeLists(ListNode *ptr1, ListNode *ptr2){
	    ListNode *temp = new ListNode(0);
	    ListNode *res = temp;
	    
	    while(ptr1!=NULL && ptr2!=NULL){
	        if(ptr1->data <= ptr2->data){
	            temp->bottom = ptr1;
	            temp = temp->bottom;
	            ptr1 = ptr1->bottom;
	        } else {
	            temp->bottom = ptr2;
	            temp = temp->bottom;
	            ptr2 = ptr2->bottom;
	        }
	    }
	    
	    if(ptr1!=NULL) temp->bottom = ptr1;
	    if(ptr2!=NULL) temp->bottom = ptr2;
	    
	    return res->bottom;
	}
	ListNode *flatten(ListNode *root){
	    if(root==NULL || root->next==NULL){
	        return root;
	    }
	    
	    // Recur in the primary list
	    root->next = flatten(root->next);
	    
	    // merge the current and next ListNode's list
	    root = mergeLists(root, root->next);
	    
	    return root;
	}	
};