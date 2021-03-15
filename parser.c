#include "holberton.h"
void selector_type(token_t *token, char current_character)
{
	int i;
	link_token_t selector_token[] = {
		{'c', character},
		{'s', string},
		{'d', integer},
		{'i', generic_integer},
		{'%', percentage_escape},
		{'\0', null}
	};

	for (i = 0; selector_token[i].literal ; i++)
	{
		if (current_character == selector_token[i].literal)
		{
			token->type = selector_token[i].type;
			break;
		}
	}
}

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
	if (parse_tokens == NULL)
		return (NULL);
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
					parse_tokens[parser_index]->literal = str_copy(raw_tokens[raw_index]->literal, shifting);
					parse_tokens[parser_index]->type = without_adding;
					parse_tokens[parser_index]->type_handler = (shifting = 1) ? simple_handler : complex_handler;
					selector_type(parse_tokens[parser_index], *raw_tokens[raw_index + shifting]->literal);
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
			parse_tokens[parser_index]->literal = str_copy(raw_tokens[raw_index]->literal, 0);
			parse_tokens[parser_index]->type = normal_string;
			parser_index += 1;
		}
	parse_tokens[parser_index] = NULL;
	return (parse_tokens);
}


