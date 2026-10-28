class SmallestInfiniteSet {
    private PriorityQueue<Integer> pq;
    private int idx;
    Set<Integer> set;
    public SmallestInfiniteSet() {
        pq = new PriorityQueue<>();
        idx = 1;
        set = new HashSet<>();
    }
    
    public int popSmallest() {
        if(!pq.isEmpty()) {
            set.remove(pq.peek());
            return pq.poll();
        }

        return idx++;
    }
    
    public void addBack(int num) {
        if(num < idx && !set.contains(num)) {
            set.add(num);
            pq.add(num);
        }
    }
}

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet obj = new SmallestInfiniteSet();
 * int param_1 = obj.popSmallest();
 * obj.addBack(num);
 */