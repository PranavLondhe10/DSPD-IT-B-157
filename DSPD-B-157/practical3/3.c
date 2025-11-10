#include <stdio.h>
#define MAX 50

char queue[MAX];
int front = -1 , rear = -1 ;

void insert(char ch)
{
    if(rear == MAX - 1)
    {
        printf("\nQueue Overflow!\n");
        return;
    }
    if(front == -1)
        front = 0;
    queue[++rear] = ch;
    printf("'%c' inserted into queue.\n", ch);
}

void dequeue()
{
    if(front == -1 || front > rear)
    {
        printf("\nQueue Underflow!\n");
        return;
    }
    printf("'%c' deleted from queue.\n", queue[front]);
    front++;

    if(front > rear)   
        front = rear = -1;
}

void display()
{
    if(front == -1 || front > rear)
    {
        printf("\nQueue is empty.\n");
        return;
    }
    printf("\nCurrent Queue: ");
    for(int i = front; i <= rear; i++)
        printf("%c ", queue[i]);
    printf("\n");
}

int main()
{
    int choice;
    char ch;

    while(1)
    {
        printf("\n--- QUEUE MENU ---\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                printf("Enter character to insert: ");
                scanf(" %c", &ch);
                insert(ch);
                break;

            case 2:
                dequeue();
                break;

            case 3:
                display();
                break;

            case 4:
                return 0;

            default:
                printf("Invalid choice.\n");
        }
    }
}
