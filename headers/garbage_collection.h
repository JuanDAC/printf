#ifndef GARBAGE_COLLETION
#define GARBAGE_COLLETION
/* Garbage Collection*/
/* Garbage Collector*/
/**
 * struct _garbage - struct
 * @subscriptions: subscriptor
 * @malloc: malloc
 * @free_all: free
 * @malloc_acumulator: acumulator
 */
typedef struct _garbage
{
	void **subscriptions;

	int long malloc_acumulator;

	void *(*malloc)(void *garbage_collector_t, size_t size);
	void *(*free_all)(void *garbage_collector_t);
} garbage_collector_t;

garbage_collector_t create_garbage_collector(void);

#endif /* GARBAGE_COLLETION */
