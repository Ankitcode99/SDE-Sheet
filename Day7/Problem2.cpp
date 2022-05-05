//Copy list with random pointer
class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head) 
            return NULL;
        Node* newHead, *copyNode, *temp= head;
        
        //step 1.
        while(temp)
        {
            copyNode = new Node(temp->val);
            copyNode->next = temp->next;
            temp->next = copyNode;
            temp = copyNode->next;
        }
        
        newHead = head->next;
        temp = head;
        
        //step 2.
        while(temp)
        {
            if(temp->random == NULL)
                temp->next->random = NULL;
            
            else 
                temp->next->random = temp->random->next;
            
            temp = temp->next->next;
        }
        temp = head;
        
        //step 3
        while(temp)
        {
            copyNode = temp->next;
            temp->next = copyNode->next;
            
            if(copyNode->next)
                copyNode->next = copyNode->next->next;
            
            temp = temp->next;
        }
        
        return newHead;
    }
};