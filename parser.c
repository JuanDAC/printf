#include "holberton.h"



token_t **parser(
	const garbage_collector_t *GC,
	token_t **raw_tokens
)
{
	int raw_index, parser_index, shifting;
	bool continue_format = true;
	char last_type_specifiers[] = "cdefgiosuxh%";
	char middle_type_specifiers[] = " -+l.0123456789";
	token_t **parse_tokens;
	parse_tokens = malloc(1024 * sizeof(token_t));

	(void)GC;

	for (raw_index = 0, parser_index = 0; raw_tokens[raw_index]; raw_index++)
		if (raw_tokens[raw_index]->type == formated)
		{
			continue_format = true;
			for (shifting = 1; continue_format; shifting++)
			{
				if (includes(last_type_specifiers, *raw_tokens[raw_index + shifting]->literal))
				{
					parse_tokens[parser_index] = malloc(sizeof(token_t));
					parse_tokens[parser_index]->literal = str_copy(raw_tokens[raw_index]->literal, shifting + 1);
					parse_tokens[parser_index]->type = without_adding;
					parse_tokens[parser_index]->type_handler = (shifting = 1) ? simple_handler : complex_handler;
					raw_index += shifting;
					parser_index += 1;
					continue_format = false;
				}
				else if (!includes(middle_type_specifiers, *raw_tokens[raw_index + shifting]->literal))
				{
					break;
				}
			}
		}
		else
		{
			parse_tokens[parser_index] = raw_tokens[raw_index];
			parser_index += 1;
		}
	return (parse_tokens);
}


