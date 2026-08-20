class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& img, int sr, int sc, int color) {
        int r = img.size();
        int c = img[0].size();
        int iniColor = img[sr][sc];
        if(iniColor == color) return img;

        queue<pair<int, int>> q;
        q.push({sr, sc});
        img[sr][sc] = color;

        int dr[] = {-1, 0, 1, 0};
        int dc[] = {0, -1, 0, 1};
        while(!q.empty()){
            auto it = q.front();
            q.pop();

            for(int k=0; k < 4; k++){
                int nr = dr[k] + it.first;
                int nc = dc[k] + it.second;

                if(nr >= 0 && nr < r && nc >= 0 && nc < c && img[nr][nc] == iniColor){
                    q.push({nr, nc});
                    img[nr][nc] = color;
                }
            }
        }

        return img;
    }
};