#include <malloc.h>
#include "stack.h"

struct stack_node {
    // TODO (task 1): what fields do we need here?
    char value;
    struct stack_node *next;
};

struct stack {
    // Null if the stack is empty.
    struct stack_node *head;
};

stack_ptr stack_new() {
    stack_ptr s = malloc(sizeof(struct stack));
    s->head = NULL;
    return s;
}

void stack_free(stack_ptr s) {
    // TODO (task 1): how do we make sure the nodes don't leak memory?
    if(s != NULL) {
        free(s);
    }
}

void stack_push(stack_ptr s, char c) {
    // TODO (task 1): how do we push an entry onto the stack?
    struct stack_node *newNode = malloc(sizeof(struct stack_node));
    newNode->value = c;
    newNode->next = s->head;
    s->head =newNode;
}

bool stack_pop(stack_ptr s, char *out) {
    // TODO (task 1): how do we pop an entry from the stack?
    if(s->head == NULL) {
        return false;
    }
    struct stack_node *pop = s->head;
    *out = pop->value;
    s->head = pop->next;
    free(pop);
    return true;
}
