#include<stdio.h>
#define NONBLANK '1'
#define NOWINWORD 1
#define NOWOUTWORD 0
count_words() {
	int nw = 0,
		c,
		state = NOWOUTWORD;
	while ((c = getchar()) != EOF) {
		if (('a' <= c && c <= 'z') || 'A' <= c && c <= 'Z' ) {
			state = NOWINWORD;
		}
		else if (c == '-' && state) {
			state = NOWINWORD;
		}
		else if ('0' <= c && c <= '9') {
			if (state) {
				if (state) {
					++nw;
				}
				state = NOWOUTWORD;
			}
			else {
				state = NOWINWORD;
			}
		}

		else {
			if (state) {
				++nw;
			}
			state = NOWOUTWORD;
		}

	}
	printf("单词数：%d\n", nw);
}

many_space_to_one() {
	int c,
		last_c = NONBLANK;
	while ((c = getchar()) != EOF) {
		if (c != ' ' || last_c != ' ') {
			putchar(c);
		}
		last_c = c;
	}
};
replace_character() {
	int c;
	while ((c = getchar()) != EOF) {
		if (c == '\n') {
			printf("\\n");
		}
		else if (c == '\t') {
			printf("\\t");
		}
		else if (c == '\b') {
			printf("\\b");
		}
		else if (c == '\\') {
			printf("\\\\");
		}
		else {
			putchar(c);
		}
	}
};
count_character() {
	int nc = 0,
		nl = 0,
		ns = 0,
		nt = 0,
		c;
	while ((c=getchar()) != EOF) {
		if (c == '\n')
			++nl;
		else if (c == ' ')
			++ns;
		else if (c == '\t')
			++nt;
		++nc;
	}
	printf("字符数：%4d\t行数：%4d\t空格数：%4d\t制表符数：%4d\n",nc,nl,ns,nt);
};