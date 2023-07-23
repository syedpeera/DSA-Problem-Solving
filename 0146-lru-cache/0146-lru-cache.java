class LRUCache {
    private class Node{
        int key;
        int value;
        Node next;
        Node prev;
        Node(int k, int v){
            key = k;
            value = v;
            next = null;
            prev = null;
        }
    }
    
    private Map<Integer, Node> cache;
    private int capacity;
    private Node head;
    private Node tail;
    
    public LRUCache(int cap) {
        capacity = cap;
        cache = new HashMap<>();
        head = new Node(-1, -1);
        tail = new Node(-1, -1);
        head.next = tail;
        tail.prev = head;
    }
    
    public void addToFront(Node node){
        node.next = head.next;
        node.prev = head;
        head.next = node;
        node.next.prev = node;
    }
    
    public void removeNode(Node node){
        node.prev.next = node.next;
        node.next.prev = node.prev;
    }
    
    public int get(int key) {
        if(cache.containsKey(key)){
            Node node = cache.get(key);
            removeNode(node);
            addToFront(node);
            return node.value;
        }
        return -1;
    }
    
    public void put(int key, int value) {
        if(cache.containsKey(key)){
            Node node = cache.get(key);
            node.value = value;
            removeNode(node);
            addToFront(node);
        }
        else{
            if(cache.size() >= capacity){
                Node nodeToRemove = tail.prev;
                removeNode(nodeToRemove);
                cache.remove(nodeToRemove.key);
            }
            Node newNode = new Node(key, value);
            addToFront(newNode);
            cache.put(key, newNode);
        }
    }
}

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache obj = new LRUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */