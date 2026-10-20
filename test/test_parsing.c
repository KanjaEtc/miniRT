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

Test(parsing, a_valid_infos)
{
	char **infos0 = ft_split("0.2 255", ",	 ");
	char **infos1 = ft_split("0 0", " ,	");
	char **infos2 = ft_split("1.0 +0.5", ",	 ");

	cr_assert(ft_check_infos_validity(infos0, "A"));
	cr_assert(ft_check_infos_validity(infos1, "A"));
	cr_assert(ft_check_infos_validity(infos2, "A"));

	ft_free_array(infos0);
	ft_free_array(infos1);
	ft_free_array(infos2);
}

Test(parsing, a_bad_infos)
{	
	char **a_bad0 = ft_split("255 0.2", ",	 ");
	char **a_bad1 = ft_split("-0.3 2345", ",	 ");
	char **a_bad2 = ft_split("3, 255", " ,	");
	char **a_bad3 = ft_split("0.2 -3", ",	 ");
	char **a_bad4 = ft_split("0.2 255.3", " ,	");
	char **a_bad5 = ft_split("0.2 256", " ,	");
	
	cr_assert(!ft_check_infos_validity(a_bad0, "A"));
	cr_assert(!ft_check_infos_validity(a_bad1, "A"));
	cr_assert(!ft_check_infos_validity(a_bad2, "A"));
	cr_assert(!ft_check_infos_validity(a_bad3, "A"));
	cr_assert(!ft_check_infos_validity(a_bad4, "A"));
	cr_assert(!ft_check_infos_validity(a_bad5, "A"));

	ft_free_array(a_bad0);
	ft_free_array(a_bad1);
	ft_free_array(a_bad2);
	ft_free_array(a_bad3);
	ft_free_array(a_bad4);
	ft_free_array(a_bad5);
}

Test(parsing, c_valid_infos)
{
	char **infos0 = ft_split("-1 +2 05.2, 0 0 -1, 70", " ,	");
	char **infos1 = ft_split("-01 +2 05.2 -00.0 0.4 -1 70", ",	 ");
	char **infos2 = ft_split("-1 +2 05.2 0 0 -1 180", " ,	");
	char **infos3 = ft_split("-1 +2 05.2 0 0 -1 0", ",	 ");

	cr_assert(ft_check_infos_validity(infos0, "C"));
	cr_assert(ft_check_infos_validity(infos1, "C"));
	cr_assert(ft_check_infos_validity(infos2, "C"));
	cr_assert(ft_check_infos_validity(infos3, "C"));

	ft_free_array(infos0);
	ft_free_array(infos1);
	ft_free_array(infos2);
	ft_free_array(infos3);
}

Test(parsing, c_bad_infos)
{
	char **c_bad0 = ft_split("-1 +2 05.2 0 1 1.1 70", " ,	");
	char **c_bad1 = ft_split("-1 +2 05.2 0 -3 1 70", " ,	");
	char **c_bad2 = ft_split("-1 +2 05.2 3 1 1 70", " ,	");
	char **c_bad3 = ft_split("-1 +2 05.2 , 0 -3 1 70", " ,	");
	char **c_bad4 = ft_split("-1 +2 05.2 0 0 -1 -3", " 	,");
	char **c_bad5 = ft_split("-1 +2 05.2 0 0 -1 180.3", "	, ");
	char **c_bad6 = ft_split("-1 +2 05.2 0 0 -1 300", ",	 ");
	char **c_bad7 = ft_split("-1 +2 05.2 0 0 -1 -0.3", " ,	");

	cr_assert(!ft_check_infos_validity(c_bad0, "C"));
	cr_assert(!ft_check_infos_validity(c_bad1, "C"));
	cr_assert(!ft_check_infos_validity(c_bad2, "C"));
	cr_assert(!ft_check_infos_validity(c_bad3, "C"));
	cr_assert(!ft_check_infos_validity(c_bad4, "C"));
	cr_assert(!ft_check_infos_validity(c_bad5, "C"));
	cr_assert(!ft_check_infos_validity(c_bad6, "C"));
	cr_assert(!ft_check_infos_validity(c_bad7, "C"));

	ft_free_array(c_bad0);
	ft_free_array(c_bad1);
	ft_free_array(c_bad2);
	ft_free_array(c_bad3);
	ft_free_array(c_bad4);
	ft_free_array(c_bad5);
	ft_free_array(c_bad6);
	ft_free_array(c_bad7);
}

