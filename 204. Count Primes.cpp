int dp[5000005];
bool sieve[5000005];
void calculate(){
    memset(sieve, true, sizeof(sieve));
    sieve[0] = sieve[1] = false;
    for(int i=2; i*i<5000005; i++){
        if(sieve[i]){
            for(int j=i*i; j<5000005; j+=i){
                sieve[j] = false;
            }
        }
    }
    dp[0] = 0, dp[1] = 0;
    for(int i=2; i<5000005; i++){
        if(sieve[i]) dp[i] = dp[i-1] + 1;
        else dp[i] = dp[i-1];
    }
}
class Solution
{
public:
    int countPrimes(int n)
    {
       static int x = 0;
       if(x == 0)
       {
       calculate();
       x++;
       }
       return sieve[n] ? dp[n-1] : dp[n];
    }
};
