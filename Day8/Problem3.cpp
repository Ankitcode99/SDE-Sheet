// Job Sequencing

struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
};


class Solution 
{
    public:
    //Function to find the maximum profit and the number of jobs done.
    vector<int> JobScheduling(Job arr[], int n) { 
        sort(arr,arr+n,[&](auto a, auto b){
            return a.profit>b.profit;
        });
        
        int maxDeadline=0;
        for(int i=0;i<n;i++) maxDeadline = max(maxDeadline, arr[i].dead);
        
        int slots[maxDeadline+1];
        memset(slots,-1,sizeof slots);
        int cnt=0,profit=0;
        for(int i=0;i<n;i++){
            for(int j=arr[i].dead;j>0;j--){
                if(slots[j]==-1){
                    slots[j]=arr[i].id;
                    cnt+=1;
                    profit+=arr[i].profit;
                    break;
                }
            }
        }
        
        vector<int> ans = {cnt,profit};
        return ans;
    } 
};