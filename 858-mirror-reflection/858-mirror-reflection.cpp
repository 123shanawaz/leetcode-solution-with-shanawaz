class Solution
{
public:
    int gcd(int a, int b)
    {
        while (b)
        {
            a %= b;
            swap(a, b);
        }
        return a;
    }
    int mirrorReflection(int p, int q)
    {
        int lcm = p * q / gcd(p, q);
        int a = lcm / p;
        int b = lcm / q;
        return (a % 2 == 0) ? 0 : (b % 2 == 0 ? 2 : 1);
    }
};