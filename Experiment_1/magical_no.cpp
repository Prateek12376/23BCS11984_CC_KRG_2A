class Solution {
public:
    int nthMagicalNumber(int n, int a, int b) {
        long mod = 1e9 + 7;
        long low = 1, high = (long)n * min(a, b);
        
        long gcd = __gcd(a, b);
        long lcm = (long)a * b / gcd;
        
        while (low < high) {
            long mid = low + (high - low) / 2;
            
            long count = mid/a + mid/b - mid/lcm;
            
            if (count < n)
                low = mid + 1;
            else
                high = mid;
        }
        
        return low % mod;
    }
};
