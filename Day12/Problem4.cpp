//Number of distinct substrings of a string using Trie
struct Node{
	Node *links[26];
	
	bool containsKey(char ch){
		return links[ch-'a']!=NULL;
	}
	
	void put(char ch, Node *newNode){
		links[ch-'a']=newNode;
	}
	
	Node *get(char ch){
		return links[ch-'a'];
	}
};
int countDistinctSubstrings(string &s)
{
    Node *root = new Node();
	int count=0;
	
	int n = s.size();
	for(int i=0;i<n;i++){
		Node *node = root;
		for(int j=i;j<n;j++){
			if(!node->containsKey(s[j])){
				node->put(s[j],new Node());
				count++;
			}
			node = node->get(s[j]);
		}
	}
	return count+1;
}