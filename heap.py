class minHeap:
    def __init__():
        self.heap = []

    # Defining helper functions to be used in the main methods
    def get_parent_index(index): return (index - 1) // 2
    def get_left_child_index(index): return 2 * index + 1
    def get_right_child_index(index): return 2 * index + 2
    def get_parent(index): return self.heap[self.get_parent_index(index)]
    def get_left_child(index): return self.heap[self.get_left_child_index(index)]
    def get_right_child(index): return self.heap[self.get_right_child_index(index)]
    def has_left_child(index): return self.get_left_child_index(index) < len(self.heap)
    def has_right_child(index): return self.get_right_child_index(index) < len(self.heap)

    def fix_up():
        index = len(self.heap) - 1
        parent_index = self.get_parent_index(index)
        while parent_index >= 0 and self.heap[index] < self.get_parent(index):
            self.heap[index], self.heap[parent_index] = self.heap[parent_index], self.heap[index]
            index = parent_index
            parent_index = self.get_parent_index(index)
        return

    def fix_down():
        index = 0
        while self.has_left_child(index):
            small_index = self.get_left_child_index(index)
            if self.has_right_child(index) and self.get_right_child(index) < self.heap[small_index]:
                small_index = self.get_right_child_index(index)

            if self.heap[index] < self.heap[small_index]:
                break
                
            self.heap[index], self.heap[small_index] = self.heap[small_index], self.heap[index]
            index = small_index

    def push(value):
        self.heap.append(value)
        self.fix_up()
        return


    def pop():
        if not self.heap():
            throw IndexError()
        min_elem = self.heap[0]
        self.heap[0] = self.heap[-1]
        self.heap.pop()
        self.fix_down()
        return min_elem
