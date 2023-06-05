class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        if(coordinates.size()==2)
            return true;
        double slope=0.0;
        bool xaxis=false;
        bool yaxis=false;
        for(int i=2;i<coordinates.size();i++){
            if((coordinates[i][0]-coordinates[i-1][0])!=0){
                slope=(double)(coordinates[i][1]-coordinates[i-1][1])/(double)(coordinates[i][0]-coordinates[i-1][0]);              
            }
            if(coordinates[i][0]==coordinates[i-1][0] && coordinates[i-1][0]==coordinates[i-2][0])
                xaxis=true;
            else
                xaxis=false;
            if(coordinates[i][1]==coordinates[i-1][1] && coordinates[i-1][1]==coordinates[i-2][1])
                yaxis=true;
            else
                yaxis=false;
        }
        if(xaxis || yaxis)
            return true;
        int intercept=coordinates[0][1]-slope*coordinates[0][0];
        for(int i=0;i<coordinates.size();i++){
            if(coordinates[i][1]!=slope*coordinates[i][0]+intercept)
                return false;
        }
       
        return true;
    }
};