#include<stdio.h>
/*华氏温度转摄氏温度*/
#define LOWER 0
#define UPPER 300
#define STEP 20
fahr2cels() {
	float fahr, celsius;

	printf("华氏温度转换摄氏温度\n");
	printf("%6s\t%6s\n", "华氏(F)", "摄氏(C)");
	/*while (fahr <= upper) {
		celsius = 5 * (fahr - 32) / 9.0;
		printf("%6.0f\t%6.1f\n", fahr, celsius);
		fahr = fahr + step;
	}*/
	for (fahr = LOWER; fahr <= UPPER; fahr += STEP) {
		celsius = 5 * (fahr - 32) / 9.0;
		printf("%6.0f\t%6.1f\n", fahr, celsius);
	}
}