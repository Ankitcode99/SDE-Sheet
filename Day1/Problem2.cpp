// Pascal Triangle
class Solution{
public:
	void printTriangle(int n){
		vector<vector<int>> pascal;

		pascal.push_back({1});
		vector<int> prev;
		for(int i=1;i<n;i++){
			vector<int> curr;
			for(int j=0;j<=i;j++){
				if(j==0 or j==i){
					curr.push_back(1);
				}else{
					curr.push_back(prev[j]+prev[j-1]);
				}
			}
			pascal.push_back(curr);
			prev=curr;
		}
	}

	int getRC(int r, int c){
		int res = 1;
		for(int i=0;i<c;i++){
			res *= (r-i);
			res /= (i+1);
		}
		return res;
	}

	vector<int> getNthRow(int n){
		vector<int> result;

		int curr=1;
		result.push_back(curr);
		for(int i=0;i<n;i++){
			curr *= (n-i);
			curr /= (i+1);
			result.push_back(curr);
		}
		return result;
	}
}
