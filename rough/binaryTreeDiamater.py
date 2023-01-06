class BinaryTree:
    def __init__(self, value, left=None, right=None):
        self.value = value
        self.left = left
        self.right = right


# Our required Method:
def binaryTreeDiameter(tree):
    return getTreeInfo(tree).diameter


def getTreeInfo(tree):
    if(tree is None):
        return TreeInfo(0, 0)

    leftTreeData = getTreeInfo(tree.left)
    rightTreeData = getTreeInfo(tree.right)

    longestPathThroughRoot = leftTreeData.height+rightTreeData.height
    maxDiameterSoFar = max(leftTreeData.diameter, rightTreeData.diameter)
    currentDiameter = max(maxDiameterSoFar, longestPathThroughRoot)
    currentHeight = 1 + max(leftTreeData.height, rightTreeData.height)

    return TreeInfo(currentDiameter, currentHeight)


class TreeInfo():
    def __init__(self, diameter, height):
        self.diameter = diameter
        self.height = height


tree1 = BinaryTree(2)

tree2 = BinaryTree(3)
tree3 = BinaryTree(4)
tree1.left = tree2
tree1.right = tree3

# Another way to link the Binary Tree:
# tree1 = BinaryTree(2, tree2, tree3)

print(binaryTreeDiameter(tree1))
