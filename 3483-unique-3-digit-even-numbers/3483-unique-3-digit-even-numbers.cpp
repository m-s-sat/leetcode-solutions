class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        vector<int> freq(10, 0);
        for(int digit : digits)  freq[digit]++;
        int ans = 0;
        for(int num = 100; num <= 999; num++) {
            if (num % 2 != 0) continue;
            int x = num;
            int ones = x % 10;
            x /= 10;
            int tens = x % 10;
            x /= 10;
            int hundreds = x % 10;
            freq[ones]--;
            freq[tens]--;
            freq[hundreds]--;
            if(freq[ones] >= 0 && freq[tens] >= 0 && freq[hundreds] >= 0)  ans++;
            freq[ones]++;
            freq[tens]++;
            freq[hundreds]++;
        }
        return ans;
    }
};