Test(parsing, l_valid_infos)
{
	char **infos0 = ft_split("-00.1 +02.2 -0.0 0.001 0 8 6", " ,	");
	char **infos1 = ft_split("-00.1 +02.2 -0.0 0 +1 255 255 255", " ,	");
	char **infos2 = ft_split("-0 +0.0 0.0.0000 0 0 0 0", " 	,");
	char **infos3 = ft_split("-00.1 +02.2 -0.0 0.001 +0.7 0.01 002", " ,	");

	cr_assert(ft_check_infos_validity(infos0, "L"));
	cr_assert(ft_check_infos_validity(infos1, "L"));
	cr_assert(ft_check_infos_validity(infos2, "L"));
	cr_assert(ft_check_infos_validity(infos3, "L"));

	ft_free_array(infos0);
	ft_free_array(infos1);
	ft_free_array(infos2);
	ft_free_array(infos3);
}

Test(parsing, l_bad_infos)
{
	char **l_bad0 = ft_split("-00.1 +02.2 -0.0 1.003 0 8 6", " ,	");
	char **l_bad1 = ft_split("-00.1 +02.2 -0.0 0 -0.0003 255 255 255", ",	 ");
	char **l_bad2 = ft_split("-0 +0.0 0.0.0000 -3 0 0 0", " 	,");
	char **l_bad3 = ft_split("-00.1 +02.2 -0.0 0 -0.7 0.02 002", ",	 ");
	char **l_bad4 = ft_split("-00.1 +02.2 -0.0 0 0.7 255.0003 002", " ,	");
	char **l_bad5 = ft_split("-00.1 +02.2 -0.0 0 0.7 0.02 -333", " ,	");

	cr_assert(!ft_check_infos_validity(l_bad0, "L"));
	cr_assert(!ft_check_infos_validity(l_bad1, "L"));
	cr_assert(!ft_check_infos_validity(l_bad2, "L"));
	cr_assert(!ft_check_infos_validity(l_bad3, "L"));
	cr_assert(!ft_check_infos_validity(l_bad4, "L"));
	cr_assert(!ft_check_infos_validity(l_bad5, "L"));

	ft_free_array(l_bad0);
	ft_free_array(l_bad1);
	ft_free_array(l_bad2);
	ft_free_array(l_bad3);
	ft_free_array(l_bad4);
	ft_free_array(l_bad5);
}

Test(parsing, pl_valid_infos)
{
	char **infos0 = ft_split("0 1 2 1 0.5 -1 255 0 4.5", "	, ");
	char **infos1 = ft_split("+00.0000 1 2 +1 -0.5 -001 255 255 255", " 	,");
	char **infos2 = ft_split("0 -1000.4 2 0 0 -0 0.00 -0.0 +0.000", " 	,");
	char **infos3 = ft_split("0 1 +0222 1 1 1 255.0 +255.0 255.00000000", "	, ");

	cr_assert(ft_check_infos_validity(infos0, "pl"));
	cr_assert(ft_check_infos_validity(infos1, "pl"));
	cr_assert(ft_check_infos_validity(infos2, "pl"));
	cr_assert(ft_check_infos_validity(infos3, "pl"));

	ft_free_array(infos0);
	ft_free_array(infos1);
	ft_free_array(infos2);
	ft_free_array(infos3);
}

Test(parsing, pl_bad_infos)
{
	char **pl_bad0 = ft_split("0 1 2 -1.0001 0 0 255 255 255", ",	 ");
	char **pl_bad1 = ft_split("0 1 2 0 +1.0001 0 255 255 255", ",	 ");
	char **pl_bad2 = ft_split("0 1 2 0 0 +0003 255 255 255", " ,	");
	char **pl_bad3 = ft_split("0 1 2 0 1 0 255.0001 255 255", " 	,");
	char **pl_bad4 = ft_split("0 1 2 0 1 0 255 -0255 255", " 	,");
	char **pl_bad5 = ft_split("0 1 2 0 1 0 255 255 -25.5", "	, ");

	cr_assert(!ft_check_infos_validity(pl_bad0, "pl"));
	cr_assert(!ft_check_infos_validity(pl_bad1, "pl"));
	cr_assert(!ft_check_infos_validity(pl_bad2, "pl"));
	cr_assert(!ft_check_infos_validity(pl_bad3, "pl"));
	cr_assert(!ft_check_infos_validity(pl_bad4, "pl"));
	cr_assert(!ft_check_infos_validity(pl_bad5, "pl"));

	ft_free_array(pl_bad0);
	ft_free_array(pl_bad1);
	ft_free_array(pl_bad2);
	ft_free_array(pl_bad3);
	ft_free_array(pl_bad4);
	ft_free_array(pl_bad5);
}

