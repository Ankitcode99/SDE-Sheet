//Check for child sum property
class Solution{
public:
	void changeTree(BinaryTreeNode < int > * root) {
	    if(!root)
	        return;
	    
	    int childSum=0;
	    if(root->left) childSum += root->left->data;
	    if(root->right) childSum += root->right->data;
	    
	    if(childSum >= root->data) 
	        root->data = childSum;
	    else{
	        if(root->left) root->left->data = root->data;
	        if(root->right) root->right->data = root->data;
	    }
	    
	    changeTree(root->left);
	    changeTree(root->right);
	    
	    childSum = 0;
	    if(root->left) childSum += root->left->data;
	    if(root->right) childSum += root->right->data;
	    if(root->left || root->right) root->data = childSum;
	}  
}