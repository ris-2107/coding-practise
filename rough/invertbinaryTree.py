# O(n) time | O(n) space:

def invertBinary(tree):
    queue = [tree]
    while len(queue):
        current = queue.pop(0)
        if current is None:
            continue

        swapLeftAndRight(current)
        queue.append(current.left)
        queue.append(current.right)


def swapLeftAndRight(tree):
    tree.left, tree.right = tree.right, tree.left


# Recursive Solution:

def invertBinaryTreeRec(tree):
    if tree is None:
        return
    swapLeftAndRight(tree)
    invertBinaryTreeRec(tree.left)
    invertBinaryTreeRec(tree.right)