Test(parsing, sp_valid_infos)
{
	char **infos0 = ft_split("46222 2 2 -0 0255 00255 00000000000255", " 	,");
	char **infos1 = ft_split("0 0 0 +8.888888888888 -0 -0 -0", " 	,");
	char **infos2 = ft_split("0 0 0 0 0 0 0", " ,	");
	char **infos3 = ft_split("0.0000000001 444 +0.555555555 0.0001 254.99999 +00.0 -00", ",	 ");

	cr_assert(ft_check_infos_validity(infos0, "sp"));
	cr_assert(ft_check_infos_validity(infos1, "sp"));
	cr_assert(ft_check_infos_validity(infos2, "sp"));
	cr_assert(ft_check_infos_validity(infos3, "sp"));

	ft_free_array(infos0);
	ft_free_array(infos1);
	ft_free_array(infos2);
	ft_free_array(infos3);
}

Test(parsing, sp_bad_infos)
{
	char **sp_bad0 = ft_split("2 4 6 -1 255 255 255", "	, ");
	char **sp_bad1 = ft_split("2 4 6 -0.0003 255 255 255", ",	 ");
	char **sp_bad2 = ft_split("2 4 6 8 255 255 2555", " 	,");
	char **sp_bad3 = ft_split("2 4 6 8 -255 255 255", " ,	");
	char **sp_bad4 = ft_split("2 4 6 8 255 +00000000255255", " ,	");

	cr_assert(!ft_check_infos_validity(sp_bad0, "sp"));
	cr_assert(!ft_check_infos_validity(sp_bad1, "sp"));
	cr_assert(!ft_check_infos_validity(sp_bad2, "sp"));
	cr_assert(!ft_check_infos_validity(sp_bad3, "sp"));
	cr_assert(!ft_check_infos_validity(sp_bad4, "sp"));

	ft_free_array(sp_bad0);
	ft_free_array(sp_bad1);
	ft_free_array(sp_bad2);
	ft_free_array(sp_bad3);
	ft_free_array(sp_bad4);
}

Test(parsing, cy_valid_infos)
{
	char **infos0 = ft_split("50.0,	0.0,20.6 	0, 0, 1.0	14.2   21.42 10, 0, 255", "	 ,");
	char **infos1 = ft_split("0 0 0  1,1,1	12345 0  255.0 +255 -00", ",	 ");
	char **infos2 = ft_split("00000,00 000  +0.2 -0.4 +00.08 0.0  12345  2 5 6", " 	,");
	char **infos3 = ft_split("256 257 258  -1 -1 -1  256  400  0 1 0", " 	,");
	char **infos4 = ft_split("0 0 0  1,1,1  -00.0  -000  255 255 255", " 	,");

	cr_assert(ft_check_infos_validity(infos0, "cy"));
	cr_assert(ft_check_infos_validity(infos1, "cy"));
	cr_assert(ft_check_infos_validity(infos2, "cy"));
	cr_assert(ft_check_infos_validity(infos3, "cy"));
	cr_assert(ft_check_infos_validity(infos4, "cy"));

	ft_free_array(infos0);
	ft_free_array(infos1);
	ft_free_array(infos2);
	ft_free_array(infos3);
	ft_free_array(infos4);
}

Test(parsing, cy_bad_infos)
{
	char **cy_bad0 = ft_split("0 0 0  -1 -03 -0003	14.2   21.42  255 255 255", "	, ");
	char **cy_bad1 = ft_split("0 0 0  -1.3,1,1	14.2 21.42  255 255 255", "	, ");
	char **cy_bad2 = ft_split("0 0 0  0255 +255 +00255 14.2  21.42  255 255 255", "	, ");
	char **cy_bad3 = ft_split("0 0 0  1 0 0  -0000.0001 21.42  255 255 255", "	 ");
	char **cy_bad4 = ft_split("0 0 0  1,1,1  14.2  -03  255 255 255", ", ");
	char **cy_bad5 = ft_split("0 0 0  1,1,1  14.2  21.42  -255 -255 -255", "	 ");
	char **cy_bad6 = ft_split("0 0 0  1,1,1  14.2  21.42  255 255255 255", ", ");
	char **cy_bad7 = ft_split("0 0 0  1,1,1  14.2  21.42  0 0 -2553", "	, ");

	cr_assert(!ft_check_infos_validity(cy_bad0, "cy"));
	cr_assert(!ft_check_infos_validity(cy_bad1, "cy"));
	cr_assert(!ft_check_infos_validity(cy_bad2, "cy"));
	cr_assert(!ft_check_infos_validity(cy_bad3, "cy"));
	cr_assert(!ft_check_infos_validity(cy_bad4, "cy"));
	cr_assert(!ft_check_infos_validity(cy_bad5, "cy"));
	cr_assert(!ft_check_infos_validity(cy_bad6, "cy"));
	cr_assert(!ft_check_infos_validity(cy_bad7, "cy"));

	ft_free_array(cy_bad0);
	ft_free_array(cy_bad1);
	ft_free_array(cy_bad2);
	ft_free_array(cy_bad3);
	ft_free_array(cy_bad4);
	ft_free_array(cy_bad5);
	ft_free_array(cy_bad6);
	ft_free_array(cy_bad7);
}
