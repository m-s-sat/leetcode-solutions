class Solution {
public:
    bool checkDivisibility(int n) {
        int num = n;
        int sum = 0, prod = 1;
        while(num>0){
            int digit = num%10;
            sum+= digit;
            prod*=digit;
            num/=10;
        }
        return (sum + prod) != 0 && n % (sum + prod) == 0;
    }
};