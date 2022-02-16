/*
You have a graph of n nodes labeled from 0 to n - 1. You are given an integer n and a list of edges where edges[i] = [ai, bi] indicates that there is an undirected edge between nodes ai and bi in the graph.

Return true if the edges of the given graph make up a valid tree, and false otherwise.
@author: Kruthi Meghana Anumandla
*/

class Solution {
    
    public boolean isConnected(int[][] edges, int[] visited) {
        int count = 0;
        for(int i = 0; i < edges.length; i++) {
            //check if it is a cycle
            if(visited[edges[i][0]] != -1 && visited[edges[i][1]] == visited[edges[i][0]]) {
                return false;
            }
            if(visited[edges[i][0]] == -1 && visited[edges[i][1]] == -1){
                visited[edges[i][0]] = edges[i][0];
                visited[edges[i][1]] = edges[i][0];
                count += 2;
                
            }else if(visited[edges[i][1]] == -1){
                visited[edges[i][1]] = visited[edges[i][0]];
                count += 1;
                
            }else if(visited[edges[i][0]] == -1){
                visited[edges[i][0]] = visited[edges[i][1]];
                count += 1;
                
            }
            
        }
        if(count == visited.length) return true;
        return false;
    }
    
    public boolean validTree(int n, int[][] edges) {
        
        if(edges.length == 0 && n == 1) return true;
        
        int length = edges.length;
        
        if(length != n-1) return false;
        
        int[] visited = new int[n];
        Arrays.fill(visited, -1);
        
        return isConnected(edges, visited);
        
    }
}
