//Maximum XOR with an element from array
struct Node{
    Node *link[2];
    
    bool containsKey(int idx){
        return link[idx]!=NULL;
    }
    
    void put(int idx, Node *newNode){
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
        root = new Node();
    }
    
    void insert(int num){
        Node *node = root;
        for(int i=31;i>=0;i--){
            int bit = (num>>i)&1;
            if(!node->containsKey(bit)){
                node->put(bit, new Node());
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

class Solution {
public:
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        Trie trie;
        sort(nums.begin(),nums.end());
        
        vector<pair<int,pair<int,int>>> oQ;
        int n = queries.size();
        for(int i=0;i<n;i++){
            oQ.push_back({queries[i][1],{queries[i][0],i}});
        }
        sort(oQ.begin(),oQ.end());
        vector<int> ans(n);
        int idx=0;
        for(int i=0;i<n;i++){
            int lim = oQ[i].first;
            int x = oQ[i].second.first;
            int ansIdx = oQ[i].second.second;
            
            while(idx<nums.size() && nums[idx]<=lim){
                trie.insert(nums[idx]);
                idx+=1;
            }
            if(idx==0){
                ans[ansIdx]=-1;
                continue;
            }
            int maxXor = trie.findMax(x);
            ans[ansIdx] = maxXor;
        }
        return ans;
    }
};
