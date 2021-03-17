# structuring with prototypes, data types and modules*, percentage escape handler

![strcct in c](https://media.geeksforgeeks.org/wp-content/cdn-uploads/Structure-In-C.png)

|CONSTANS      |  EVALUATOR      |
|--------------|-----------------|
|- RAW_SIZE      | - struct _handler_link
|              | - *evaluator
|              | - handler_selector
|FORMATS HANDLER| _PRINTF  |
| - integer_handler| - NULL_OR_ONLY_PERCENTAGE|
| - *character_handler| _printf  |
| - *string_handler| - NULL_OR_ONLY_PERCENTAGE|
| - *percentage_escape_handler| - _printf      |
| GARBAGE COLLECTOR|             LEXER               |
| - struct _garbage          | - **lexer             |
| - garbage_collector_t      | - garbage_collector_t |
| - *create_garbage_collector|                       |
| PARSER                 |  TOKEN                    |
| - **parser             |- enmun _token_type        |
| - garbage_collector_t  |- enum_handler_function    |
|                        |- struct _token|           |
| TOOLS                  |- struct _link_token
| - print_rev            |  TYPES
| - *_strcat             |- enum_boolean
| - *rot13               |
| - *str_concat          |
| - get_scale            |
| - _abs                 |
| - _isalpha             |
| - *_calloc             |
| - _pow                 |
| - lenht                |
| - paserInt             |
| - is_number            |
| - _strspn              |
| - _strlen_recursion    |
| - length_str           |
| - includes             |
| - *string_nconcat      |
| - *str_copy            |
| - *_strdup             |
| - string_number_alt    |
|                                                   |