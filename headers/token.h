#ifndef TOKEN_H
#define TOKEN_H
/**
* enum _token_type - tiping handlers
* @null: \0
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
	/* mandatory */
	null,
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

	character,
	string,

	long_doble_float,
	long_integer,
} token_type;

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
} token_t;

#endif /* TOKEN_H */
