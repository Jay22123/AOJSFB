#ifdef _DEBUG
#	define debug(function) function
#else
#	define debug(function)
#endif

#include <stdio.h>
#include <stdlib.h>


/* 佇列相關程式 開始 */
typedef struct _QueueNode
{
	int data;
	struct _QueueNode *next;
}QueueNode;

typedef struct _Queue
{
	QueueNode *front;
	QueueNode *rear;
	unsigned int count;
}Queue;

void newQueue(Queue **newQueue)
{
	if (*newQueue == NULL)
	{
		(*newQueue) = (Queue *)malloc(sizeof(Queue));
		(*newQueue)->front = (*newQueue)->rear = NULL;
		(*newQueue)->count = 0;
	}
}

void deleteQueue(Queue **newQueue)
{
	if (*newQueue != NULL)
	{
		(*newQueue)->front = (*newQueue)->rear = NULL;
		(*newQueue)->count = 0;

		free(*newQueue);
	}
}

void push(Queue *Queue, int data)
{
	QueueNode *pushQueueNode = (QueueNode *)malloc(sizeof(QueueNode));
	pushQueueNode->data = data;
	pushQueueNode->next = NULL;

	if (Queue->rear == NULL)
	{
		Queue->front = Queue->rear = pushQueueNode;

		Queue->count = 1;
	}
	else
	{
		Queue->rear->next = pushQueueNode;
		Queue->rear = pushQueueNode;

		++(Queue->count);
	}
}

void pushNode(Queue *Queue, QueueNode *pushQueueNode)
{
	if (Queue->count <= 0)
	{
		Queue->front = Queue->rear = pushQueueNode;
		Queue->count = 1;
	}
	else
	{
		Queue->rear->next = pushQueueNode;
		Queue->rear = pushQueueNode;

		++(Queue->count);
	}
}

int pop(Queue *Queue)
{
	if (Queue->front == NULL)
		return NULL;

	QueueNode *popQueueNode = Queue->front;
	Queue->front = Queue->front->next;

	int result = popQueueNode->data;
	popQueueNode->next = NULL;
	free(popQueueNode);

	--(Queue->count);

	return result;
}

QueueNode *popNode(Queue *Queue)
{
	QueueNode *popQueueNode = Queue->front;

	if (popQueueNode != NULL)
	{
		Queue->front = popQueueNode->next;

		popQueueNode->next = NULL;
		--(Queue->count);
	}

	return popQueueNode;
}

void printQueue(Queue *Queue)
{
	if (Queue->front != NULL)
	{
		QueueNode *current = Queue->front;

		while (current != NULL)
		{
			printf("%d ", current->data);
			current = current->next;
		}
	}
}
/* 佇列相關程式 結束 */


int main(int argc, char *argv[])
{
	int n = 0, k, k1 = 0, k2 = 0;

	while (scanf("%d", &n) != EOF)
	{
		debug(printf("[DEBUG] n=%d\n", n));

		Queue *head_k1 = NULL, *head_k2 = NULL;
		newQueue(&head_k1);
		newQueue(&head_k2);

		scanf("%d", &k1);
		debug(printf("[DEBUG] k1=%d\n", k1));
		for (k = 1; k <= k1; k++)
		{
			int num;
			scanf("%d", &num);
			push(head_k1, num);
		}
		debug(
			printf("[DEBUG] "); printQueue(head_k1); printf("\n");
		);

		scanf("%d", &k2);
		debug(printf("[DEBUG] k2=%d\n", k2));
		for (k = 1; k <= k2; k++)
		{
			int num;
			scanf("%d", &num);
			push(head_k2, num);
		}
		debug(
			printf("[DEBUG] "); printQueue(head_k2); printf("\n");
		);

		int times = 0;
		while (
			(head_k1->count > 0) &&
			(head_k2->count > 0))
		{
			QueueNode *k1q = popNode(head_k1),
				*k2q = popNode(head_k2);

			if (k1q->data > k2q->data)
			{
				pushNode(head_k1, k2q);
				pushNode(head_k1, k1q);
			}
			else
			{
				pushNode(head_k2, k1q);
				pushNode(head_k2, k2q);
			}
			times++;
		}

		printf("%d %d\n",
			times, ((head_k1->count > 0) ? 1: 2)
		);

		deleteQueue(&head_k1);
		deleteQueue(&head_k2);
	}

	return 0;
}
