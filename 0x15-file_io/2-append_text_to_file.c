#include "main.h"

/**
 * append_text_to_file - appends text at the end of a File.
 * @filename: A Pointer to the name of the File.
 * @text_content: The String to add to the end of the File.
 *
 * Return: If the function fails or filename is NULL - -1.
 *         If the file does not exist the user lacks write permissions - -1.
 *         Otherwise - 1.
 */
int append_text_to_file(const char *filename, char *text_content)
{
int o, wr, len = 0;

if (filename == NULL)
return (-1);

if (text_content != NULL)
{
for (len = 0; text_content[len];)
len++;
}

o = open(filename, O_WRONLY | O_APPEND);
wr = write(o, text_content, len);

if (o == -1 || wr == -1)
return (-1);

close(o);

return (1);
}
