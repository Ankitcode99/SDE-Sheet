// Max XOR of 2 numbers one selected from each of the given 2 arrays
struct Node{
    Node *link[2];
    
    bool containsKey(int idx){
        return link[idx]!=NULL;
    }
    
    void put(int idx,Node *newNode){
        link[idx]=newNode;
    }
    
    Node *get(int idx){
        return link[idx];
    }
};

class Trie{
private:
    Node *root;
public:
	Trie(){
		root= new Node();
	}
    
    void insert(int num){
        Node *node = root;
        for(int i=31;i>=0;i--){
            int bit = (num>>i)&1;
            if(!node->containsKey(bit)){
                node->put(bit,new Node());
            }
            node = node->get(bit);
        }
    }
    
    int findMax(int num){
        Node *node = root;
        int maxNum=0;
        for(int i=31;i>=0;i--){
            int bit = (num>>i)&1;
            if(node->containsKey(!bit)){
                maxNum |= (1<<i);
                node = node->get(!bit);
            }else{
                node = node->get(bit);
            }
        }
        return maxNum;
    }
};

int maxXOR(int n, int m, vector<int> &arr1, vector<int> &arr2) 
{
	Trie trie;// = new Trie();
	for(int num:arr1){ 
		trie.insert(num);
	}
	int maxXor=0;
	for(int num:arr2){
		maxXor = max(maxXor, trie.findMax(num));
	}
	return maxXor;
}
