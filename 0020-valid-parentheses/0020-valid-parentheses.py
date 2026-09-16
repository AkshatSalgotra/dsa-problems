class Solution:
    def isValid(self, s: str) -> bool:
        stack = []

        for ch in s:
            if ch == '(' or ch == '[' or ch == '{':
                stack.append(ch)
                continue
            else:
                if not stack:
                    return False
                else:
                    topEl = stack[-1]
                    if (ch == ')' and topEl != '(') or (ch == ']' and topEl != '[') or (ch == '}' and topEl != '{'):
                        return False
                    stack.pop()
        
        return not stack
    

        