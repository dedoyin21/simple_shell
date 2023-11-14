#include "shell.h"

/**
 * _myhistory -function displays the history list, preceded
 *              with line numbers, starting at 0.
 * @info: Structure containing potential arguments. Used to maintain
 *        constant function prototype.
 *  Return: Always 0
 */

int _myhistory(info_t *info)
{
	print_list(info->history);
	return (0);
}

/**
 * unset_alia -function  sets alia to string
 * @info: parameter struct
 * @str: the string argument alia
 *
 * Return: Always 0 on success, 1 on error
 */

int unset_alia(info_t *info, char *str)
{
	char *p, c;
	int ret;

	p = _strchr(str, '=');
	if (!p)
		return (1);
	c = *p;
	*p = 0;
	ret = delete_node_at_index(&(info->alia),
		get_node_index(info->alia, node_starts_with(info->alia, str, -1)));
	*p = c;
	return (ret);
}

/**
 * set_alia -function sets alias to string
 * @info: parameter struct
 * @str: the string alias
 * Return: Always 0 on success, 1 on error
 */

int set_alia(info_t *info, char *str)
{
	char *p;

	p = _strchr(str, '=');
	if (!p)
		return (1);
	if (!*++p)
		return (unset_alia(info, str));

	unset_alia(info, str);
	return (add_node_end(&(info->alia), str, 0) == NULL);
}

/**
 * print_alia -function prints an alia string
 * @node: the alia node
 * Return: Always 0
 */

int print_alia(list_t *node)
{
	char *p = NULL, *a = NULL;

	if (node)
	{
		p = _strchr(node->str, '=');
		for (a = node->str; a <= p; a++)
			_putchar(*a);
		_putchar('\'');
		_puts(p + 1);
		_puts("'\n");
		return (0);
	}
	return (1);
}

/**
 * _myalia -function mimics the alia bultin (man alia)
 * @info: Structure containing potential arguments. Used to maintain
 *          constant function prototype.
 *  Return: Always 0
 */

int _myalia(info_t *info)
{
	int i = 0;
	char *p = NULL;
	list_t *node = NULL;

	if (info->argc == 1)
	{
		node = info->alia;
		while (node)
		{
			print_alia(node);
			node = node->next;
		}
		return (0);
	}
	for (i = 1; info->argv[i]; i++)
	{
		p = _strchr(info->argv[i], '=');
		if (p)
			set_alia(info, info->argv[i]);
		else
			print_alia(node_starts_with(info->alia, info->argv[i], '='));
	}

	return (0);
}
