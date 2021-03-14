#ifndef TOKEN_H
#define TOKEN_H
/**
* enum _token_type - tiping handlers
* @null: \0
* @normal_string: no es un flag
* @integer: d
* @character: c
* @string: s
* @generic_integer: i
* @ocatal_integer: o
* @hexadecimal_integer: x
* @unsigned_integer: u
* @short_integer: h
* @float_point: f
* @scientifi_notation: e
* @shortest_among: g
* @character: c
* @string: s
* @long_doble_float: lf
* @long_integer: ld
*
* Description: Longer description
*/
typedef enum _token_type
{

	null,

	/* types */
	format_specification,

	/* mandatory */
	normal_string,
	character,
	string,
	integer,
	generic_integer,

	/* advanced */

	ocatal_integer,
	hexadecimal_integer,
	unsigned_integer,
	short_integer,
	float_point,
	scientifi_notation,
	shortest_among,
	long_doble_float,
	long_integer,
} token_type;

typedef enum _handler_function
{
	equal_handler,
	simple_handler,
	complex_handler,
} handler_function_t;

/**
* struct _token - object token
* @type: type of handler
* @literal: character literal
*
* Description: Longer description
*/
typedef struct _token
{
	token_type type;
	char *literal;
	handler_function_t type_handler;
} token_t;


#endif /* TOKEN_H */
