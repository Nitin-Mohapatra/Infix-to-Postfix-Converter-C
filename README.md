# Infix to Postfix Converter – C

## Description  
This C program converts an **infix expression** (e.g., `a+b*c`) into its **postfix form** (e.g., `abc*+`) using a **stack-based algorithm**. It handles operator precedence and parenthesis correctly to maintain the logical order of operations.

## Features  
- ✅ Converts infix expressions to postfix expressions  
- ✅ Handles operators: `+`, `-`, `*`, `/`, `%`  
- ✅ Manages parentheses and operator precedence  
- ✅ Uses custom stack implementation with `push` and `pop` functions  

## How It Works  
1. The program takes an infix expression as input from the user.  
2. It uses two stacks:  
   - One for operators  
   - One for the output postfix expression  
3. It loops through each character in the expression:  
   - If the character is an operand (a-z or A-Z), it's added directly to the postfix stack.  
   - If it's an operator, it checks precedence and pushes/pops accordingly.  
   - Parentheses are handled by pushing `'('` and popping until `'('` when `')'` is encountered.  
4. Finally, remaining operators are popped to the postfix stack.  
5. The postfix expression is printed.

## Example  

Enter the infix exp  
a+b*c  
Postfix: abc*+  
