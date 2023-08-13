class Solution {
public:
    int solve(vector<int> &days,vector<int> &costs,int currDay,unordered_set<int> &travelNeeded,
             vector<int> &dp){
        if(currDay>days[days.size()-1])
            return 0;
        if(travelNeeded.find(currDay)==travelNeeded.end()){
            return solve(days,costs,currDay+1,travelNeeded,dp);
        }
        if(dp[currDay]!=-1)
            return dp[currDay];
        int oneticket=costs[0]+solve(days,costs,currDay+1,travelNeeded,dp);
        int seventicket=costs[1]+solve(days,costs,currDay+7,travelNeeded,dp);
        int monthticket=costs[2]+solve(days,costs,currDay+30,travelNeeded,dp);
        return dp[currDay]=min({oneticket,seventicket,monthticket});
        
    
}
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        unordered_set<int> travelNeeded;
        int last=days[days.size()-1];
        vector<int> dp(last+1,-1);
        for(int i:days)
            travelNeeded.insert(i);
        return solve(days,costs,1,travelNeeded,dp);
    }
};