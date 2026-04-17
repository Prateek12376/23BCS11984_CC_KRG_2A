class Exp3 {
    public int nthMagicalNumber(int n, int a, int b) {
        long mod = 1000000007;
        long l = 1, r = (long) n * Math.min(a, b);
        long lcm = (long) a * b / gcd(a, b);

        while (l < r) {
            long mid = (l + r) / 2;
            long count = mid / a + mid / b - mid / lcm;
            if (count < n) l = mid + 1;
            else r = mid;
        }
        return (int) (l % mod);
    }

    long gcd(long a, long b) {
        if (b == 0) return a;
        return gcd(b, a % b);
    }
}
