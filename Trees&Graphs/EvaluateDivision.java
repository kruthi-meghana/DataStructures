/*
You are given an array of variable pairs equations and an array of real numbers values, where equations[i] = [Ai, Bi] and values[i] represent the equation Ai / Bi = values[i]. Each Ai or Bi is a string that represents a single variable.

You are also given some queries, where queries[j] = [Cj, Dj] represents the jth query where you must find the answer for Cj / Dj = ?.

Return the answers to all queries. If a single answer cannot be determined, return -1.0.

Note: The input is always valid. You may assume that evaluating the queries will not result in division by zero and that there is no contradiction.
@author: Kruthi Meghana Anumandla
*/

class Solution {
    
    
    public double compute(HashMap<String, HashMap<String, Double>> dataStructure, String literal_one, String literal_two, HashSet<String> visited) {
        
        visited.add(literal_one);
        
        HashMap<String, Double> buffer = dataStructure.get(literal_one);
        if(buffer.containsKey(literal_two)) {
            return buffer.get(literal_two);
        }
       
        for(String key: buffer.keySet()) {
            if(visited.contains(key)) {
                continue;
            }
            double ans = compute(dataStructure, key, literal_two, visited);
            if(ans == -1){
                continue;
            }
            return buffer.get(key) * ans;
        }
        return -1;
        
    }
    
    public double[] calcEquation(List<List<String>> equations, double[] values, List<List<String>> queries) {
        
        
        HashMap<String, HashMap<String, Double>> dataStructure =  new HashMap<>();
        
        double[] results = new double[queries.size()];
        int i = 0;
        
        for(List<String> pair: equations) {
            
            String literal_one = pair.get(0), literal_two = pair.get(1);
            
            if(!dataStructure.containsKey(literal_one))
                dataStructure.put(literal_one, new HashMap<String, Double>());
            
            if(!dataStructure.containsKey(literal_two))
                dataStructure.put(literal_two, new HashMap<String, Double>());
        
            dataStructure.get(literal_one).put(literal_two, values[i]);
            dataStructure.get(literal_two).put(literal_one, 1/values[i]);
            
            i += 1;
        }
        
        i = 0;
        
        for(List<String> query: queries) {
           
            String literal_one = query.get(0), literal_two = query.get(1);
            if(!dataStructure.containsKey(literal_one) || !dataStructure.containsKey(literal_two))
                results[i] = -1.0;
            else if(literal_one == literal_two)
                results[i] = 1.0;
            else{
                HashSet<String> visitedNodes = new HashSet<String>();
                results[i] = compute(dataStructure,  literal_one, literal_two, visitedNodes);
            }
            
            i += 1;
        }
        
        return results; 
    }
}
