# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def findTarget(self, root: TreeNode, k: int) -> bool:
        needed = set()
        return self.recursiveFind(root, k, needed)
        
    
    def recursiveFind(self, root, k, needed):
        if root is None:
            return False
        elif root.val in needed:
            return True
        
        needed.add(k - root.val)
        return self.recursiveFind(root.left, k, needed) or self.recursiveFind(root.right, k, needed)