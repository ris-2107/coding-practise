# find the diameter of the Binary Tree


# O(n) time |  O(n) space complexity:
class BinaryTreeDiameter:
    def __init__(self, value, right, left):
        self.value = value
        self.left = left
        self.right = right


def binaryTreeInfo(tree):
    return getTreeInfo().diameter


def getTreeInfo(tree):

    if(tree is None):
        return TreeInfo(0, 0)

    leftTreeData = getTreeInfo(tree.right)
    rightTreeData = getTreeInfo(tree.left)
   # We need to calculate the maximum diameter of both STs and then take maximum
   # We need to get the maximum height so far from both STs
    # We have answer as the max of {maxHeight , maxDiameter}
    longestPathThroughRoot = leftTreeData.height + rightTreeData.height
    currentHeight = 1 + max(rightTreeData.height, leftTreeData.height)
    currentDiameter = max(longestPathThroughRoot,
                          leftTreeData.diameter, rightTreeData.diameter)

    return TreeInfo(currentDiameter, currentHeight)


class TreeInfo:
    def __init__(self, diameter, height):
        self.diameter = diameter
        self.height = height
