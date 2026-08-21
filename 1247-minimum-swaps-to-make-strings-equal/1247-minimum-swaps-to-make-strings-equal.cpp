class Solution {
public:
    int minimumSwap(string s1, string s2) {
        int xyPair=0, yxPair=0;

        for(int i=0; i<s1.length(); i++){
            if(s1[i] == 'x' && s2[i] == 'y') xyPair++;
            if(s1[i] == 'y' && s2[i] == 'x') yxPair++;
        }

        if((xyPair + yxPair)%2 == 1) return -1;

        return (xyPair/2) + (yxPair/2) + (xyPair%2)*2;
    }
};