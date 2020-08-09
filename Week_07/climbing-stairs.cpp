class Solution {
public:
    int climbStairs(int n) {
        if(n == 0) return 0;
        if(n == 1) return 1;
        if(n == 2) return 2;

        int v1 = 1;
        int v2 = 2;
        int v3 = 0;
        for(int i=3; i<=n; i++ ){
            v3 = v1 + v2;
            v1 = v2;
            v2 = v3;
        }
        return v3;
    }
};