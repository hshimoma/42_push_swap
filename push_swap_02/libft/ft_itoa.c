/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimoma <hshimoma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 18:53:44 by hshimoma          #+#    #+#             */
/*   Updated: 2024/11/18 09:16:54 by hshimoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//整数を文字列に変換する関数

#include "libft.h"

static int	digit_count(int n)
{
	int	i;

	i = 0;
	if (n <= 0)
	{
		i++;
	}
	while (n != 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	int				len;
	char			*arr;
	unsigned int	i;

	len = digit_count(n);
	arr = (char *)malloc(len + 1);
	if (arr == NULL)
		return (NULL);
	arr[len] = '\0';
	if (n < 0)
	{
		arr[0] = '-';
		i = -n;
	}
	else
		i = n;
	while (len-- > 0 && i > 0)
	{
		arr[len] = (i % 10) + '0';
		i /= 10;
	}
	if (n == 0)
		arr[0] = '0';
	return (arr);
}

// int main(void)
// {
//     char *result;

//     // テストケース1: 正の整数
//     result = ft_itoa(123);
//     printf("Test 1: Input = 123, Output = %s\n", result);
//     free(result);

//     // テストケース2: 負の整数
//     result = ft_itoa(-456);
//     printf("Test 2: Input = -456, Output = %s\n", result);
//     free(result);

//     // テストケース3: 0の場合
//     result = ft_itoa(0);
//     printf("Test 3: Input = 0, Output = %s\n", result);
//     free(result);

//     // テストケース4: 大きな正の整数
//     result = ft_itoa(2147483647);  // INT_MAX
//     printf("Test 4: Input = 2147483647, Output = %s\n", result);
//     free(result);

//     // テストケース5: 大きな負の整数
//     result = ft_itoa(-2147483648); // INT_MIN
//     printf("Test 5: Input = -2147483648, Output = %s\n", result);
//     free(result);

//     return (0);
// }
