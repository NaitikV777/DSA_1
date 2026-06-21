#ifndef QUEUE_H
#define QUEUE_H

#define USERNAME_LENGTH 10
#define USERNAME_SIZE 11
#define FACTION_SIZE 10

// Structure to represent one game user
struct user
{
    char username[USERNAME_SIZE];
    int level;
    char faction[FACTION_SIZE];
};

// Structure to represent one queue node
struct node
{
    struct user data;
    struct node* link;
};

// Structure to represent the queue
struct queue
{
    struct node* head;
    struct node* tail;
};

// Function declarations
void initQueue(struct queue* q);
int isQueueEmpty(struct queue* q);
int enqueue(struct queue* q, struct node* newNode);
struct node* dequeue(struct queue* q);
int enqueueRandomUsers(struct queue* q, int numberOfUsers);

void generateUsername(char username[], int usernameSize, int number);
void generateFaction(char faction[], int factionSize);
void printUser(struct user u);

#endif