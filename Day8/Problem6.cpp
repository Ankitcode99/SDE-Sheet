// Activity Selection (Same as N-meetings in a room)
class Solution{
public:
	int maximumActivities(vector<int> &start, vector<int> &finish) {
		vector<pair<int,int>> vec;
		for(int i=0;i<start.size();i++){
			vec.push_back({start[i],finish[i]});
		}
		
		sort(vec.begin(),vec.end(),[&](pair<int,int> a, pair<int,int> b){
			if(a.second!=b.second) return a.second<b.second;
			else return a.first<b.first;
		});
		
		int ans=1;
		int lim=vec[0].second;
		for(int i=1;i<vec.size();i++){
			if(vec[i].first>=lim){
				ans++;
				lim=vec[i].second;
			}
		}
		return ans;
	}
};