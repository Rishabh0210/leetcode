//https://leetcode.com/explore/challenge/card/june-leetcoding-challenge/541/week-3-june-15th-june-21st/3367/

class Solution {
    int min=0;
    public int calculateMinimumHP(int[][] d) {
       
        int m=d.length;
        int n=d[0].length;
        
        int[][] dp=new int[m][n];
        
        dp[m-1][n-1]= Math.max(1-d[m-1][n-1],1);
        
        for(int i=n-2;i>=0;i--){
            int val=d[m-1][i];
            dp[m-1][i]=Math.max(dp[m-1][i+1] - val,1);
        }
        
        for(int i=m-2;i>=0;i--){
            int val=d[i][n-1];
            
            dp[i][n-1]=Math.max(dp[i+1][n-1] - val,1);
            
        }
        
        
        for(int i=m-2;i>=0;i--){
            for(int j=n-2;j>=0;j--){
                
                int val=d[i][j];
                int min=Math.min(dp[i][j+1],dp[i+1][j]);
                
                dp[i][j]=Math.max(min-val,1);
                
            }
        }
        
        return dp[0][0];
        
    }
    
    
}