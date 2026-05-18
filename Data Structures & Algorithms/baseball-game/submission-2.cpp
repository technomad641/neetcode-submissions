class Solution {
public:
    int calPoints(vector<string>& operations) {
        stack< int > st;
        int ans = 0;
        for(auto x: operations){
            if(x[0] != '+' && x[0]!= 'D' && x[0] != 'C'){
                st.push(stoi(x));
                //printf(st.top());
              //  ans+= stoi(x);
            }else{
                if(x[0]=='+'){
                    if(st.size()>=2){
                        int A = st.top(); st.pop();
                        int B = st.top(); st.pop();
                        int N = A+B;
                        st.push(B);
                        st.push(A);
                        st.push(N);
                      //  ans+=N;
                    }
                    }
                    else if(x[0]=='C'){
                        // ans-= st.top();
                         if(st.size()>0)st.pop();
                    }
                    else if (x[0]== 'D'){
                        if(st.size()>0)st.push(st.top()*2);
                       // ans+= (st.top())*2;
                    }
                }
            }
           // cout<< st.top();
             //cout<< "/n";
        
        while(!st.empty()){
            ans+=st.top();
            st.pop();
        }
        return ans;
    }
};