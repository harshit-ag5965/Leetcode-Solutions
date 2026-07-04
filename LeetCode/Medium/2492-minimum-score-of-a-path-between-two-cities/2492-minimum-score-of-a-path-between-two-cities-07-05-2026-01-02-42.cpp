class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
      // Today's Potd is very easy using simple bfs approach
      // Adjacency List creation
      //1 based indexing
      vector<pair<int,int>>adj[n+1];
        for(int i=0;i<roads.size();i++){
            int u=roads[i][0];
            int v=roads[i][1];
            int weight=roads[i][2];
            adj[u].push_back({v,weight});
            adj[v].push_back({u,weight});
        }
  priority_queue<pair<int,int>,
               vector<pair<int,int>>,
               greater<pair<int,int>>> q;
        vector<bool>visited(n+1,false);
        q.push({0,1});
        visited[1]=true;
     vector<int>dis(n+1,INT_MAX);
        while(!q.empty()){
            int weight=q.top().first;
            int node=q.top().second;
            q.pop();
       
            for(int i=0;i<adj[node].size();i++){
                int nextnode=adj[node][i].first;
                    int nextweight=adj[node][i].second;
                    dis[nextnode]=min(dis[nextnode],nextweight);
              if(!visited[nextnode]){ 
            
                visited[nextnode]=true;
                q.push({nextweight,nextnode});
              }
            }
        }
        int mini=INT_MAX;
      for(auto i:dis){
        mini=min(mini,i);
      }
        return mini;

        
    }
};