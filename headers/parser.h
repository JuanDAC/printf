#ifndef PARSE_H
#define PARSE_H



token_t **parser(
	const garbage_collector_t *GC,
	token_t **raw_tokens
);

#define SET_NORMAL_TOKEN(PT, PI, RT, RI)                   \
	parse_tokens[parser_index] = raw_tokens[raw_index];\
	parse_tokens[parser_index]->literal = str_copy(    \
		raw_tokens[raw_index]->literal, 0);            \
	parse_tokens[parser_index]->type = normal_string;  \
	parser_index += 1;



#endif /* PARSE_H */
