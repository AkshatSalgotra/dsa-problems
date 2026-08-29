class Solution {
public:
    int minBishopMoves(vector<int>& source, vector<int>& target) {
        if(((source[0]+target[0])%2 == 1 && (source[1]+target[1])%2 == 0) || ((source[0]+target[0])%2 == 0 && (source[1]+target[1])%2 == 1) ) return -1;
        else if (abs(source[0]-target[0]) == abs(source[1]-target[1])) return 1;
        else return 2;
    }
};