//Fractional Knapsack
struct Item{
    int value;
    int weight;
};


class Solution
{
    public:
    //Function to get the maximum total value in the knapsack.
    double fractionalKnapsack(int W, Item arr[], int n)
    {
        sort(arr,arr+n,[&](auto a,auto b){
            return ((double)a.value/(double)a.weight)>((double)b.value/(double)b.weight);
        });
        
        double pro=0;
        int currW=0;
        for(int i=0;i<n;i++){
            if(currW + arr[i].weight <= W){
                currW+=arr[i].weight;
                pro += (double)arr[i].value;
            }else{
                int rem = W-currW;
                double val = (rem*arr[i].value)/(arr[i].weight*1.0);
                pro+=val;
                break;
            }
        }
        return pro;
    }
        
};
