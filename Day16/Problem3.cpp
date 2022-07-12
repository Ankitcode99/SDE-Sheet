//Minimum characters to be added in-front to make string palindrome
class Solution{
public:
	int minimumCharactersToBeAdded(string s){
		string revS = s;
		reverse(revS.begin(), revS.end());
		string combined = s+'$'+revS;

		auto generatePrefixArray = [&](string str){
			int sz = str.size();
			vector<int> pref(sz,0);

			int len=0,i=1;
			while(i<sz){
				if(str[i]==str[len]){
					pref[i]=len+1;
					len++,i++;
				}else{
					if(len>0){
						len=pref[len-1];
					}else{
						pref[i]=0;
						i++;
					}
				}
			}
			return pref;
		};

		vector<int> pref = generatePrefixArray(combined);
		return s.size()-pref.back();
	}
};