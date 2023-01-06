
class BinaryTreeDiameter:
    def __init__(self, value, right, left):
        self.value = value
        self.left = left
        self.right = right


def solution(tree):
    return getTreeDiameter(tree).diameter


def getTreeDiameter(root):
    if(root == None):
        return TreeInfo(0, 0)

    # get the treeInfo from both left and right subtree:
    leftTreeData = getTreeDiameter(root.left)
    rightTreeData = getTreeDiameter(root.right)

    longestPathThroughRoot = leftTreeData.height + rightTreeData.height
    currentHeight = 1 + max(leftTreeData.height, rightTreeData.height)
    maxDiameterSoFar = max(leftTreeData.diameter, rightTreeData.diameter)
    currentDiameter = max(maxDiameterSoFar, longestPathThroughRoot)

    return TreeInfo(currentHeight, currentDiameter)


class TreeInfo:
    def __init__(self, height, diameter) -> None:
        self.diameter = diameter
        self.height = height
