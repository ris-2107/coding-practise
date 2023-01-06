
from matplotlib.pyplot import bar_label


class BinaryTreeDiameter:
    def __init__(self, value, right, left, parent):
        self.value = value
        self.left = left
        self.right = right


# O(n) time and O(h) space
def heightBalancedBinaryTree(tree):
    treeInfo = getTreeInfo(tree)
    return treeInfo.isBalanced


class TreeInfo():
    def __init__(self, height, isBalanced):
        self.height = height
        self.isBalanced = isBalanced


def getTreeInfo(node):
    if node == None:
        # the '-1' signifies that the node is non-existent and hence has a height of -1
        return TreeInfo(True, -1)

    leftSubtreeInfo = getTreeInfo(node.left)
    rightSubtreeInfo = getTreeInfo(node.right)

    isBalanced = leftSubtreeInfo.isBalanced and rightSubtreeInfo.isBalanced and abs(
        leftSubtreeInfo.height - rightSubtreeInfo.height) <= 1
    height = max(leftSubtreeInfo.height, rightSubtreeInfo.height)+1
    return TreeInfo(isBalanced, height)
