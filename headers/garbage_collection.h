#ifndef GARBAGE_COLLETION
#define GARBAGE_COLLETION
/* Garbage Collection*/
/* Garbage Collector*/
typedef struct _garbage
{
	void **subscriptions;
	int malloc_acumulator;
	void *(*malloc)(void *garbage_collector_t, size_t size);
	void *(*free_all)(void *garbage_collector_t);
} garbage_collector_t;

ge_collector_t create_garbage_collector(garbage_collector_t *GC);

#endif /* GARBAGE_COLLETION */
