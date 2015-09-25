#define max(a, b) ({ \
    typeof(a) __a = (a); \
    typeof(b) __b = (b); \
    (__a > __b) ? __a : __b; \
})


/***
 * use divide-and-conquer method, o(m*n), m, n: length of string.
 */
int 
findSubStr(char *sa, char *sb, int m, int n)
{
    int tbl[64][64] = {0};
    int result = 0;

    int i, j;

    for (i = 0; i <= m; i++) {
        for (j = 0; j <= n; j++) {
            if (i == 0 || j == 0) {
                tbl[i][j] = 0;
            }
            else if (sa[i-1] == sb[j-1]) {
                tbl[i][j] = tbl[i-1][j-1] + 1;
                result = max(result, tbl[i][j]);
            }
            else {
                tbl[i][j] = 0;
            }
        }
    }
    return result;
}
