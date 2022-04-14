/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romannbroque <rbroque@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 18:25:51 by romannbroque      #+#    #+#             */
/*   Updated: 2022/04/14 10:49:58 by romannbroque     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_lem_in.h"
#include <check.h>

////////// get_info.c

/// ft_strlen

START_TEST(ft_strlen__1)
{
	ck_assert_int_eq(ft_strlen("bonjour"), 7);
}
END_TEST

START_TEST(ft_strlen__2)
{
	ck_assert_int_eq(ft_strlen(""), 0);
}
END_TEST

/// ft_strchr

START_TEST(ft_strchr__1)
{
	ck_assert_int_eq(ft_strchr("hello\n", '\n'), 1);
}
END_TEST

START_TEST(ft_strchr__2)
{
	ck_assert_int_eq(ft_strchr("", '\n'), 0);
}
END_TEST

START_TEST(ft_strchr__3)
{
	ck_assert_int_eq(ft_strchr("\n\n\n\n", '\n'), 1);
}
END_TEST

START_TEST(ft_strchr__4)
{
	ck_assert_int_eq(ft_strchr("\n", '\0'), 1);
}
END_TEST

START_TEST(ft_strchr__5)
{
	ck_assert_int_eq(ft_strchr(NULL, 'b'), 0);
}
END_TEST

/// is_empty

START_TEST(is_empty__1)
{
	const char	str[2] = {'\0', '\0'};

	ck_assert_int_eq(is_empty(str, 2), 1);
}
END_TEST

START_TEST(is_empty__2)
{
	const char	str[4] = "";

	ck_assert_int_eq(is_empty(str, 4), 1);
}
END_TEST

START_TEST(is_empty__3)
{
	const char	str[4] = "a";

	ck_assert_int_eq(is_empty(str, 4), 0);
}
END_TEST

Suite	*utilities(void)
{
	Suite	*s;
	TCase	*ft_strlen;
	TCase	*ft_strchr;
	TCase	*is_empty;

	s = suite_create("UTILITIES");
	ft_strlen = tcase_create("FT_STRLEN");
	ft_strchr = tcase_create("FT_STRCHR");
	is_empty = tcase_create("IS_EMPTY");

	tcase_add_test(ft_strlen, ft_strlen__1);
	tcase_add_test(ft_strlen, ft_strlen__2);
	
	tcase_add_test(ft_strchr, ft_strchr__1);
	tcase_add_test(ft_strchr, ft_strchr__2);
	tcase_add_test(ft_strchr, ft_strchr__3);
	tcase_add_test(ft_strchr, ft_strchr__4);
	tcase_add_test(ft_strchr, ft_strchr__5);
	
	tcase_add_test(is_empty, is_empty__1);
	tcase_add_test(is_empty, is_empty__2);
	tcase_add_test(is_empty, is_empty__3);

	suite_add_tcase(s, ft_strlen);
	suite_add_tcase(s, ft_strchr);
	suite_add_tcase(s, is_empty);

	return (s);
}

int	get_failed_from_suite(Suite *suite)
{
	int		not_failed;
	Suite	*s;
	SRunner	*runner;

	not_failed = 0;
	s = suite;
	runner = srunner_create(s);
	
	srunner_run_all(runner, CK_NORMAL);
	not_failed = srunner_ntests_failed(runner);
	srunner_free(runner);
	return (not_failed);
}

int	main(void)
{
	Suite	*(*suite[NBOF_SUITE])(void) = {utilities};
	int		nbof_failed;
	size_t	i;

	i = 0;
	nbof_failed = 0;
	while (i < NBOF_SUITE)
	{
		nbof_failed += get_failed_from_suite(suite[i]());
		++i;
	}
	return (nbof_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
