//Largest area in histogram
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int largestArea = 0;
        stack<int> st;
        int sz = heights.size();
        for(int idx=0;idx<=sz;idx++){
            while(!st.empty() && (idx==sz || heights[st.top()]>=heights[idx])){
                int height = heights[st.top()];
                st.pop();
                int width;
                if(st.empty()) 
                    width=idx;
                else
                    width=(idx-st.top()-1);
                cout<<" height "<<height<<"\n";
                largestArea = max(largestArea,width*height);
            }
            st.push(idx);
        }
        
        return largestArea;
    }
};