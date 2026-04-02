class Solution {
public:
        int m;
        int n;
        int dp[501][501][3];

    int robot(vector<vector<int>>& coins,int i, int j,int Chance){
      

        //base case

        //last index pr gya to nikal max
        if(i == n-1 && j == m-1){
            if(Chance > 0 && coins[i][j] < 0){
                
                return 0;
                }
            return coins[i][j];  
        }
        if( i >= n || j >= m){
            return INT_MIN;
        }

        if(dp[i][j][Chance] != INT_MIN){
            return dp[i][j][Chance];
        }
   

    // take (ALWAYS try this)
    int take = coins[i][j] + max(robot(coins, i+1, j, Chance), robot(coins, i, j+1, Chance));

    int skip = INT_MIN;
    if(coins[i][j] < 0 && Chance > 0){
        int skipDown = robot(coins,i+1,j,Chance-1);
        int skipRight = robot(coins,i,j+1,Chance-1);

        skip = max(skipDown,skipRight);
    }

        return dp[i][j][Chance] = max(take,skip);
            
    }


    int maximumAmount(vector<vector<int>>& coins) {

        n = coins.size();
        m = coins[0].size();

        for(int i = 0; i< 501; i++){
            for(int j = 0; j<501;j++){
                for(int k = 0; k<3;k++){
                    dp[i][j][k] = INT_MIN;
                }
            }
        }

        
       return robot(coins,0,0,2);
    }
};