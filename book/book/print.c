#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
test_scanf() {
	int day, year;
	char monthname[20];
	scanf("%d %s %d", &day, monthname, &year);
	printf("%d %s %d\n", day, monthname, year);
}
test_print() {
	printf("sfdsdfsdfsd");
	printf("\n");
	printf("sdfd%%afdasfd");	//遇到字符串中有单纯意义上的% ， 则用%%替代
	printf("\n");
	printf("sdfd*sdfsdf");
	printf("\n");
	printf("%d\n", strlen("\t\"\065\xff\n"));
	char str[] = "ab\n\012\\\"";
	printf("%d\n", strlen(str));
	char *s = str;
	printf("%d\n", strlen(s));
}

test_sprint() {
	char s[64] = {0};
	sprintf(s,"%s","ni shi sha bi ye bao cuo a ");
	printf("%s\n",s);
}