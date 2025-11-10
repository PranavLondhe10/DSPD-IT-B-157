#include <stdio.h>
#include <string.h>
#define MAX 50

int stack[MAX];
int top = -1;

void push(int x) {
    if(top == MAX - 1) {
        printf("Stack Overflow! Cannot push %d\n", x);
        return;
    }
    stack[++top] = x;
    printf("%d pushed onto stack.\n", x);
}

void pop() {
    if(top == -1) {
        printf("Stack Underflow! No elements to pop.\n");
        return;
    }
    printf("%d popped from stack.\n", stack[top--]);
}

void display() {
    if(top == -1) {
        printf("Stack is empty.\n");
        return;
    }
    printf("Current Stack:\n");
    for(int i = top; i >= 0; i--)
        printf("%d\n", stack[i]);
}

void checkPalindrome() {
    char str[50];
    int i, len, flag = 1;
    printf("Enter a string to check palindrome: ");
    scanf("%s", str);
    len = strlen(str);
    top = -1;
    for(i = 0; i < len; i++)
        push(str[i]);
    for(i = 0; i < len; i++) {
        if(str[i] != stack[top--]) {
            flag = 0;
            break;
        }
    }
    if(flag)
        printf("The string is a Palindrome.\n");
    else
        printf("The string is not a Palindrome.\n");
}

int main() {
    int choice, num;
    while(1) {
        printf("\n STACK MENU \n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Check Palindrome\n");
        printf("4. Display Stack\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                printf("Enter element to push: ");
                scanf("%d", &num);
                push(num);
                break;
            case 2:
                pop();
                break;
            case 3:
                checkPalindrome();
                break;
            case 4:
                display();
                break;
            case 5:
                return 0;
            default:
                printf("Invalid choice.\n");
        }
    }
}