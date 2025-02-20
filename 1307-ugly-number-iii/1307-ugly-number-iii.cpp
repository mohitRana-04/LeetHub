class Solution {
public:

    bool feasible(long long mid, long long n, long a, long b, long c) {
        // Pass int to __gcd while calculating LCM using long long
        long long ab = (long long)a * b / __gcd((int)a, (int)b);
        long long bc = (long long)b * c / __gcd((int)b, (int)c);
        long long ac = (long long)a * c / __gcd((int)a, (int)c);
        long long abc = ab * c / __gcd((int)ab, (int)c);

        // Calculate how many numbers are divisible by a, b, c, ab, ac, bc, and abc
        long long sum = mid / a + mid / b + mid / c
                         - mid / ab - mid / ac - mid / bc
                         + mid / abc;

        return sum >= n; // If there are at least n numbers
    }

    int nthUglyNumber(int n, int a, int b, int c) {
        long long l = 1, r = 2e9;  // Use long long for both bounds

        while (l < r) {
            long long mid = l + (r - l) / 2;
            if (feasible(mid, n, a, b, c)) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        return (int)l;  // Return the result as an integer
    }
};
