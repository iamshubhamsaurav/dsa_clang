#include<stdio.h>
#include<ctype.h>

int top = -1;
int stack[20];

void push(int value) {
    top++;
    stack[top] = value;
}

int pop() {
    int val = stack[top];
    top--;
    return val;
}


int main() {
    char expr[20];
    printf("\nEnter the expression: ");
    scanf("%s", &expr);
    printf("\nThe expression is: %s", expr);
    int index = 0;
    while (expr[index] != '\0')
    {
        if(isalnum(expr[index])) {
            int el = (int)expr[index] - 48;
            push(el);
        } else {
            char ch = expr[index];
            int op2 = pop();
            int op1 = pop();

            switch(ch) {
                case '+': {
                    push(op1 + op2);
                    break ;
                }

                case '-': {
                    push(op1 - op2);
                    break ;
                }
                case '*': {
                    push(op1 * op2);
                    break ;
                }
                case '/': {
                    push(op1 / op2);
                    break ;
                }
            }
        }
        
        index++;
    }

    printf("\nThe result is : %d", pop());
    
    return 0;
}