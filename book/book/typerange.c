#include<stdio.h>
#include<limits.h>
#include<math.h>

type_range() {
	printf("char range: %d ~ %d .\n",
		CHAR_MIN, CHAR_MAX);

	double short_exponent = ceil(log(SHRT_MAX) / log(2));
	printf("short range: %d ~ %d, ¼´ -2^%0.0lf ~ 2^%0.0lf-1 .\n", 
		SHRT_MIN, SHRT_MAX, short_exponent, short_exponent);
	printf("unsignded short range: 0 ~ %d, ¼´ 0 ~ 2^%0.0lf-1 \n.",
		USHRT_MAX, ceil(log(USHRT_MAX) / log(2)));

	double int_exponent = ceil(log(INT_MAX) / log(2));
	printf("int range: %d ~ %d, ¼´ -2^%0.0lf ~ 2^%0.0lf-1 .\n",
		INT_MIN, INT_MAX, int_exponent, int_exponent);
	printf("unsignded int range: 0 ~ %d, ¼´ 0 ~ 2^%0.0lf-1 \n.",
		UINT_MAX, ceil(log(UINT_MAX) / log(2)));

	double long_exponent = ceil(log(LONG_MAX) / log(2));
	printf("long range: %d ~ %d, ¼´ -2^%0.lf ~ 2^%0.0lf-1 .\n",
		LONG_MIN, LONG_MAX, long_exponent, long_exponent);
	printf("unsignded long range: 0 ~ %d, ¼´ 0 ~ 2^%0.0lf-1 \n.",
		ULONG_MAX, ceil(log(ULONG_MAX) / log(2)));

}