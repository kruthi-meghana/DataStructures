//Using pre-defined stack;

class MinStack {
    
    private Stack<int[]> minStk = new Stack<>();

    /** initialize your data structure here. */
    public MinStack() {
        
    }
    
    public void push(int val) {
        if(minStk.isEmpty()) {
            minStk.push(new int[] {val, val});
            return;
        }
        
        minStk.push(new int[]{val, Math.min(val, minStk.peek()[1])});
    }
    
    public void pop() {
        if(minStk.isEmpty()) return; //raise Exception
        minStk.pop();
    }
    
    public int top() {
        if(minStk.isEmpty()) return -1;
        return minStk.peek()[0];
    }
    
    public int getMin() {
        if(minStk.isEmpty()) return -1;
        return minStk.peek()[1];
    }
}

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(val);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */
