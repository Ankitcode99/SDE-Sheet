// Implement countWordsEqualTo, countWordsStartingWith, erase in trie
struct Node{
	Node *links[26];
	int cntEndWith=0, cntPrefix=0;
	
	bool containsKey(char ch){
		return (links[ch-'a']!=NULL);
	}
	
	void put(char ch, Node *newNode){
		links[ch-'a']=newNode;
	}
	
	Node* get(char ch){
		return links[ch-'a'];
	}
	
	void incPrefix(){
		cntPrefix++;
	}
	
	void incEnd(){
		cntEndWith++;
	}
	
	void decPrefix(){
		cntPrefix--;
	}
	
	void decEnd(){
		cntEndWith--;
	}
	
	int getPrefix(){
		return cntPrefix;
	}
	
	int getEnd(){
		return cntEndWith;
	}
};

class Trie{
private:
	Node *root;
public:

    Trie(){
        root = new Node();
    }

    void insert(string &word){
        Node *node = root;
		for(char ch:word){
			if(!node->containsKey(ch)){
				node->put(ch,new Node());
			}
			node = node->get(ch);
			node->incPrefix();
		}
		node->incEnd();
    }

    int countWordsEqualTo(string &word){
        Node *node = root;
		for(char ch:word){
			if(!node->containsKey(ch)){
				return 0;
			}else{
				node = node->get(ch);
			}
		}
		return node->getEnd();
    }

    int countWordsStartingWith(string &word){
        Node *node = root;
		for(char ch:word){
			if(!node->containsKey(ch)){
				return 0;
			}else{
				node = node->get(ch);
			}
		}
		return node->getPrefix();
    }

    void erase(string &word){
        Node *node = root;
		for(char ch:word){
			if(!node->containsKey(ch)){
				return;
			}else{
				node = node->get(ch);
				node->decPrefix();
			}
		}
		node->decEnd();
    }
};
