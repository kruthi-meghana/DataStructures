/*
You are given a string s, and an array of pairs of indices in the string pairs where pairs[i] = [a, b] indicates 2 indices(0-indexed) of the string.

You can swap the characters at any pair of indices in the given pairs any number of times.

Return the lexicographically smallest string that s can be changed to after using the swaps.

Example 01:

Input: s = "dcab", pairs = [[0,3],[1,2]]
Output: "bacd"
Explaination: 
Swap s[0] and s[3], s = "bcad"
Swap s[1] and s[2], s = "bacd"

@author: Kruthi Meghana Anumandla
*/

class Solution {
    
    int[] province;
    
    public String smallestStringWithSwaps(String s, List<List<Integer>> pairs) {
        
        province = new int[s.length()];
        
        for(int i = 0; i < province.length; i++) {
            province[i] = i;
        }
        
        for(List<Integer> pair : pairs) {
            union(pair.get(0), pair.get(1));
        }
        
        Map<Integer, PriorityQueue<Character>> dataStructure = new HashMap<>();
        
        for(int i =0; i < province.length; i++) {
            int parent = find(i);
            dataStructure.putIfAbsent(parent, new PriorityQueue<>());
            dataStructure.get(parent).offer(s.charAt(i));
        }
        
        StringBuilder s_afterSwaps = new StringBuilder();
        
        for(int i = 0; i < province.length; i++) {
            s_afterSwaps.append(dataStructure.get(find(i)).poll());
        }
        
        return s_afterSwaps.toString();
        
    }
    
    public int find(int literal){
        
        int parent = province[literal];
        
        while(parent != province[parent]){
            province[parent] = province[province[parent]];
            parent = province[parent];
        }
        return parent;
    }
    
    public void union(int literal_one, int literal_two){
        
        int parent_one = find(literal_one);
        int parent_two = find(literal_two);
        
        if(parent_one == parent_two){
            return;
        }
        
        if(parent_one < parent_two){
            province[parent_two] = parent_one;
        }
        else{
            province[parent_one] = parent_two;
        }
    }
}
