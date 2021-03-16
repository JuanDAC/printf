#include "holberton.h"
/**
 * _malloc - guarda en memoria
 * @GC: garbage collector
 * @size: size
 * Return: puntero en una nueva posicion
 */
void *_malloc(garbage_collector_t *GC, size_t size)
{
	GC->subscriptions[GC->malloc_acumulator] = malloc(size);
	if (GC->subscriptions[GC->malloc_acumulator] == NULL)
		return (NULL);
	GC->malloc_acumulator++;
	return (GC->subscriptions[GC->malloc_acumulator - 1]);
}
/**
 * _free_all - libera
 * @GC: garbage collector
 * Return: always void
 */
void _free_all(garbage_collector_t *GC)
{
	while (GC->malloc_acumulator > 0)
	{
		GC->malloc_acumulator -= 1;
		free(GC->subscriptions[GC->malloc_acumulator]);
	}
}

/**
 * create_garbage_collector - create garbage collector
 * Return: GC
 */
garbage_collector_t *create_garbage_collector(void)
{
	garbage_collector_t *GC;

	GC = malloc(sizeof(garbage_collector_t));
	if (GC == NULL)
		return (NULL);

	GC->subscriptions = malloc(RAW_SIZE * sizeof(void *));
	if (GC->subscriptions == NULL)
	{
		free(GC);
		return (NULL);
	}

	GC->subscriptions[0] = GC;
	GC->subscriptions[1] = GC;
	GC->malloc = _malloc;
	GC->free_all = _free_all;
	GC->malloc_acumulator = 2;

	return (GC);
}
