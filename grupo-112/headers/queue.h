typedef struct queue{
  int front;
  int rear;
  int size;
  char *values;
} *Queue;


Queue init(int);
int isEmpty(Queue);
int isFull(Queue);
int enqueue(Queue,char* value);
int dequeue(Queue);
int inFront(Queue);

