// N'th root of an integer
class Solution{
public:
	double findNthRootOfM(int n, long long m) {
		double low=1, hi=m, eps = 1e-9;
		
		auto multiply = [&](double m, int n){
			double pro = 1.0;
			while(n){
				if(n&1){
					pro*=m;
				}
				m=m*m;
				n>>=1;
			}
			return pro;
		};
		
		while((hi-low)>eps){
			double mid = (low+hi)/2.0;
			if(multiply(mid,n)<=m){
				low = mid;
			}else{
				hi = mid;
			}
		}
		return low;
	}
}