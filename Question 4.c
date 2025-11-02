#include <stdio.h>

#define MAX 100  

// Function prototypes
void push(int stack[], int *top);
void pop(int stack[], int *top);
void peek(int stack[], int top);
void display(int stack[], int top);

int main() {
    int stack[MAX];
    int top = -1; 
    int choice;

    do {
        printf("\n===== STACK MENU =====\n");
        printf("1. PUSH\n2. POP\n3. PEEK\n4. DISPLAY\n5. EXIT\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                push(stack, &top);
                break;
            case 2:
                pop(stack, &top);
                break;
            case 3:
                peek(stack, top);
                break;
            case 4:
                display(stack, top);
                break;
            case 5:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice! Try again.\n");
        }
    } while(choice != 5);

    return 0;
}


void push(int stack[], int *top) {
    if(*top >= MAX - 1) {
        printf("STACK OVERFLOW! Cannot push more elements.\n");
    } else {
        int value;
        printf("Enter element to push: ");
        scanf("%d", &value);
        (*top)++;
        stack[*top] = value;
        printf("%d pushed to stack.\n", value);
    }
}

void pop(int stack[], int *top) {
    if(*top < 0) {
        printf("STACK UNDERFLOW! Nothing to pop.\n");
    } else {
        printf("Popped element: %d\n", stack[*top]);
        (*top)--;
    }
}

void peek(int stack[], int top) {
    if(top < 0) {
        printf("STACK EMPTY! Nothing on top.\n");
    } else {
        printf("Top element: %d\n", stack[top]);
    }
}


void display(int stack[], int top) {
    if(top < 0) {
        printf("STACK EMPTY! Nothing to display.\n");
    } else {
        printf("Stack elements (top to bottom):\n");
        for(int i = top; i >= 0; i--) {
            printf("%d\n", stack[i]);
        }
    }
}


