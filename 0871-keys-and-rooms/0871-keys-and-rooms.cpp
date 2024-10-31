class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n=rooms.size();
        vector<bool> keys(n, false);
        keys[0]=true;
        queue<int>q;
        while(!q.empty()){
            int key=q.front();
            q.pop();
            keys[key]=true;
            for(int &e:rooms[key]){
                if(!keys[e])q.push(e);
            }
        }
        for(int i=0;i<n;i++){
            if(!keys[i]) return false;
        }
        return true;
    }
};