#ifndef GARBAGE_COLLETION
#define GARBAGE_COLLETION

/* Garbage collection */
/* Garbage collector */
typedef struct _garbage
{
	void **subscriptions;
	int malloc_acumulator;
	void *(*malloc)(void *garbage_collector_t, size_t size);
	void *(*free_all)(void *garbage_collector_t);
	void *(*free)(void *garbage_collector_t, void *ptr_to_free);
} garbage_collector_t;


#endif /* GARBAGE_COLLETION */
