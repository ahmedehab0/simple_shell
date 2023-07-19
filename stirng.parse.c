#include "main.h"

/**
 *string_parse - function to tokenize the string
 *@str: string to be tokenized
 *return - array of strings
 */
char **string_parse(char *str)
{
	char **token, *delim = " ";
	int i = 0, buf_size = 1024;

	token = malloc(sizeof(char *) * buf_size);
	if (!token)
	{
		free(token);
		return (NULL);
	}

	token[i] = strtok(str, delim);
	i++;

	while(token[i])
	{
		token[i] = strtok(NULL, delim);
		if (i >= buf_size)
		{
			buf_size += buf_size;
			token = _realloc(token, sizeof (char *) * buf_size);
			if (!token)
			{
				perror("Error");
			}
		}
		i++;
	}
return (token);
}
/**
 *_realloc - function to dynamically reallocate the memory
 *@new_size: new_size to be reallocated
 *return: pointer to the new memory
 */
void *_realloc(void *ptr, int new_size)
{
	char *new;
	int i;

	if (!ptr)
	{
		ptr = malloc(new_size);
		if (!ptr)
			return (NULL);
		return (ptr);
	}

	if (new_size == 0)
	{
		free(ptr);
		return (NULL);
	}

	new = malloc(new_size);
	if (!new)
		return(NULL);

	for (i = 0; new[i]; i++)
		new[i] = ((char *)ptr)[i];

	free (ptr);
	return (new);
}

/**
 * split_str - split string into array of name and value
 * @str: a pointer to string
 *
 * Return: an array of two elements, name and value of environment
 */
char **split_str(char *str)
{
	/* may be similar to string parse - so we can modify later. */
	char *delim = "=";
	char **split = NULL;
	char *buff = NULL;

	buff = strtok(str, delim);
	split[0] = strdup(buff);
	buff = strtok(NULL, delim);
	split[1] = strdup(buff);

	return (split);
}

/**
 * _strlen - get length of string
 * @s: A pointer to char
 *
 * computes the length of the string s up to,
 * but not including the terminating null character.
 *
 * Return: length of string
 */
int _strlen(const char *s)
{
	int len;

	for (len = 0; s[len]; len++)
		;

	return (len);
}