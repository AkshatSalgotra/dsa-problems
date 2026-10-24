class Solution {
public:
    int helper(string date){
        int days[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        int m = stoi(date.substr(0, 2));
        int d = stoi(date.substr(3, 2));

        int tot = 0;
        for(int i=0; i<m-1; i++){
            tot += days[i];
        }

        tot += d;
        return tot;
    }

    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
        int aa = helper(arriveAlice);
        int al = helper(leaveAlice);

        int ba = helper(arriveBob);
        int bl = helper(leaveBob);

        int cnt = min(al, bl) - max(aa, ba) + 1;

        return (cnt > 0) ? cnt : 0;
    }
};