class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        map<int, vector<int>> mp;
        for(auto it: reservedSeats){
            int row = it[0];
            int col = it[1];
            if(mp.find(row)==mp.end()){
                vector<int> seats(11,0);
                mp[row] = seats;
            }
            mp[row][col] = 1;
        }
        int cnt = 2*(n-mp.size());
        for(auto it: mp){
            vector<int> seats = it.second;
            int leftFit = true, midFit = true, rightFit = true;
            for(int i=2;i<=5;i++){
                if(seats[i]==1) leftFit = false;
            }
            for(int i=4;i<=7;i++){
                if(seats[i]==1) midFit = false;
            }
            for(int i=6;i<=9;i++){
                if(seats[i]==1) rightFit = false;
            }
            if(leftFit&&rightFit) cnt+=2;
            else if(leftFit || rightFit || midFit) cnt+=1;
        }
        return cnt;
    }
};