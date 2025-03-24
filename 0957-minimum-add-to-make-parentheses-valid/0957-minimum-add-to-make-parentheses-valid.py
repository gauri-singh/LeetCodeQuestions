class Solution(object):
    def minAddToMakeValid(self, s):
        """
        :type s: str
        :rtype: int
        """
        stack = []

        for char in s:
            if char == '(':
                stack.append(char)
            elif char == ')':
                if stack and stack[-1] == '(':
                    stack.pop()  # matched
                else:
                    stack.append(char)  # unmatched ')'

        return len(stack)