#ifndef BSTRING_H
#define BSTRING_H

#ifdef __cplusplus
extern "C" {
#endif

typedef struct {
	char *data;
	int len;
} bstring_t, *bstring;

/* init -- destroy */
/* new -- delete */
int bstring_init(bstring str, const char *text);
bstring bstring_new(const char *text);
void bstring_destroy(bstring str);
void bstring_delete(bstring str);

bstring bstring_copy(bstring str);
bstring bstring_cat(bstring str1, bstring str2);
bstring bstring_mul(bstring str, int times);

int bstring_find(bstring str, const char *text);
int bstring_count(bstring str, const char ch);


#ifdef __cplusplus
}
#endif

#endif
