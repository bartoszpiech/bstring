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

bstring_t *bstring_copy(bstring_t *str) {
	return bstring_new(str->data, str->len);
}

bstring_t *bstring_cat(bstring_t *str1, bstring_t *str2) {
	int tmp = str1->len;
	str1->len += str2->len;
	str1->data = realloc(str1->data, str1->len);
	for (int i = 0; i < str2->len; i++) {
		str1->data[i + tmp] = str2->data[i];
	}
	return str1;
}

/*
bstring bstring_cat(bstring str1, bstring str2) {
	bstring result = malloc(sizeof(bstring_t));
	result->len = str1->len + str2->len;
	result->data = malloc(result->len);
	for (int i = 0; i < str1->len; i++) {
		result->data[i] = str1->data[i];
	}
	for (int i = str1->len; i < result->len; i++) {
		result->data[i] = str2->data[i - str1->len];
	}
	return result;
}
*/

bstring_t *bstring_mul(bstring_t *str, int times) {
	bstring_t *helper = bstring_copy(str);
	for (int i = 0; i < times - 1; i++) {
		bstring_cat(str, helper);
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

void bstring_print(const bstring_t *str) {
	printf("[%d - %.*s]", str->len, str->len, str->data);
}
