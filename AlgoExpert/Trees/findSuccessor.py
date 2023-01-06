

class BinaryTreeDiameter:
    def __init__(self, value, right, left, parent):
        self.value = value
        self.left = left
        self.right = right
        self.parent = parent


# Iterative Solution: O(n) time | O(n) space:
def findSuccessorIterative(tree, node):
    inOrder = getInOrderTraversal(tree)
    for idx, currNode in enumerate(inOrder):
        if currNode != node:
            continue

        if idx == len(inOrder)-1:
            return None

        return inOrder[idx+1]

# ------------------------------- # --------------------------------- # ---------------------

# recursive approach --> O(n) time | O(h) space


def getInOrderTraversal(node, order=[]):
    if node == None:
        return order

    getInOrderTraversal(node.left, order)
    order.append(node)
    getInOrderTraversal(node.right, order)

    return order


def findSuccessorRec(tree, node):

    # case 1: if the node has a right child
    if node.right is not None:
        return getLeftmostChild(node.right)

    # case 2: not having right child
    return getRightmostParent()


def getLeftmostChild(node):
    currentNode = node
    while currentNode.left is not None:
        currentNode = currentNode.left
    return currentNode


def getRightmostParent(node):
    currentNode = node
    while currentNode.parent is not None and currentNode.parent.right == currentNode:
        currentNode = currentNode.parent
    return currentNode.parent
