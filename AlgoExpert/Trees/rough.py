# PowerSet generation
# p(1,2,3) = [[1],[2],[3],[1,2] ... [1,2,3]]


def powerset(array):
    subsets = [[]]
    te = []

    for ele in array:
        for i in range(len(subsets)):
            currentSubset = subsets[i]
            # [ele] = an array containing just the element
            subsets.append(currentSubset + [ele])

    for idx, ele in enumerate(subsets):
        print(idx, ele)

    return subsets


array = [1, 2, 3]
powerset(array)
