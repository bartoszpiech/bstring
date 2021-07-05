#ifndef BSTRING_H
#define BSTRING_H

#ifdef __cplusplus
extern "C" {
#endif

typedef struct {
	char *data;
	int len;
} bstring_t;

/* init -- destroy */
/* new -- delete */

int bstring_init(bstring_t *str, const char *text, const int len);
bstring_t *bstring_new(const char *text, const int len);
void bstring_destroy(bstring_t *str);
void bstring_delete(bstring_t *str);


bstring_t *bstring_copyb(const bstring_t *str);
bstring_t *bstring_copys(bstring_t *str, const char *text, const int len);
bstring_t *bstring_catb(bstring_t *str1, const bstring_t *str2);
bstring_t *bstring_cats(bstring_t *str1, const char *str2);
bstring_t *bstring_mul(bstring_t *str, const int times);

int bstring_find(const bstring_t *str, const char *text);
int bstring_count(const bstring_t *str, const char ch);
bstring_t *bstring_slice(bstring_t *str, const int beg, const int end);
bstring_t *bstring_replace(bstring_t *str,
		const char *oldval, const char *newval);

void bstring_print(const bstring_t *str);

#ifdef __cplusplus
}
#endif

#endif
