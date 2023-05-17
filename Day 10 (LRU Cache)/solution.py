class LRUCache:
    
    def __init__(self, capacity: int):
        self.lru = {}
        self.capacity = capacity

    def get(self, key: int) -> int:
        if key in self.lru:
            val = self.lru.pop(key)
            self.lru[key] = val
            return val
        return -1

    def put(self, key: int, value: int) -> None:
        if key in self.lru:
            self.lru.pop(key)
        
        self.lru[key] = value
        
        if len(self.lru) > self.capacity:
            for k in self.lru:
                break
            self.lru.pop(k)
        


# Your LRUCache object will be instantiated and called as such:
# obj = LRUCache(capacity)
# param_1 = obj.get(key)
# obj.put(key,value)