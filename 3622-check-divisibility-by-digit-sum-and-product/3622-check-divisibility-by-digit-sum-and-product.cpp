class Solution {
public:
    int solve(int n){
        int digSum=0, digProduct=1;
        while(n){
            int dig = n%10;
            digSum += dig;
            digProduct *= dig;
            n /= 10;
        }

        return digSum + digProduct;
    }

    bool checkDivisibility(int n) {
        return (n % solve(n) == 0);
    }
};