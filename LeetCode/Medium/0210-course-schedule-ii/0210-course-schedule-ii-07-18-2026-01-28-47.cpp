class Solution {
public:
    vector<int>result;
    bool dfs(int node, vector<int>& visited, vector<int>& path, vector<vector<int>>& adj){
        visited[node] = 1;
        path[node] = 1;

        for(auto it: adj[node]){
            if(visited[it] == 0){
                if(!dfs(it, visited, path, adj))return false;;
            }
            else if(path[it] == 1)return false;
        }
        path[node] = 0;
        result.push_back(node);
        return true;
    }

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>>adj(numCourses);

        for(auto it: prerequisites){
            adj[it[0]].push_back(it[1]);
        }

        vector<int>visited(numCourses,0);
        vector<int>path(numCourses,0);

        for(int i=0; i<numCourses; i++){
            if(visited[i] == 0){
                if(!dfs(i,visited, path, adj))return {};
            }
        }
        return result;;
    }
};