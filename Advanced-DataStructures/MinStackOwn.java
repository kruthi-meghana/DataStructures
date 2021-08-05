class MinStackOwn {
    StackNode top;
   

    /** initialize your data structure here. */
    public MinStackOwn() {
        top = null;   
    }
    
    public void pop() {
        if(top == null) return;
        top = top.next;
    }
  
    public int top(){
        if(top == null) return -1;
        return top.value;
    }
    
    public void push(int value) {
        if(top == null) {
            top = new StackNode(value, value, null);
            return;
        }
        StackNode node = new StackNode(value, Math.min(value, getMin()), top);
        top = node;
    }
    
    public int getMin(){ 
        if(top == null) return -1;
        return top.minUntil;
    }
    
    private class StackNode {
        int value;
        int minUntil;
        StackNode next;
        
        private StackNode(int value, int minUntil, StackNode next) {
            this.value = value;
            this.minUntil = minUntil;
            this.next = next;
        }
    }
      
}
