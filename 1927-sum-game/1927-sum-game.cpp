class Solution {
public:
    bool sumGame(string num) {
        int n = num.length();
        int sum1=0, sum2=0, c1=0, c2=0;

        for(int i=0; i<n; i++){
            if(i < n/2){
                if(num[i] == '?') c1++;
                else sum1 += num[i]-'0';
            } else {
                if(num[i] == '?') c2++;
                else sum2 += num[i]-'0';
            }
        }

        //if sum is odd, alice has extra turn, she wins
        if((c1+c2)%2) return true;

        //if sum is even, cancel cout the c1, c2 so that all q on same side, then c = no.of pairs of '?'
        int c = (c2-c1)/2;
        if(sum1-sum2 == 9*c) return false;
        
        return true;
    }   
};