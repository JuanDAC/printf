#include "holberton.h"
/**
 * set_normal_token - define un token de tipo normal
 * @GC: parse tpken
 * @PT: parse tpken
 * @PI: parse index
 * @RT: row token
 * @RI: row index
 * Return: always void
 */
void set_normal_token(garbage_collector_t *GC,
	token_t **PT, int *PI, token_t **RT, int RI)
{
	PT[*PI] = RT[RI];
	PT[*PI]->literal = str_copy(GC,
	RT[RI]->literal, 1);
	PT[*PI]->type = normal_string;
	(*PI) += 1;
}



/**
 * selector_type -  function selector type
 * @token: token
 * @current_character: current character
 * Return: void
 */
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
/**
 * parser - function parser
 * @GC: variable
 * @raw_tokens: raw tokens
 * Return: parse_tokens
 **/
token_t **parser(garbage_collector_t *GC, token_t **raw_tokens)
{
	int raw_index, parser_index, shifting;
	bool continue_f = true;
	char last_type_specifiers[] = "cdefgiosuxh%";
	char middle_type_specifiers[] = " -+l.0123456789";
	token_t **parse_tokens;

	parse_tokens = (token_t **)GC->malloc(GC, BUFFER_SIZE * sizeof(token_t));

	if (parse_tokens == NULL)
		return (NULL);
	for (raw_index = 0, parser_index = 0; raw_tokens[raw_index]; raw_index++)
		if (raw_tokens[raw_index]->type == formated)
		{
			for (shifting = 1, continue_f = true; continue_f; shifting++)
				if (includes(last_type_specifiers,
					*raw_tokens[raw_index + shifting]->literal))
				{
					parse_tokens[parser_index] = GC->malloc(GC,
						sizeof(token_t));
					parse_tokens[parser_index]->literal = str_copy(GC,
						raw_tokens[raw_index]->literal, shifting);
					parse_tokens[parser_index]->type = without_adding;
					parse_tokens[parser_index]->type_handler = (shifting = 1)
						? simple_handler : complex_handler;
					selector_type(parse_tokens[parser_index],
						*raw_tokens[raw_index + shifting]->literal);
					raw_index += shifting, parser_index++, continue_f = false;
				}
				else if (!includes(middle_type_specifiers,
					*raw_tokens[raw_index + shifting]->literal))
				{
					set_normal_token(GC, parse_tokens, &parser_index, raw_tokens, raw_index);
					break;
				}
		}
		else
			set_normal_token(GC, parse_tokens, &parser_index, raw_tokens, raw_index);
	parse_tokens[parser_index] = NULL;
	return (parse_tokens);
}
