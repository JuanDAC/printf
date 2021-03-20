#ifndef TOKEN_H
#define TOKEN_H
/**
* enum _token_type - tiping handlers
* @null: \0
* @normal_string: no es un flag
* @binary_integer: b
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
* @without_adding: sin añadir token
* @formated: %
* @format_specification: %
* @normal_percentage: %
* @remove_string: ""
* @percentage_escape: %
* Description: Longer description
*/
typedef enum _token_type
{

	null,
	/* formating */
	without_adding,
	formated,
	format_specification,
	normal_percentage,
	normal_string,
	remove_string,
	/* mandatory */
	character,
	string,
	integer,
	generic_integer,
	percentage_escape,
	unsigned_integer,
	/* advanced */
	binary_integer,
	ocatal_integer,
	hexadecimal_integer,
	short_integer,
	float_point,
	scientifi_notation,
	shortest_among,
	long_doble_float,
	long_integer
} token_type;
/**
 * enum _handler_function - manejador de parametros de funciones
 * @equal_handler: sin funcion
 * @simple_handler: sin argumento
 * @complex_handler: con un argumento de formato
 */
typedef enum _handler_function
{
	equal_handler,
	simple_handler,
	complex_handler
} handler_function_t;

/**
* struct _token - object token
* @literal: character literal
* @type_handler: manjador de tipo
* @type: tipo del token
* Description: Longer description
*/
typedef struct _token
{
	token_type type;
	char *literal;
	handler_function_t type_handler;
} token_t;
/**
 * struct _link_token - vincula el tipo con el literal
 * @literal: string
 * @type: type string
 */
typedef struct _link_token
{
	char literal;
	token_type type;
} link_token_t;


#endif /* TOKEN_H */
