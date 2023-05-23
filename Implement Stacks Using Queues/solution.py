class MyStack:

    def __init__(self):
        self.queue = []

    def push(self, x: int) -> None:
        self.queue.append(x)

    def pop(self) -> int:
        for _ in range(len(self.queue)-1):
            self.queue.append(self.queue.pop(0))
        return self.queue.pop(0)

    def top(self) -> int:
        for _ in range(len(self.queue)-1):
            self.queue.append(self.queue.pop(0))
        el = self.queue[0]
        self.queue.append(self.queue.pop(0))
        return el

    def empty(self) -> bool:
        return not self.queue


# Your MyStack object will be instantiated and called as such:
# obj = MyStack()
# obj.push(x)
# param_2 = obj.pop()
# param_3 = obj.top()
# param_4 = obj.empty()