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

	void *(*malloc)(garbage_collector_t *GC, size_t size);
	void (*free_all)(garbage_collector_t *GC);
} garbage_collector_t;

garbage_collector_t *create_garbage_collector(void);

#endif /* GARBAGE_COLLETION */
