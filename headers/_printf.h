#ifndef PRINTF_H
#define PRINTF_H

#define NULL_OR_ONLY_PERCENTAGE(F)
	((F) == NULL || ((*(F)) == '%' && length_str((char *)(F), false) == 1))

#define HANDLER_EXCEED_BUFFER(B, F)
	if (length_str((char *)(F), true) > BUFFER_SIZE)
		(B) = (char *)(F);
	else

int _printf(const char *format, ...);

#endif /* PRINTF_H */
