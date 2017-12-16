#include "fh.h"
#include <algorithm>
#include <climits>
#include <cstring>

static long long int middle(const Symbol* symbols, long long int l, long long int sum, long long int& lsum,long long int& rsum);

CodeTree* fanno_shannon(const Symbol* symbols,long long int l,long long int r,long long int sum)
{
	if (l >= r) return nullptr;
	if (r - l == 1) return make_leaf(symbols[l]);
    long long int lsum, rsum;
    long long int m = middle(symbols, l, sum, lsum, rsum);
	CodeTree* ltree = fanno_shannon(symbols, l, m + 1, lsum);
	CodeTree* rtree = fanno_shannon(symbols, m + 1, r, rsum);
	CodeTree* node = make_node(sum, ltree, rtree);
	ltree->parent = node;
	rtree->parent = node;
	return node;
}
CodeTree* fanno_shannon(const Symbol* symbols, long long int len)
{
    long long int sum = 0;
    for (long long int i = 0; i < len; ++i)
		sum += symbols[i].weight;
	return fanno_shannon(symbols, 0, len, sum);
}
CodeTree* fanno_shannon(const char* message)
{
	Symbol symbols[UCHAR_MAX];
    for (long long int i = 0; i < UCHAR_MAX; ++i) {
		symbols[i].c = i + CHAR_MIN;
		symbols[i].weight = 0;
	}
	int size = strlen(message);
    for (long long int i = 0; i < size; ++i)
		symbols[message[i] - CHAR_MIN].weight++;
	std::sort(symbols, symbols + UCHAR_MAX, symbol_greater);
    long long int len = 0;
	while (symbols[len].weight > 0 && len < UCHAR_MAX) len++;
	return fanno_shannon(symbols, len);
}
long long int middle(const Symbol* symbols, long long int l, long long int sum, long long int& lsum, long long int& rsum)
{
    long long int m = l;
	lsum = symbols[m].weight;
	rsum = sum - lsum;
    long long int delta = lsum - rsum;
	while (delta + symbols[m + 1].weight < 0) {
		m++;
		lsum += symbols[m].weight;
		rsum -= symbols[m].weight;
		delta = lsum - rsum;
	}
	return m;
}
