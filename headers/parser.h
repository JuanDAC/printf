#ifndef PARSE_H
#define PARSE_H

token_t **parser(
	garbage_collector_t *GC,
	token_t **raw_tokens
);

#endif /* PARSE_H */
