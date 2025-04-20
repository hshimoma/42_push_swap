/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimoma <hshimoma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 19:13:15 by hshimoma          #+#    #+#             */
/*   Updated: 2024/11/19 19:03:26 by hshimoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//文字列を区切ったものを新しく作成(文字列をn文字文複製する関数)

#include "libft.h"

 static char	*ft_strndup(const char *s1, size_t n)
{
	char	*dst;
	size_t	i;

	dst = (char *)malloc((n + 1) * sizeof(char));
	if (dst == NULL)
	{
		return (NULL);
	}
	i = 0;
	while (i < n && s1[i])
	{
		dst[i] = s1[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

static size_t	malloc_len(char const *s, char c)
{
	size_t	i;
	size_t	size;

	i = 0;
	size = 0;
	while (s[i] != '\0')
	{
		while (s[i] == c)
		{
			i++;
		}
		if (s[i] != '\0')
		{
			size++;
			while (s[i] && s[i] != c)
			{
				i++;
			}
		}
	}
	return (size);
}

static void	arr_free(char **arr, size_t arr_size)
{
	size_t	i;

	i = 0;
	while (i < arr_size)
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

 static int	split_and_allocate(char **arr, const char *s, char c)
{
	const char	*l;
	size_t		i;
	size_t		j;

	i = 0;
	j = 0;
	while (s[i] != '\0')
	{
		while (s[i] == c)
			i++;
		if (s[i] != '\0')
		{
			l = &s[i];
			while (s[i] && s[i] != c)
				i++;
			arr[j] = ft_strndup(l, i - (l - s));
			if (arr[j] == NULL)
			{
				return (arr_free(arr, j), 0);
			}
			j++;
		}
	}
	arr[j] = NULL;
	return (1);
}

char	**ft_split(char const *s, char c)
{
	char		**arr;

	if (s == NULL)
	{
		return (NULL);
	}
	arr = (char **)malloc((malloc_len(s, c) + 1) * sizeof(char *));
	if (arr == NULL)
	{
		return (NULL);
	}
	if (!split_and_allocate(arr, s, c))
	{
		return (NULL);
	}
	return (arr);
}

//test
// #include <stdio.h>

// // 配列の内容を出力する関数
// void print_split_result(char **result)
// {
//     int i = 0;
//     while (result[i])
// 	{
//         printf("result[%d]: %s\n", i, result[i]);
//         i++;
//     }
// }

// int main(void)
// {
//     char **result;

//     // テストケース1: 通常の分割
//     printf("Test 1:\n");
//     result = ft_split("Hello,World,Test", ',');
//     print_split_result(result);

//     // テストケース2: デリミタが先頭と末尾にある場合
//     printf("\nTest 2:\n");
//     result = ft_split(",Start,Middle,End,", ',');
//     print_split_result(result);

//     // テストケース3: デリミタが連続している場合
//     printf("\nTest 3:\n");
//     result = ft_split("A,,B,,,C", ',');
//     print_split_result(result);

//     // テストケース4: 空文字列を分割
//     printf("\nTest 4:\n");
//     result = ft_split("", ',');
//     print_split_result(result);

//     // テストケース5: デリミタが存在しない場合
//     printf("\nTest 5:\n");
//     result = ft_split("NoDelimitersHere", ',');
//     print_split_result(result);

//     return (0);
// }

// ーー結果ーー
// Test 1:
// result[0]: Hello
// result[1]: World
// result[2]: Test

// Test 2:
// result[0]: Start
// result[1]: Middle
// result[2]: End

// Test 3:
// result[0]: A
// result[1]: B
// result[2]: C

// Test 4:
// (空の出力)

// Test 5:
// result[0]: NoDelimitersHere
