import numpy
# This is a practice problem relating to Greedy Algorithms
# Problem: Given a set of n activities with start and finish times, find the largest
# set of activities that do not overlap
# Assumption: The activities are sorted increasing order of finish time
# Runtime: O(n) Memory: O(1)
def activitySelection(start, finish):
    if len(finish) == 0:
        return []
    # The first element is always in the optimal set
    schedule = [0]
    # Index for last element added
    for i in range(1, len(finish)):
        if start[i] >= finish[schedule[-1]]:
            schedule.append(i)

    return schedule

# Now what if the finish and start times weren't in any particular order?
# We'd have to sort by index in order to use the previous algorithm
# Runtime O(nlogn) Memory O(n)

# Purpose: Sort the finish list and return the indices
# Could also have implemented this using sorted([(elem, i) for elem, i in enumurate(finish)])
# but numpy.argsort() is much more efficient per
# https://stackoverflow.com/questions/6422700/how-to-get-indices-of-a-sorted-array-in-python
def indexSort(finish):
    return list(numpy.argsort(finish))

def activitySelectionUnsorted(start, finish):
    if len(start) == 0:
        return []
    # Get the indices of the sorted finish array
    indices = indexSort(finish)
    schedule = [indices[0]]

    for index in indices[1:]:
        if start[index] >= finish[schedule[-1]]:
            schedule.append(index)

    return schedule

# Test for empty set
def testEmpty():
    start, finish = [], []
    assert(activitySelection(start, finish) == [])
    assert(activitySelectionUnsorted(start, finish) == [])

# Testing a normal set of activities
def testRegular():
    start = [1, 3, 0, 5, 3, 5, 6, 8, 8, 2, 12]
    finish = [4, 5, 6, 7, 9, 9, 10, 11, 12, 14, 16]
    answer = [0, 3, 7, 10]
    assert(activitySelection(start, finish) == answer)

def testUnsorted():
    start = [3, 6, 2, 3, 5, 1, 12, 8, 0, 8, 5]
    finish = [5, 10, 14, 9, 7, 4, 16, 12, 6, 11, 9]
    answer = [5, 4, 9, 6]
    assert(activitySelectionUnsorted(start, finish) == answer)

def testAllSame():
    start = [5, 5, 5, 5]
    finish = [10, 10, 10, 10]
    assert(activitySelection(start, finish) == [0])
    assert(activitySelectionUnsorted(start, finish) == [0])

def main():
    testEmpty()
    testRegular()
    testUnsorted()
    testAllSame()

if __name__ == '__main__':
    main()
