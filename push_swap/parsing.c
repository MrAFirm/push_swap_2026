#include "push_swap.h"

static int	is_flag(char *arg)
{
	if (!ft_strncmp(arg, "--bench", 8) || !ft_strncmp(arg, "--adaptive", 11)
		|| !ft_strncmp(arg, "--simple", 9) || !ft_strncmp(arg, "--medium", 9)
		|| !ft_strncmp(arg, "--complex", 10))
		return (1);
	return (0);
}

static int	has_duplicate(t_list *a, int val)
{
	while (a)
	{
		if (a->content == val)
			return (1);
		a = a->next;
	}
	return (0);
}

static int	is_numeric(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '+' || str[i] == '-')
		i++;
	if (!str[i])
		return (0);
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

static int	parse_int(char *str, long *value)
{
	if (!is_numeric(str))
		return (0);
	*value = ft_atoi(str);
	if (*value > 2147483647 || *value < -2147483648)
		return (0);
	return (1);
}

int	parsing_create(int ac, char **av, t_list **a)
{
	int			i;
	long		value;
	t_list		*tmp;

	i = 1;
	*a = NULL;
	while (i < ac)
	{
		if (is_flag(av[i]))
			i++;
		else
		{
			if (!parse_int(av[i], &value) || has_duplicate(*a, (int)value))
				return (ft_lstclear(a, del), 0);
			tmp = ft_lstnew((int)value);
			if (!tmp)
				return (ft_lstclear(a, del), 0);
			ft_lstadd_back(a, tmp);
			i++;
		}
	}
	return (1);
}
