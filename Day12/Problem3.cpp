//Longest string whose all prefixes is present
struct Node{
	Node *links[26];
	bool flag=false;
	
	bool containsKey(char ch){
		return links[ch-'a']!=NULL;
	}
	
	void put(char ch, Node *newNode){
		links[ch-'a']=newNode;
	}
	
	Node *get(char ch){
		return links[ch-'a'];
	}
	
	void setEnd(){
		flag=true;
	}
	
	bool isEnd(){
		return flag;
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
		}
		node->setEnd();
	}
	
	bool checkIfPrefixExist(string& word){
		Node *node = root;
		for(int i=0;i<word.size();i++){
			char ch=word[i];
			if(node->containsKey(ch)){
				node = node->get(ch);
				if(node->isEnd()==false){
					return false;
				}
			}
			else
				return false;
		}
		return true;
	}
};

string completeString(int n, vector<string> &a){
    string ans="";
	
	Trie *trie = new Trie();
	for(string s:a){
		trie->insert(s);
	}
	
	for(string s:a){
		if(trie->checkIfPrefixExist(s)){
			if(s.size()>ans.size()){
				ans = s;
			}else if(s.size()==ans.size() and s<ans){
				ans=s;
			}
		}
	}
	return ans==""?"None":ans;
}