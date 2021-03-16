#include "holberton.h"



void *_malloc(garbage_collector_t *GC, size_t size)
{
	GC->subscriptions[GC->malloc_acumulator] = malloc(size);
	if (GC->subscriptions[GC->malloc_acumulator] == NULL)
		return (NULL);
	return GC->subscriptions[GC->malloc_acumulator];
}

void *_malloc(garbage_collector_t *GC, size_t size)
{
	GC->subscriptions[GC->malloc_acumulator] = malloc(size);
	if (GC->subscriptions[GC->malloc_acumulator] == NULL)
		return (NULL);
	return GC->subscriptions[GC->malloc_acumulator];
}

garbage_collector_t create_garbage_collector(garbage_collector_t *GC)
{
	GC->subscriptions = _malloc(RAW_SIZE, sizeof(void *));
	if (GC->subscriptions == NULL)
		return (NULL);
	GC->malloc = _malloc;
	GC->free_all = _free_all;
	GC->malloc_acumulator = 0;
}

