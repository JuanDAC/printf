#include "holberton.h"


garbage_collector_t create_garbage_collector(garbage_collector_t *GC)
{
	GC->subscriptions = _calloc(RAW_SIZE, sizeof(void *));
	if (GC->subscriptions == NULL)
		return (NULL);
	GC->malloc = _malloc;
	GC->free_all = _free_all;
}

