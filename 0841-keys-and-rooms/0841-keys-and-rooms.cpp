class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        vector<bool> visited(rooms.size(),false);
        queue<int> q;
        q.push(0);
        visited[0]=true;
        int rooms_visited=1;
        while(!q.empty()){
            int cur_room=q.front();
            q.pop();
            for(int i=0;i<rooms[cur_room].size();i++){
                if(!visited[rooms[cur_room][i]]){
                    visited[rooms[cur_room][i]]=true;
                    rooms_visited++;
                    q.push(rooms[cur_room][i]);
                }
            }
        }
        return rooms_visited==rooms.size();
    }
};