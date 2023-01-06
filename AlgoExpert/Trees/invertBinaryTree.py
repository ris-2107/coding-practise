def swapLeftAndRight(tree):
    tree.left, tree.right = tree.right, tree.left


def invertBinaryTree(tree):
    # we are creating queue of the tree nodes
    queue = [tree]
    while len(queue > 0):
        # we pop out the first element form the queue:
        curr = queue.pop(0)

    # if the current element is Null then we just continue to pop the other elements present the list
        if(curr is None):
            continue

        # if the current node was not NULL then we just swap the elements from right to left
        swapLeftAndRight(curr)
        queue.append(curr.left)
        queue.append(curr.right)

