#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct stack {
    char data;
    struct stack* next;
};

typedef struct stack st;

st* top = NULL;

int execute(char[]);
int opd(char);
int opr(char);
int matchpair(char, char);
void push(char);
char pop();

int main() {
    char x[80];
    printf("ENTER string = ");
    gets(x);
    int ans = execute(x);

    if (ans == 1) {
        printf("The expression '%s' is valid.\n", x);
    } else {
        printf("The expression '%s' is not valid.\n", x);
    }
}

void push(char m) {
    st* p = (st*)malloc(sizeof(st));
    p->data = m;
    p->next = top;
    top = p;
}

char pop() {
    if (top == NULL) {
        printf("stack is underflow");
        return 0; // Return a default value (you can handle this differently)
    } else {
        char data = top->data;
        st* p = top;
        top = top->next;
        free(p);
        return data;
    }
}

int execute(char x[]) {
    int n;
    int i = 0;
    n = strlen(x);

    for (i = 0; i < n; i++) {
        if (opd(x[i])) {
            continue; // Ignore operands
        } else if (opr(x[i])) {
            push(x[i]); // Push operators onto the stack
        } else if (x[i] == '(' || x[i] == '[' || x[i] == '{') {
            push(x[i]); // Push opening brackets onto the stack
        } else if (x[i] == ')' || x[i] == ']' || x[i] == '}') {
            char popped = pop(); // Pop the top element from the stack
            if (!matchpair(popped, x[i])) {
                return 0; // Mismatched brackets
            }
        }
    }

    // Check if there are any unmatched opening brackets left
    if (top != NULL) {
        return 0;
    }

    return 1;
}

int opd(char m) {
    return (m >= 'a' && m <= 'z') || (m >= 'A' && m <= 'Z') || (m >= '0' && m <= '9');
}

int opr(char m) {
    return (m == '+' || m == '-' || m == '*' || m == '/');
}

int matchpair(char open, char close) {
    if (open == '(' && close == ')')
        return 1;
    if (open == '[' && close == ']')
        return 1;
    if (open == '{' && close == '}')
        return 1;
    return 0;
}
