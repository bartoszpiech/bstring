#ifndef BSTRING_H
#define BSTRING_H

#ifdef __cplusplus
extern "C" {
#endif

typedef struct {
	char *data;
	int size;
} bstring_t, *bstring;

/* init -- destroy */
/* new -- delete */
int bstring_init(bstring str, const char *text);
bstring bstring_new(const char *text);
void bstring_destroy(bstring str);
void bstring_delete(bstring str);

#ifdef __cplusplus
}
#endif

#endif
