// Inversion Count using Merge Sort
long long merge(vector<long long>& ar, vector<long long>& temp, int left, int mid, int right){
	int ptr1 = left, ptr2 = mid, idx = left;
	
	int ic=0;
	while(ptr1<=(mid-1) and ptr2<=right){
		if(ar[ptr1] <= ar[ptr2]){
			temp[idx++]=ar[ptr1++];
		}else{
			ic += (mid-ptr1);
			temp[idx++]=ar[ptr2++];
		}
	}
	
	while(ptr1<=(mid-1)){
		temp[idx++]=ar[ptr1++];
	}
	
	while(ptr2<=right){
		temp[idx++]=ar[ptr2++];
	}
	
	for(int i = left; i<=right;i++){
		ar[i] = temp[i];
	}
	
	return ic;
}

long long mergeSort(vector<long long>& ar,vector<long long>& temp, int left, int right){
	long long inversionCount = 0;
	while(left<right){
		int mid = (left+right)/2;
		inversionCount += mergeSort(ar,temp,left,mid);
		inversionCount += mergeSort(ar,temp,mid+1,right);
		
		inversionCount += merge(ar,temp,left,mid+1,right);
	}
	return inversionCount;
}

long long getInversions(long long *arr, int n){
    vector<long long> ar,temp(n);
	for(int idx=0;idx<n;idx++) ar.push_back(arr[idx]);
	
	return mergeSort(ar,temp,0,n-1);
}