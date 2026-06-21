#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "queue.h"

void initQueue(struct queue* q)
{
    if (q == NULL)
    {
        return;
    }

    q->head = NULL;
    q->tail = NULL;
}

int isQueueEmpty(struct queue* q)
{
    if (q == NULL || q->head == NULL)
    {
        return 1;
    }

    return 0;
}

int enqueue(struct queue* q, struct node* newNode)
{
    if (q == NULL || newNode == NULL)
    {
        return 1;
    }

    newNode->link = NULL;

    if (q->head == NULL)
    {
        q->head = newNode;
        q->tail = newNode;
    }
    else
    {
        q->tail->link = newNode;
        q->tail = newNode;
    }

    return 0;
}

struct node* dequeue(struct queue* q)
{
    struct node* temp;

    if (q == NULL || q->head == NULL)
    {
        return NULL;
    }

    temp = q->head;
    q->head = q->head->link;

    if (q->head == NULL)
    {
        q->tail = NULL;
    }

    temp->link = NULL;

    return temp;
}

int enqueueRandomUsers(struct queue* q, int numberOfUsers)
{
    int i;
    struct node* newNode;

    if (q == NULL || numberOfUsers < 0 || numberOfUsers > 999999)
    {
        return 1;
    }

    for (i = 1; i <= numberOfUsers; i++)
    {
        newNode = (struct node*)malloc(sizeof(struct node));

        if (newNode == NULL)
        {
            return 1;
        }

        generateUsername(newNode->data.username, USERNAME_SIZE, i);

        newNode->data.level = (rand() % 60) + 1;

        generateFaction(newNode->data.faction, FACTION_SIZE);

        newNode->link = NULL;

        if (enqueue(q, newNode) != 0)
        {
            free(newNode);
            return 1;
        }
    }

    return 0;
}

void generateUsername(char username[], size_t usernameSize, int number)
{
    char letters[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
    int i;
    int randomIndex;
    int lettersLength;

    lettersLength = (int)strlen(letters);

    for (i = 0; i < 4; i++)
    {
        randomIndex = rand() % lettersLength;
        username[i] = letters[randomIndex];
    }

    sprintf_s(username + 4, usernameSize - 4, "%06d", number);

    username[USERNAME_LENGTH] = '\0';
}

void generateFaction(char faction[], size_t factionSize)
{
    int randomFaction;

    randomFaction = rand() % 3;

    if (randomFaction == 0)
    {
        strcpy_s(faction, factionSize, "red");
    }
    else if (randomFaction == 1)
    {
        strcpy_s(faction, factionSize, "blue");
    }
    else
    {
        strcpy_s(faction, factionSize, "green");
    }
}

void printUser(struct user u)
{
    printf_s("Username: %s\n", u.username);
    printf_s("Level: %d\n", u.level);
    printf_s("Faction: %s\n", u.faction);
    printf_s("-------------------------\n");
}