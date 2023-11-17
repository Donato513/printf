#include "main.h" 
#include <stdarg.h>
#include <unistd.h>

/**
 * _printf - Custom print formatted output
 * @format: Format string
 *
 * Return: Number of characters printed
 */
int _printf(const char *format, ...)
{
    va_list args;
    int printed_chars = 0;

    va_start(args, format);

    while (*format != '\0')
    {
        if (*format == '%')
        {
            format++;
            switch (*format)
            {
                case 'c':
                {
                    char c = va_arg(args, int);
                    write(1, &c, 1);
                    printed_chars++;
                    break;
                }
                case 's':
                {
                    char *str = va_arg(args, char *);
                    while (*str != '\0')
                    {
                        write(1, str, 1);
                        str++;
                        printed_chars++;
                    }
                    break;
                }
                case '%':
                    write(1, "%", 1);
                    printed_chars++;
                    break;
                default:
                    break;
            }
        }
        else
        {
            write(1, format, 1);
            printed_chars++;
        }
        format++;
    }

    va_end(args);

    return (printed_chars);
}

