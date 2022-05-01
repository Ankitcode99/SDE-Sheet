// Find repeat and missing number
vector<int> repeatedNumber(const vector<int> &A) {
    long long int nums = A.size();
    long long int sumOfNos = (nums*(nums+1))/2;
    long long int sumOfSq = (nums*(nums+1)*(2*nums+1))/6;

    for(int ele: A){
        sumOfNos -= (long long int)ele;
        sumOfSq -= ((long long int)ele*(long long int)ele);
    }

    long long int missing = (sumOfNos + (sumOfSq/sumOfNos))/2;
    long long int repeating = missing - sumOfNos;

    vector<int> ans = {repeating, missing};
    return ans;
}
