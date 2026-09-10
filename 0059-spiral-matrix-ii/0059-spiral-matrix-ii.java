class Solution {
    public int[][] generateMatrix(int n) {
        int srow = 0, scol = 0;
        int erow = n-1, ecol = n-1;
        int num = 1;
        int[][] ans = new int[n][n];

        while(srow <= erow && scol <= ecol){
            for(int j = scol; j <= ecol; j++){
                ans[srow][j] = num++;
            }

            for(int i=srow+1; i <= erow; i++){
                ans[i][ecol] = num++;
            }

            for(int j = ecol-1; j >= scol; j--){
                if(srow == erow) break;
                ans[erow][j] = num++;
            }

            for(int i = erow-1; i >= srow+1; i--){
                if(scol == ecol) break;
                ans[i][scol] = num++;
            }

            srow++; erow--;
            scol++; ecol--;
        }

        return ans;
    }
}