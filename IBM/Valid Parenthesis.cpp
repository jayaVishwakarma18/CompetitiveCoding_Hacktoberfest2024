# Problem: Valid Parentheses

## Problem Description
Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.
An input string is valid if:
Open brackets must be closed by the same type of brackets.
Open brackets must be closed in the correct order.
Every close bracket has a corresponding open bracket of the same type.


Example 1:
Input: s = "()"
Output: true

Example 2:
Input: s = "()[]{}"
Output: true

Example 3:
Input: s = "(]"
Output: false

Example 4:
Input: s = "([])"
Output: true


 Constraints
- 	1 <= s.length <= 104
-	s consists of parentheses only '()[]{}'.

SOLUTION

Language- C++
Time Complexity: O(n)
Space Complexity: O(n)

class Solution{
public:
    bool isValid(std::string s){
        std::stack<char> stack;
        std::unordered_map<char, char> map = {{')', '('}, {'}', '{'}, {']', '['}};

        for (char c : s){
            if (map.count(c)==0){
                stack.push(c);  //Opening bracket 
            }else{
                 //Closing bracket 
                 if (stack.empty() || stack.top() != map[c]){
                    //if number of braces are unequal
                    return false;
                 }
                //if it's a match or valid pair of parentheses 
                stack.pop(c);
            }
        }
        //if all the braces got paired return true
        return stack.empty();
    }
};
