class Solution {
public:
    int gcd (int a, int b) {
        if (b == 0) return a;
        return gcd(b,a%b);
    }
    int minimizeSet(int divisor1, int divisor2, int uniqueCnt1, int uniqueCnt2) {
        long l = 0;
        long r = 2e9;
        long ans = r;

        long lcm = ((long)divisor1*(long)divisor2)/gcd(divisor1,divisor2);

        while ( l<=r ) {
            long mid = (l+r)/2;
            int x = (int)(mid - (mid/divisor1));
            int y = (int)(mid - (mid/divisor2));
            int z = (int)(mid - (mid/lcm));

            if (x<uniqueCnt1 || y<uniqueCnt2 || z<(uniqueCnt2+uniqueCnt1)){
                l = mid+1;
            }
            else {
                ans = min(ans,mid);
                r = mid-1;
            }
        }
        return (int)(ans);
    }
};
