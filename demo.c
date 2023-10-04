#include "demo.h"
#include "stack.h"
#include <stdbool.h>

bool check_brackets(const char *str) {
    stack_ptr s = stack_new();
    
    int stack_size = 0;
    while (*str != '\0') { //While loop to
        char current = *str;

        if (current == '(' || current == '[' || current == '{') {
            stack_push(s, current);
            stack_size++;  // Increment the stack size
        } else if (current == ')' || current == ']' || current == '}') {
            char popped;
            if (!stack_pop(s, &popped)) {
                // If the stack is empty or the popped bracket doesn't match, it's unbalanced
                stack_free(s);
                return false;
            }

            stack_size--;  // Decrement the stack size

            if ((current == ')' && popped != '(') ||
                (current == ']' && popped != '[') ||
                (current == '}' && popped != '{')) {
                // Mismatched brackets
                stack_free(s);
                return false;
            }
        }
        str++;
    }
    //Check if the stack is empty
    stack_free(s);
    return stack_size == 0;
}
