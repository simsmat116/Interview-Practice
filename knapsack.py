# This is a practice problem relating to Greedy Algorithms
# Problem: Given n items and lists of their values and weights, find the set of items
# that leads to the great value without exceeding weight W
# Assumption: Weights and values are non-negative
def fractionalKnapsack(values, weights, W):
    if len(values) == 0 or W == 0:
        return []

    # Compute the value to weight ratio for each item
    ratios = [(values[i] / weights[i], i) for i in range(len(values))]
    # Sort the list of ratios - in Python, list.sort() for tuples sorts by first index
    # and then uses the second value for cases of equality
    ratio.sort()
    # List for storing the results - going to store the item index and how much (e.g (0, 2/3))
    final_items = []

    for item in ratios:
        remaining_weight = max(0, W - weight[item[1]])
        weight_contributed = weight[item[1]] if remaining_weight > 0 else W
        final_items.append((item[1], weight_contributed))

        W = remaining_weight
        if W == 0:
            break

    return final_items

def main():
    print("Hello World!")

if __name__ == '__main__':
    main()
