# structuring with prototypes, data types and modules*percentage_escape_handler

|constans      |
|--------------|
|RAW_SIZE      |
|              |

|evaluator            |
|---------------------|
| struct _handler_link|
| *evaluator          |
| handler_selector    |
|                     |

|format handlers            |
|---------------------------|
| integer_handler           |
| *character_handler        |
| *string_handler           |
| *percentage_escape_handler|
|                           |

| _printf               |
|-----------------------|
|NULL_OR_ONLY_PERCENTAGE|
| _printf               |
|                       |

| garbage_collection|
|--------------------------|
| struct _garbage          |
| garbage_collector_t      |
| *create_garbage_collector|
|                          |

| lexer                  |
|------------------------|
| **lexer                |
|garbage_collector_t     |
|                        |

| parser               |
|----------------------|
| **parser             |
| garbage_collector_t  |
|                      |

| token                                    |
|------------------------------------------|
| enum _token_type                         |
| enum _handler_function                   |
| struct _token                            |
| struct _link_token                       |
|                                          |

| tools                                               |
|-----------------------------------------------------|
| print_rev                                           |
| *_strcat                                            |
| *rot13                                              |
| *str_concat                                         |
| get_scale                                           |
| _abs                                                |
| _isalpha                                            |
| *_calloc                                            |
| _pow                                                |
| lenht                                               |
| paserInt                                            |
| is_number                                           |
| _strspn                                             |
| _strlen_recursion                                   |
| length_str                                          |
| includes                                            |
| *string_nconcat                                     |
| *str_copy                                           |
| *_strdup                                            |
| string_number_alt                                   |
|                                                     |

| types                                          |
|------------------------------------------------|
| enum _boolean                                  |
|                                                |
