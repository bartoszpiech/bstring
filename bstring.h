#ifndef BSTRING_H
#define BSTRING_H

#ifdef __cplusplus
extern "C" {
#endif

typedef struct {
	char *data;
	int size;
} *bstring_t;

bstring_t bstring(const char *text);
void bstring_free(bstring_t str);

#ifdef __cplusplus
}
#endif

#endif
