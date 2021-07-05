#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

#include "bstring.h"
/* OK */
/* malloc free strlen memcpy snprintf */

/* NOT OK */
/* strcpy strncpy strcat strncat */


int bstring_init(bstring_t *str, const char *text, const int len) {
	str->len = len;
	if ((str->data = malloc(str->len)) == NULL) {
		return 1;
	}
	for (int i = 0; i < str->len; i++) {
		str->data[i] = text[i];
	}
	return 0;
}

bstring_t *bstring_new(const char *text, const int len) {
	bstring_t *str;
	if ((str = malloc(sizeof(bstring_t))) == NULL) {
		fprintf(stderr, "Error: could not allocate space for bstring\n");
		exit(1);
	}
	if (bstring_init(str, text, len)) {
		fprintf(stderr, "Error: could not allocate space for bstring data\n");
		exit(1);
	}
	return str;
}

void bstring_destroy(bstring_t *str) {
	free(str->data);
}

void bstring_delete(bstring_t *str) {
	bstring_destroy(str);
	free(str);
}

bstring_t *bstring_copys(bstring_t *str, const char *text, const int len) {
	bstring_destroy(str);
	if (bstring_init(str, text, len)) {
		fprintf(stderr, "Error: could not allocate space for bstring data\n");
		exit(1);
	}
	return str;
}

bstring_t *bstring_copyb(const bstring_t *str) {
	return bstring_new(str->data, str->len);
}

bstring_t *bstring_catb(bstring_t *str1, const bstring_t *str2) {
	int str1_len = str1->len;
	int str2_len = str2->len;
	str1->len += str2->len;
	str1->data = realloc(str1->data, str1->len);
	for (int i = 0; i < str2_len; i++) {
		str1->data[i + str1_len] = str2->data[i];
	}
	return str1;
}

bstring_t *bstring_cats(bstring_t *str1, const char *str2) {
	int str1_len = str1->len;
	int str2_len = 0;
	while (str2[str2_len] != 0) {
		str2_len++;
	}
	str1->len += str2_len;
	str1->data = realloc(str1->data, str1->len);
	for (int i = 0; i < str2_len; i++) {
		str1->data[i + str1_len] = str2[i];
	}
	return str1;
}

bstring_t *bstring_mul(bstring_t *str, const int times) {
	bstring_t *helper = bstring_copyb(str);
	for (int i = 0; i < times - 1; i++) {
		bstring_catb(str, helper);
	}
	bstring_delete(helper);
	return str;
}

int bstring_find(const bstring_t *str, const char *text) {
	int text_len = 0;
	for (int i = 0; text[i] != 0; i++) {
		text_len++;
	}
	for (int i = 0; i < str->len; i++) {
		for (int j = 0; j < text_len; j++) {
			if (str->data[i+j] != text[j]) {
				break;
			} else if (j == text_len - 1) {
				return i;
			}
		}
	}
	return -1;
}

int bstring_count(const bstring_t *str, const char ch) {
	int count = 0;
	for (int i = 0; i < str->len; i++) {
		if (str->data[i] == ch) {
			count++;
		}
	}
	return count;
}

bstring_t *bstring_slice(bstring_t *str, int beg, int end) {
	if (end == -1) {
		end = str->len;
	}
	int cap = end - beg;
	bstring_t *helper = bstring_new(" ", cap);
	for (int i = beg; i < end; i++) {
		helper->data[i-beg] = str->data[i];
	}
	bstring_copys(str, helper->data, helper->len);
	bstring_delete(helper);
	return str;
}

bstring_t *bstring_replace(bstring_t *str,
		const char *oldval, const char *newval) {
	bstring_t *helper = bstring_copyb(str);
	int index = bstring_find(helper, oldval);
	return str;
}
	

void bstring_print(const bstring_t *str) {
	printf("[%d - \"%.*s\"]", str->len, str->len, str->data);
	//printf("[%d - \"%s\"]\n", str->len, str->data);
}
