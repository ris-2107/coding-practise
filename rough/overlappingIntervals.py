# Sort the given 2D array based on the 1st part of each pair
#condition: end>=start

from heapq import merge


def mergeOverlappingIntervals(intervals):

    # Sort :
    sortedIntervals = sorted(intervals, key=lambda x: x[0])
    mergedIntervals = []
    currentInterval = sortedIntervals[0]
    mergedIntervals.append(currentInterval)

    for nextInterval in sortedIntervals:
        currentIntervalStart, currentIntervalEnd = currentInterval
        nextIntervalStart, nextIntervalEnd = nextInterval

        if currentIntervalEnd >= nextIntervalStart:
            currentInterval[1] = max(currentIntervalEnd, nextIntervalEnd)
            
        else:
            currentInterval = nextInterval
            mergedIntervals.append(currentInterval)
    return mergedIntervals


print(mergeOverlappingIntervals([[1, 5], [3, 7], [4, 5], [9, 15]]))
