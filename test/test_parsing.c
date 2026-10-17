#include "../include/header.h"
# include <criterion/criterion.h>

Test(parsing, rt_extension)
{
	cr_assert(ft_check_rt_extension("map.rt"));
	cr_assert(ft_check_rt_extension("rt.rt"));
	cr_assert(ft_check_rt_extension("r.rt"));

	cr_assert(!ft_check_rt_extension("map.r"));
	cr_assert(!ft_check_rt_extension("map.rtr"));
	cr_assert(!ft_check_rt_extension("map.rtt"));
	cr_assert(!ft_check_rt_extension("map.tr"));
	cr_assert(!ft_check_rt_extension("mar.t"));
	cr_assert(!ft_check_rt_extension("map"));
	cr_assert(!ft_check_rt_extension("rt"));
	cr_assert(!ft_check_rt_extension("rt.r"));
	cr_assert(!ft_check_rt_extension("r.t"));
}

Test(parsing, valid_infos)
{
	char **infos0 = ft_split("0.2 255", " ");
	char **infos1 = ft_split("0 0", " ");
	char **infos2 = ft_split("1.0 0.5", " "); //+0.5

	cr_assert(ft_check_infos_validity(infos0, "A"));
	cr_assert(ft_check_infos_validity(infos1, "A"));
	cr_assert(ft_check_infos_validity(infos2, "A"));
}

Test(parsing, a_bad_infos)
{	
	char **a_bad0 = ft_split("255 0.2", " ");
	char **a_bad1 = ft_split("-0.3, 234,5", " ");
	char **a_bad2 = ft_split("3, 255", " ");
	char **a_bad3 = ft_split("0.2 -3", " ");
	char **a_bad4 = ft_split("0.2 255.3", " ");
	char **a_bad5 = ft_split("0.2 256", " ");
	char **a_bad6 = ft_split("0.2 255 255", " ");
	char **a_bad7 = ft_split("0.2 255 0.2", " ");
	
	cr_assert(!ft_check_infos_validity(a_bad0, "A"));
	cr_assert(!ft_check_infos_validity(a_bad1, "A"));
	cr_assert(!ft_check_infos_validity(a_bad2, "A"));
	cr_assert(!ft_check_infos_validity(a_bad3, "A"));
	cr_assert(!ft_check_infos_validity(a_bad4, "A"));
	cr_assert(!ft_check_infos_validity(a_bad5, "A"));
	cr_assert(!ft_check_infos_validity(a_bad6, "A"));
	cr_assert(!ft_check_infos_validity(a_bad7, "A"));

	ft_free_array(a_bad0);
	ft_free_array(a_bad1);
	ft_free_array(a_bad2);
	ft_free_array(a_bad3);
	ft_free_array(a_bad4);
	ft_free_array(a_bad5);
	ft_free_array(a_bad6);
	ft_free_array(a_bad7);
}

	// char **l_infos = ft_split("0.2 255", " ");
	// char **l_bad_infos = ft_split("255 0.2", " ");
	// cr_assert(ft_check_infos_validity(a_infos, "A"));
	// cr_assert(!ft_check_infos_validity(a_bad_infos, "A"));

	// char **a_infos = ft_split("0.2 255", " ");
	// char **a_bad_infos = ft_split("255 0.2", " ");
	// cr_assert(ft_check_infos_validity(a_infos, "A"));
	// cr_assert(!ft_check_infos_validity(a_bad_infos, "A"));

	// char **a_infos = ft_split("0.2 255", " ");
	// char **a_bad_infos = ft_split("255 0.2", " ");
	// cr_assert(ft_check_infos_validity(a_infos, "A"));
	// cr_assert(!ft_check_infos_validity(a_bad_infos, "A"));

	// char **a_infos = ft_split("0.2 255", " ");
	// char **a_bad_infos = ft_split("255 0.2", " ");
	// cr_assert(ft_check_infos_validity(a_infos, "A"));
	// cr_assert(!ft_check_infos_validity(a_bad_infos, "A"));

	// char **a_infos = ft_split("0.2 255", " ");
	// char **a_bad_infos = ft_split("255 0.2", " ");
	// cr_assert(ft_check_infos_validity(a_infos, "A"));
	// cr_assert(!ft_check_infos_validity(a_bad_infos, "A"));
