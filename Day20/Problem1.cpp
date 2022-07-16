// Populating next right pointer
class Solution{
public:
	Node* connect(Node* root){
		if(!root)
			return NULL;

		Node* pre;
		while(pre){
			Node* curr = pre;
			while(curr && curr->left){
				curr->left->next = curr->right;
				if(curr->next){
					curr->right->next = curr->next->left;
				}

				curr=curr->next;
			}
			pre = pre->left;
		}
		return root;
	}
};