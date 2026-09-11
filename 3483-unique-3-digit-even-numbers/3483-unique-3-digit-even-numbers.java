class Solution {
    public int totalNumbers(int[] digits) {
        int[] cnt = new int[10];
        for(int d : digits) cnt[d]++;

        int ans=0;
        for(int num = 100; num < 999; num += 2){
            int d1 = num/100;
            int d2 = (num/10)%10;
            int d3 = num%10;

            int[] req = new int[10];
            req[d1]++;
            req[d2]++;
            req[d3]++;

            if(cnt[d1] >= req[d1] && cnt[d2] >= req[d2] && cnt[d3] >= req[d3]) ans++;
        }

        return ans;
    }
}