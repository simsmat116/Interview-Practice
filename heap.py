class minHeap:
    def __init__(self):
        self.heap = []

    # Defining helper functions to be used in the main methods
    def get_parent_index(self, index): return (index - 1) // 2
    def get_left_child_index(self, index): return 2 * index + 1
    def get_right_child_index(self, index): return 2 * index + 2
    def get_parent(self, index): return self.heap[self.get_parent_index(index)]
    def get_left_child(self, index): return self.heap[self.get_left_child_index(index)]
    def get_right_child(self, index): return self.heap[self.get_right_child_index(index)]
    def has_left_child(self, index): return self.get_left_child_index(index) < len(self.heap)
    def has_right_child(self, index): return self.get_right_child_index(index) < len(self.heap)

    def fix_up(self):
        index = len(self.heap) - 1
        parent_index = self.get_parent_index(index)
        while parent_index >= 0 and self.heap[index] < self.get_parent(index):
            self.heap[index], self.heap[parent_index] = self.heap[parent_index], self.heap[index]
            index = parent_index
            parent_index = self.get_parent_index(index)
        return

    def fix_down(self):
        index = 0
        while self.has_left_child(index):
            small_index = self.get_left_child_index(index)
            if self.has_right_child(index) and self.get_right_child(index) < self.heap[small_index]:
                small_index = self.get_right_child_index(index)

            if self.heap[index] < self.heap[small_index]:
                break

            self.heap[index], self.heap[small_index] = self.heap[small_index], self.heap[index]
            index = small_index

    def push(self, value):
        self.heap.append(value)
        self.fix_up()
        return

    def pop(self):
        if not self.heap:
            raise IndexError()
        min_elem = self.heap[0]
        self.heap[0] = self.heap[-1]
        self.heap.pop()
        self.fix_down()
        return min_elem

    def top(self):
        if not self.heap:
            raise IndexError()
        return self.heap[0]


def test_push():
    print("RUNNING - test_push")
    heap = minHeap()
    heap.push(20)
    assert(heap.top() == 20)
    heap.push(10)
    heap.push(17)
    assert(heap.top() == 10)
    heap.push(2)
    assert(heap.top() == 2)
    print("PASSED - test_push")

def test_empty():
    print("RUNNING - test_empty")
    heap = minHeap()
    error_raised = False
    try:
        heap.pop()
    except IndexError:
        error_raised = True
    assert(error_raised)
    print("PASSED - test_empty")

def test_pop():
    print("RUNNING - test_pop")
    heap = minHeap()
    nums = [32, 17, 45, 14, 7]
    for num in nums:
        heap.push(num)
    nums.sort()
    for num in nums:
        assert(heap.pop() == num)
    print("PASSED - test_pop")

def main():
    test_push()
    test_empty()
    test_pop()



if __name__ == '__main__':
    main()
