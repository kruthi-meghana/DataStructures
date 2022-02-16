/*
There are n cities. Some of them are connected, while some are not. If city a is connected directly with city b, and city b is connected directly with city c, then city a is connected indirectly with city c.

A province is a group of directly or indirectly connected cities and no other cities outside of the group.

You are given an n x n matrix isConnected where isConnected[i][j] = 1 if the ith city and the jth city are directly connected, and isConnected[i][j] = 0 otherwise.

Return the total number of provinces.
@author: Kruthi Meghana Anumandla
*/



class Solution {
    
    public void dfs(int[][] isConnected, int[] visited, int index){
        
        for(int j = 0; j < visited.length; j++) {
            if(isConnected[index][j] == 1 && visited[j] == 0) {
                visited[j] = 1;
                dfs(isConnected, visited, j);
            }
        }
    }
    
    public int findCircleNum(int[][] isConnected) {
        
        int[] visited = new int[isConnected.length];
        int provision = 0;
        Arrays.fill(visited, 0);
        
        for(int i = 0; i < visited.length; i++) {
            if(visited[i] == 0) {
                dfs(isConnected,visited, i);
                provision += 1;
            }
        }
        return provision;
    }
}
