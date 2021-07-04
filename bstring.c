#include <stdio.h>
#include <stdlib.h>

#include "bstring.h"
/* OK */
/* malloc free strlen memcpy snprintf */

/* NOT OK */
/* strcpy strncpy strcat strncat */

int bstring_init(bstring str, const char *text) {
	str->len= 0;
	for (int i = 0; text[i] != 0; i++) {
		str->len++;
	}
	if ((str->data = malloc(str->len)) == NULL) {
		return 1;
	}
	for (int i = 0; i < str->len; i++) {
		str->data[i] = text[i];
	}
	return 0;
}
bstring bstring_new(const char *text) {
	bstring str;
	if ((str = malloc(sizeof(bstring_t))) == NULL) {
		fprintf(stderr, "Error: could not allocate space for bstring\n");
		exit(1);
	}
	if (bstring_init(str, text)) {
		fprintf(stderr, "Error: could not allocate space for bstring\n");
		exit(1);
	}
	return str;
}

void bstring_destroy(bstring str) {
	free(str->data);
}

void bstring_delete(bstring str) {
	bstring_destroy(str);
	free(str);
}

bstring bstring_copy(bstring str) {
	return bstring_new(str->data);
}

bstring bstring_cat(bstring str1, bstring str2) {
	bstring result = bstring_copy(str1);
	result->len += str2->len;
	result->data = realloc(result->data, result->len);
	for (int i = str1->len; i < result->len; i++) {
		result->data[i] = str2->data[i - str1->len];
	}
	return result;
}

int bstring_find(bstring str, const char *text) {
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

int bstring_count(bstring str, const char ch) {
	int count = 0;
	for (int i = 0; i < str->len; i++) {
		if (str->data[i] == ch) {
			count++;
		}
	}
	return count;
}
