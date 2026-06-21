#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "queue.h"

int main(int argc, char* argv[])
{
    struct queue q;
    struct node* deletedNode;
    int numberOfUsers;
    int result;

    if (argc != 2)
    {
        printf_s("Usage: %s <number_of_users>\n", argv[0]);
        printf_s("Example: %s 5\n", argv[0]);
        return 1;
    }

    numberOfUsers = atoi(argv[1]);

    if (numberOfUsers < 0)
    {
        printf_s("Error: Number of users cannot be negative.\n");
        return 1;
    }

    if (numberOfUsers > 999999)
    {
        printf_s("Error: Maximum number of users allowed is 999999.\n");
        return 1;
    }

    srand((unsigned int)time(NULL));

    initQueue(&q);

    result = enqueueRandomUsers(&q, numberOfUsers);

    if (result != 0)
    {
        printf_s("Error occurred while adding users to the queue.\n");
        return 1;
    }

    printf_s("\nDequeuing users from the queue:\n\n");

    while (!isQueueEmpty(&q))
    {
        deletedNode = dequeue(&q);

        if (deletedNode != NULL)
        {
            printUser(deletedNode->data);
            free(deletedNode);
        }
    }

    printf_s("Queue is now empty.\n");

    return 0;
}