class Solution {
public:
    vector< int > nse(vector<int>& heights, int sz){
        stack< int > st;
        vector< int>NSE(sz, 1);
       // int sz = heights.size();
        for(int i=0;i<sz;i++){
            while(!st.empty() && heights[st.top()]>heights[i]){
                NSE[st.top()] = i-st.top();
                st.pop();
            }
            st.push(i);
        }
        while(!st.empty()){
            int x = st.top(); st.pop();
            NSE[x] = sz-x;
        }
        return NSE;
    }
    int largestRectangleArea(vector<int>& heights) {
        int sz = heights.size();
        vector< int > A = nse(heights, sz);
        //for(auto x: A) cout<<x<<" ";
        //cout<<endl;
        reverse(begin(heights), end(heights));
        vector< int > B = nse(heights, sz);
        reverse(begin(B), end(B));
        // for(auto x: B) cout<<x<<" ";
        // cout<<endl;
        int ans = 0;
        //int sz = heights.size();
        reverse(begin(heights), end(heights));
        for(int i=0;i<sz;i++){
            ans = max(ans, heights[i]*(abs(A[i]+B[i]-1)));
        }
        return ans;
    }
};


//[7,1,7,2,2,4]
//[1,2,1,2,3,1] // previous smaller element
//[1,5,1,3,2,1] // next smaller element
//[7,6,7,8,8,4] // ans = 8



//[7,1,7,2,2,4]
//[4,2,2,7,1,7]
//[1,3,2,1,2,1]