/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romannbroque <rbroque@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 18:25:51 by romannbroque      #+#    #+#             */
/*   Updated: 2022/05/02 19:33:57 by romannbroque     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_lem_in.h"
#include <check.h>

////////////////////////////////////////////////////////////////////////////////

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

/// ft_is_equal

START_TEST(ft_is_equal__1)
{
	ck_assert_int_eq(ft_is_equal("Hello my name is Morpheus", "Hello my name is Morpheus"), 1);
}
END_TEST

START_TEST(ft_is_equal__2)
{
	ck_assert_int_eq(ft_is_equal("Hello", "Hello my name"), 0);
}
END_TEST

START_TEST(ft_is_equal__3)
{
	ck_assert_int_eq(ft_is_equal("Hello my name", "Hello"), 0);
}
END_TEST

/// ft_strchr

START_TEST(ft_strchr__1)
{
	ck_assert_str_eq(ft_strchr("hello\n", '\n'), "\n");
}
END_TEST

START_TEST(ft_strchr__2)
{
	ck_assert_ptr_eq(ft_strchr("", '\n'), NULL);
}
END_TEST

START_TEST(ft_strchr__3)
{
	ck_assert_str_eq(ft_strchr("\n\n\n\n", '\n'), "\n\n\n\n");
}
END_TEST

START_TEST(ft_strchr__4)
{
	ck_assert_ptr_eq(ft_strchr("", '\n'), NULL);
}
END_TEST

START_TEST(ft_strchr__5)
{
	ck_assert_str_eq(ft_strchr("\n", '\n'), "\n");
}
END_TEST

START_TEST(ft_strchr__6)
{
	ck_assert_str_eq(ft_strchr("ooh\nhello\n", '\n'), "\nhello\n");
}
END_TEST

START_TEST(ft_strchr__7)
{
	ck_assert_str_eq(ft_strchr("ooh\n\nhello\n", '\n'), "\n\nhello\n");
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

/// ft_strndup

START_TEST(ft_strndup__1)
{
	const char	*str = "hello !";

	ck_assert_str_eq(ft_strndup(str, 3), "hel");
}
END_TEST

START_TEST(ft_strndup__2)
{
	const char	*str = "hello !";

	ck_assert_str_eq(ft_strndup(str, 10), str);
}
END_TEST

START_TEST(ft_strndup__3)
{
	const char	*str = "My name is Morpheus";

	ck_assert_str_eq(ft_strndup(str, 0), "");
}
END_TEST

/// ft_strtok

START_TEST(ft_strtok__1)
{
	const char	*str = "My name is Morpheus";
	const char	*delim = "is";

	ck_assert_str_eq(ft_strtok(str, delim), "My name ");
}
END_TEST

START_TEST(ft_strtok__2)
{
	const char	*str = "My name is Morpheus";
	const char	*delim = "pheus";

	ck_assert_str_eq(ft_strtok(str, delim), "My name is Mor");
}
END_TEST

START_TEST(ft_strtok__3)
{
	const char	*str = "My name is Morpheus";
	const char	*delim = "";

	ck_assert_str_eq(ft_strtok(str, delim), "");
}
END_TEST

Suite	*utilities(void)
{
	Suite	*s;
	TCase	*ft_strlen;
	TCase	*ft_is_equal;
	TCase	*ft_strchr;
	TCase	*is_empty;
	TCase	*ft_strndup;
	TCase	*ft_strtok;

	s = suite_create("UTILITIES");
	ft_strlen = tcase_create("FT_STRLEN");
	ft_is_equal = tcase_create("FT_IS_EQUAL");
	ft_strchr = tcase_create("FT_STRCHR");
	is_empty = tcase_create("IS_EMPTY");
	ft_strndup = tcase_create("FT_STRNDUP");
	ft_strtok = tcase_create("FT_STRTOK");

	tcase_add_test(ft_strlen, ft_strlen__1);
	tcase_add_test(ft_strlen, ft_strlen__2);

	tcase_add_test(ft_is_equal, ft_is_equal__1);
	tcase_add_test(ft_is_equal, ft_is_equal__2);
	tcase_add_test(ft_is_equal, ft_is_equal__3);
	
	tcase_add_test(ft_strchr, ft_strchr__1);
	tcase_add_test(ft_strchr, ft_strchr__2);
	tcase_add_test(ft_strchr, ft_strchr__3);
	tcase_add_test(ft_strchr, ft_strchr__4);
	tcase_add_test(ft_strchr, ft_strchr__5);
	tcase_add_test(ft_strchr, ft_strchr__6);
	tcase_add_test(ft_strchr, ft_strchr__7);
	
	tcase_add_test(is_empty, is_empty__1);
	tcase_add_test(is_empty, is_empty__2);
	tcase_add_test(is_empty, is_empty__3);
	
	tcase_add_test(ft_strndup, ft_strndup__1);
	tcase_add_test(ft_strndup, ft_strndup__2);
	tcase_add_test(ft_strndup, ft_strndup__3);
	
	tcase_add_test(ft_strtok, ft_strtok__1);
	tcase_add_test(ft_strtok, ft_strtok__2);
	tcase_add_test(ft_strtok, ft_strtok__3);

	suite_add_tcase(s, ft_strlen);
	suite_add_tcase(s, ft_strchr);
	suite_add_tcase(s, ft_is_equal);
	suite_add_tcase(s, is_empty);
	suite_add_tcase(s, ft_strndup);
	suite_add_tcase(s, ft_strtok);

	return (s);
}

////////////////////////////////////////////////////////////////////////////////

/// get_next_line

START_TEST(gnl__1)
{
	int	fd;

	fd = open("./tests/assets_test/file.txt", O_RDONLY);

	ck_assert_str_eq(get_next_line(fd), "I'm Morpheus,");
	ck_assert_str_eq(get_next_line(fd), "");
	ck_assert_str_eq(get_next_line(fd), "Follow the white rabbit Neo...");
	ck_assert_str_eq(get_next_line(fd), "");
	ck_assert_str_eq(get_next_line(fd), "");
	ck_assert_str_eq(get_next_line(fd), "...or take the blue pill.");
	close(fd);
}
END_TEST

START_TEST(gnl__2)
{
	int	fd;

	fd = -1;
	ck_assert_ptr_eq(get_next_line(fd), NULL);
}
END_TEST

/// is_start_inst

START_TEST(is_start_inst__1)
{
	const char	*command = "#start bahbah";

	ck_assert_str_eq(is_start_inst(command), "bahbah");
}
END_TEST

START_TEST(is_start_inst__2)
{
	const char	*command = "#sta rt bahbah";

	ck_assert_ptr_eq(is_start_inst(command), NULL);
}
END_TEST

START_TEST(is_start_inst__3)
{
	const char	*command = "#start";

	ck_assert_ptr_eq(is_start_inst(command), NULL);
}
END_TEST

/// is_end_inst

START_TEST(is_end_inst__1)
{
	const char	*command = "#end bahbah";

	ck_assert_str_eq(is_end_inst(command), "bahbah");
}
END_TEST

START_TEST(is_end_inst__2)
{
	const char	*command = " #end bahbah";

	ck_assert_ptr_eq(is_end_inst(command), NULL);
}
END_TEST

START_TEST(is_end_inst__3)
{
	const char	*command = "#end";

	ck_assert_ptr_eq(is_end_inst(command), NULL);
}
END_TEST

/// is_link_inst

START_TEST(is_link_inst__1)
{
	const char	*command = "burger-sandwich";

	ck_assert_str_eq(is_link_inst(command), command);
}
END_TEST

START_TEST(is_link_inst__2)
{
	const char	*command = "ends";

	ck_assert_ptr_eq(is_link_inst(command), NULL);
}
END_TEST

START_TEST(is_link_inst__3)
{
	const char	*command = "-ho";

	ck_assert_str_eq(is_link_inst(command), command);
}
END_TEST

START_TEST(is_link_inst__4)
{
	const char	*command = "";

	ck_assert_ptr_eq(is_link_inst(command), NULL);
}
END_TEST

Suite	*parser(void)
{
	Suite	*s;
	TCase	*gnl;
	TCase	*find_inst;

	s = suite_create("PARSER");
	gnl = tcase_create("GNL");
	find_inst = tcase_create("FIND_INSTRUCTIONS");

	tcase_add_test(gnl, gnl__1);
	tcase_add_test(gnl, gnl__2);

	tcase_add_test(find_inst, is_start_inst__1);
	tcase_add_test(find_inst, is_start_inst__2);
	tcase_add_test(find_inst, is_start_inst__3);
	
	tcase_add_test(find_inst, is_end_inst__1);
	tcase_add_test(find_inst, is_end_inst__2);
	tcase_add_test(find_inst, is_end_inst__3);

	tcase_add_test(find_inst, is_link_inst__1);
	tcase_add_test(find_inst, is_link_inst__2);
	tcase_add_test(find_inst, is_link_inst__3);
	tcase_add_test(find_inst, is_link_inst__4);

	suite_add_tcase(s, gnl);
	suite_add_tcase(s, find_inst);

	return (s);
}

////////////////////////////////////////////////////////////////////////////////

/// create_list

START_TEST(create_list__1)
{
	t_list	*list;
	const char	*name = "Strawberry";

	list = create_list((char *)name, NULL);
	ck_assert_str_eq(list->data, name);
	ck_assert_ptr_eq(list->next, NULL);
}
END_TEST

START_TEST(create_list__2)
{
	t_list		*list;
	const char	*name = "";
	char		*ptr;

	ptr = ft_strdup(name);
	list = create_list((char *)name, ptr);
	ck_assert_str_eq(list->data, name);
	ck_assert_ptr_eq(list->next, ptr);
}
END_TEST

START_TEST(create_list__3)
{
	t_list		*list;

	list = create_list(NULL, NULL);
	ck_assert_ptr_eq(list->data, NULL);
	ck_assert_ptr_eq(list->next, NULL);
}
END_TEST

/// add

START_TEST(add__1)
{
	const char	*name = "Apple";
	const char	*new_name = "Cherry";
	t_list		*list;
	t_list		*new;

	list = create_list((char *)name, NULL);
	new = create_list((char *)new_name, NULL);
	add(&list, new);
	ck_assert_str_eq(list->data, name);
	ck_assert_ptr_eq(list->next, new);
}
END_TEST

START_TEST(add__2)
{
	const char	*name = "Cherry";
	t_list		*list;
	t_list		*new;

	list = NULL;
	new = create_list((char *)name, NULL);
	add(&list, new);
	ck_assert_str_eq(list->data, name);
	ck_assert_ptr_eq(list->next, new->next);
	ck_assert_ptr_eq(list, new);
}
END_TEST

START_TEST(add__3)
{
	const char	*name1 = "Airplane";
	const char	*name2 = "Bottle";
	const char	*name3 = "Chicken";
	t_list		*node1;
	t_list		*node2;
	t_list		*node3;

	node1 = create_list((char *)name1, NULL);
	node2 = create_list((char *)name2, NULL);
	node3 = create_list((char *)name3, NULL);
	add(&node1, node2);
	add(&node1, node3);
	ck_assert_str_eq(node1->data, name1);
	ck_assert_ptr_eq(node1->next, node2);
	ck_assert_ptr_eq(node2->next, node3);
}
END_TEST

/// add_element

START_TEST(add_element_1)
{
	const char	*name1 = "Airplane";
	const char	*name2 = "Bottle";
	const char	*name3 = "Chicken";
	t_list		*rooms = NULL;
	t_room		*room1 = create_room(name1, NULL);
	t_room		*room2 = create_room(name2, NULL);
	t_room		*room3 = create_room(name3, NULL);

	add_element(&rooms, room1);
	add_element(&rooms, room2);
	add_element(&rooms, room3);
	ck_assert_ptr_eq(rooms->data, room1);
	ck_assert_ptr_eq((((t_list *)rooms->next))->data, room2);
}
END_TEST

/// destroy

START_TEST(destroy__1)
{
	const char	*name1 = "Airplane";
	t_list		*node1;

	node1 = create_list((char *)name1, NULL);
	destroy(&node1, full_free);
	ck_assert_ptr_eq(node1, NULL);
}
END_TEST

START_TEST(destroy__2)
{
	char	*stuff;

	stuff = ft_strdup("Hello");
	destroy(&stuff, full_free);
	ck_assert_ptr_eq(stuff, NULL);
}
END_TEST

/// destroy_node

START_TEST(destroy_node__1)
{
	t_list	*node;

	node = create_list("Hello", NULL);
	destroy_node(&node, NULL);
	ck_assert_ptr_eq(node, NULL);
}
END_TEST

/// cut

START_TEST(cut__1)
{
	const char	*name1 = "Airplane";
	const char	*name2 = "Bottle";
	const char	*name3 = "Cherry";
	t_list		*node1;
	t_list		*node2;
	t_list		*node3;

	node1 = create_list((char *)name1, NULL);
	node2 = create_list((char *)name2, NULL);
	node3 = create_list((char *)name3, NULL);
	add(&node1, node2);
	add(&node1, node3);
	cut(&node1, NULL);
	ck_assert_str_eq(node1->data, name1);
	ck_assert_ptr_eq(node1->next, node2);
	ck_assert_str_eq(node2->data, name2);
	ck_assert_ptr_eq(node2->next, NULL);
}
END_TEST

START_TEST(cut__2)
{
	const char	*name1 = "Airplane";
	t_list		*node1;

	node1 = create_list((char *)name1, NULL);
	cut(&node1, NULL);
	ck_assert_ptr_eq(node1, NULL);
}
END_TEST

/// destroy_list

START_TEST(destroy_list__1)
{
	const char	*name1 = "Airplane";
	const char	*name2 = "Bottle";
	const char	*name3 = "Cherry";
	t_list		*node1;
	t_list		*node2;
	t_list		*node3;

	node1 = create_list((char *)name1, NULL);
	node2 = create_list((char *)name2, NULL);
	node3 = create_list((char *)name3, NULL);
	add(&node1, node2);
	add(&node1, node3);
	destroy_list(&node1, NULL);
	ck_assert_ptr_eq(node1, NULL);
}
END_TEST

/// get_size_list

START_TEST(get_size_list__1)
{
	const char	*name1 = "Airplane";
	const char	*name2 = "Bottle";
	const char	*name3 = "Cherry";
	t_list		*node1;
	t_list		*node2;
	t_list		*node3;

	node1 = create_list((char *)name1, NULL);
	node2 = create_list((char *)name2, NULL);
	node3 = create_list((char *)name3, NULL);
	add(&node1, node2);
	add(&node1, node3);
	ck_assert_int_eq(get_size_list(node1), 3);
}
END_TEST

START_TEST(get_size_list__2)
{
	ck_assert_int_eq(get_size_list(NULL), 0);
}
END_TEST

/// are_lists_equal

START_TEST(are_lists_equal__1)
{
	t_list	*list1;
	t_list	*list2;

	list1 = NULL;
	list2 = list1;
	ck_assert_int_eq(are_lists_equal(list1, list2), 1);
}
END_TEST

START_TEST(are_lists_equal__2)
{
	t_list	*list1 = NULL;
	t_list	*list2 = NULL;
	char	*str1 = "HELLO1";
	char	*str2 = "HELLO2";

	add_element(&list1, str1);
	add_element(&list1, str2);
	add_element(&list2, str1);
	add_element(&list2, str2);
	ck_assert_int_eq(are_lists_equal(list1, list2), 1);
}
END_TEST

START_TEST(are_lists_equal__3)
{
	t_list	*list1 = NULL;
	t_list	*list2 = NULL;
	char	*str1 = "HELLO1";
	char	*str2 = "HELLO2";
	char	*str3 = "HELLO3";

	add_element(&list1, str1);
	add_element(&list1, str2);
	add_element(&list2, str1);
	add_element(&list2, str2);
	add_element(&list2, str3);
	ck_assert_int_eq(are_lists_equal(list1, list2), 0);
}
END_TEST

START_TEST(are_lists_equal__4)
{
	t_list	*list1 = NULL;
	t_list	*list2 = NULL;
	char	*str1 = "HELLO1";
	char	*str2 = "HELLO2";
	char	*str3 = "HELLO3";

	add_element(&list1, str2);
	add_element(&list1, str1);
	add_element(&list2, str1);
	add_element(&list2, str2);
	add_element(&list2, str3);
	ck_assert_int_eq(are_lists_equal(list1, list2), 0);
}
END_TEST

Suite	*linked_list(void)
{
	Suite	*s;
	TCase	*create_structure;
	TCase	*destroy_structure;
	TCase	*get_info;

	s = suite_create("LINKED_LIST");
	create_structure = tcase_create("CREATE_STRUCTURE");
	destroy_structure = tcase_create("DESTROY_STRUCTURE");
	destroy_structure = tcase_create("DESTROY_STRUCTURE");
	get_info = tcase_create("GET_INFO");

	tcase_add_test(create_structure, create_list__1);
	tcase_add_test(create_structure, create_list__2);
	tcase_add_test(create_structure, create_list__3);

	tcase_add_test(create_structure, add__1);
	tcase_add_test(create_structure, add__2);
	tcase_add_test(create_structure, add__3);
	
	tcase_add_test(create_structure, add_element_1);

	tcase_add_test(destroy_structure, destroy__1);
	tcase_add_test(destroy_structure, destroy__2);
	
	tcase_add_test(destroy_structure, cut__1);
	tcase_add_test(destroy_structure, cut__2);
	
	tcase_add_test(destroy_structure, destroy_list__1);
	
	tcase_add_test(destroy_structure, destroy_node__1);

	tcase_add_test(get_info, get_size_list__1);
	tcase_add_test(get_info, get_size_list__2);

	tcase_add_test(get_info, are_lists_equal__1);
	tcase_add_test(get_info, are_lists_equal__2);
	tcase_add_test(get_info, are_lists_equal__3);
	tcase_add_test(get_info, are_lists_equal__4);

	suite_add_tcase(s, create_structure);
	suite_add_tcase(s, destroy_structure);
	suite_add_tcase(s, get_info);

	return (s);
}

////////////////////////////////////////////////////////////////////////////////

/// init_graph

START_TEST(init_graph__1)
{
	t_graph	graph;

	init_graph(&graph);
	ck_assert_ptr_eq(graph.rooms, NULL);
	ck_assert_ptr_eq(graph.start, NULL);
	ck_assert_ptr_eq(graph.end, NULL);
}
END_TEST

/// create_room

START_TEST(create_room__1)
{
	const char	*name = "Hello";
	t_room		*new;

	new = create_room(name, NULL);
	ck_assert_str_eq(new->name, name);
	ck_assert_ptr_eq(new->neighboor, NULL);
}
END_TEST

START_TEST(create_room__2)
{
	char	*name0 = "Hello";
	char	*name1 = "Mister";
	char	*name2 = "Anderson";
	t_list		*node1;
	t_list		*node2;
	t_room		*room0;
	t_room		*room1;
	t_room		*room2;

	room1 = create_room(name1, NULL);
	room2 = create_room(name2, NULL);
	node1 = create_list((char *)room1, NULL);
	node2 = create_list((char *)room2, NULL);
	add(&node1, node2);

	room0 = create_room(name0, node1);
	ck_assert_str_eq(room0->name, (char *)name0);
	ck_assert_ptr_eq(room0->neighboor, node1);
	ck_assert_ptr_eq((t_list *)(room0->neighboor)->next, node2);
	ck_assert_ptr_eq((t_list *)(room0->neighboor)->data, room1);
	ck_assert_str_eq(room1->name, name1);
	ck_assert_ptr_eq(room1->neighboor, NULL);
	ck_assert_str_eq(room1->name, name1);
}
END_TEST

/// find_room

START_TEST(find_room__1)
{
	const char	*name1 = "Airplane";
	const char	*name2 = "Bottle";
	const char	*name3 = "Chicken";
	t_list		*rooms = NULL;
	t_room		*room1 = create_room(name1, NULL);
	t_room		*room2 = create_room(name2, NULL);
	t_room		*room3 = create_room(name3, NULL);
	t_room		*new;

	add_element(&rooms, room1);
	add_element(&rooms, room2);
	add_element(&rooms, room3);
	new = find_room(rooms, name2);
	ck_assert_ptr_eq(new, room2);
}
END_TEST

START_TEST(find_room__2)
{
	const char	*name1 = "Airplane";
	const char	*name2 = "Bottle";
	const char	*name3 = "Chicken";
	t_list		*rooms = NULL;
	t_room		*room1 = create_room(name1, NULL);
	t_room		*room2 = create_room(name2, NULL);
	t_room		*room3 = create_room(name3, NULL);
	t_room		*new;

	add_element(&rooms, room1);
	add_element(&rooms, room2);
	add_element(&rooms, room3);
	new = find_room(rooms, "hello");
	ck_assert_ptr_eq(new, NULL);
}
END_TEST

Suite	*structure(void)
{
	Suite	*s;
	TCase	*graph;
	TCase	*room;
	TCase	*path;

	s = suite_create("STRUCTURE");
	graph = tcase_create("GRAPH");
	room = tcase_create("ROOM");
	path = tcase_create("PATH");

	tcase_add_test(graph, init_graph__1);

	tcase_add_test(room, create_room__1);
	tcase_add_test(room, create_room__2);
	
	tcase_add_test(room, find_room__1);
	tcase_add_test(room, find_room__2);

	suite_add_tcase(s, graph);
	suite_add_tcase(s, room);
	suite_add_tcase(s, path);

	return (s);
}

////////////////////////////////////////////////////////////////////////////////

/// exe_inst.c

// start

START_TEST(start__1)
{
	const char	*command = "Hello";
	t_graph		graph;
	t_result		rt_value;

	init_graph(&graph);
	rt_value = start(&graph, command);
	ck_assert_str_eq(((t_room *)(graph.start))->name, "Hello");
	ck_assert_int_eq(rt_value, EXIT_SUCCESS);
}
END_TEST

START_TEST(start__2)
{
	const char	*command = "ouah";
	t_graph		graph;
	t_result		rt_value;

	init_graph(&graph);
	rt_value = start(&graph, command);
	ck_assert_str_eq(((t_room *)(graph.start))->name, "ouah");
	ck_assert_int_eq(rt_value, EXIT_SUCCESS);
}
END_TEST

Suite	*instructions(void)
{
	Suite	*s;
	TCase	*start;
//	TCase	*end;
//	TCase	*link;

	s = suite_create("INSTRUCTIONS");
	start = tcase_create("START");
//	end = tcase_create("END");
//	link = tcase_create("LINK");

	tcase_add_test(start, start__1);
	tcase_add_test(start, start__2);
	
//	tcase_add_test(graph, end__1);

	suite_add_tcase(s, start);
//	suite_add_tcase(s, end);
//	suite_add_tcase(s, link);

	return (s);
}


////////////////////////////////////////////////////////////////////////////////

/// extract_path

START_TEST(extract_path__1)
{
	const char	*name1 = "Hello1";
	const char	*name2 = "Hello2";
	const char	*name3 = "Hello3";
	t_room		*room1 = create_room(name1, NULL);
	t_room		*room2 = create_room(name2, NULL);
	t_room		*room3 = create_room(name3, NULL);
	t_list		*path1 = NULL;
	t_list		*path2 = NULL;
	t_graph		graph;

	init_graph(&graph);
	add_element(&path1, room1);
	add_element(&path1, room2);
	add_element(&path2, room1);
	add_element(&path2, room2);
	add_element(&path2, room3);
	extract_path(&graph, &path1);
	extract_path(&graph, &path2);
	ck_assert_int_eq(get_size_list(graph.shortest_paths), 1);
}
END_TEST

/*
START_TEST(keep_shortest_paths__2)
{
	t_graph		graph;
	const char	*name1 = "Hello1";
	const char	*name2 = "Hello2";
	t_room		*room1 = create_room(name1, NULL);
	t_room		*room2 = create_room(name2, NULL);
	t_path		*path1 = create_path(NULL);
	t_path		*path2 = create_path(NULL);
	
	init_graph(&graph);
	add_element(&path1->rooms, room1);
	add_element(&path1->rooms, room2);
	add_element(&path2->rooms, room1);
	add_element(&path2->rooms, room2);
	path1->size = get_size_list(path1->rooms);
	path2->size = get_size_list(path2->rooms);
	extract_path(&graph, &path1->rooms);
	extract_path(&graph, &path2->rooms);
	ck_assert_ptr_eq((graph.shortest_paths)->data, path1->rooms);
	ck_assert_ptr_eq(graph.shortest_paths->next->data, path2->rooms);
}
END_TEST
*/

Suite	*find_shortest_paths(void)
{
	Suite	*s;
	TCase	*path_finder;

	s = suite_create("FIND_SHORTEST_PATHS");
	path_finder = tcase_create("PATH_FINDER");

	tcase_add_test(path_finder, extract_path__1);
	
	suite_add_tcase(s, path_finder);

	return (s);
}

////////////////////////////////////////////////////////////////////////////////

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
	Suite	*(*suite[NBOF_SUITE])(void) = {utilities, parser, linked_list,
											structure, instructions, 
											find_shortest_paths};
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
