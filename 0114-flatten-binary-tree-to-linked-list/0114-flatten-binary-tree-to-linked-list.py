# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def flatten(self, root: Optional[TreeNode]) -> None:
        """
        Do not return anything, modify root in-place instead.
        """
        self.q= []
        def preorder(node:Optional[TreeNode]):
            if not node:
                return
            self.q.append(node)
            preorder(node.left)
            preorder(node.right)
        
        preorder(root)
        if self.q:
            self.q.pop(0)
        while self.q:
            root.right = self.q.pop(0)
            root.left = None
            root = root.right

        