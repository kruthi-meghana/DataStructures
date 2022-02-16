/*
You have a graph of n nodes. You are given an integer n and an array edges where edges[i] = [ai, bi] indicates that there is an edge between ai and bi in the graph.

Return the number of connected components in the graph.
@author: Kruthi Meghana Anumandla
*/

class Solution {
    public int countComponents(int n, int[][] edges) {
        int[] parents = new int[n];
        int[] rank = new int[n];
        
        Arrays.fill(rank, 1);
        
        for(int i = 0; i < parents.length; i++){
            parents[i] = i;
        }
        
        return n - union(edges, parents, 0, rank);
    }
    
    public int find(int[] parents, int node){
        int res = parents[node];
        while(res != parents[res]){
            parents[res] = parents[parents[res]];
            res = parents[res];
        }
        return res;
    }
    
    public int union(int[][] edges, int[] parents, int edge, int[] rank){
        if(edge == edges.length) return 0;
        
        int p1 = find(parents, edges[edge][0]);
        int p2 = find(parents, edges[edge][1]);
        if(p1 == p2){
            return union(edges, parents, edge+1, rank);
        }
        
        if(rank[p2] > rank[p1]){
            parents[p1] = p2;
            rank[p2] += rank[p1];
        }
        else{
            parents[p2] = p1;
            rank[p1] += rank[p2];
        }
        
        return union(edges, parents, edge+1, rank) + 1;
    }
}
