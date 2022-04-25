/******************************************************************************

*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
void buildPunched(int r, int c) 
{
    int _r, _c, i, j;
    for (_r=0; _r<r; _r++) {
        if (_r == 0) {
            printf("..+");
            for (_c=1; _c<c; _c++) {
                printf("-+");
            }
            printf("\n");
            printf(".");
            for (_c=0;_c<c;_c++) {
                printf(".|");
            }
            printf("\n");
            printf("+");
            for (_c=0;_c<c; _c++) {
                printf("-+");
            }
            printf("\n");
        } else {
            printf("|");
            for (_c=0; _c<c; _c++) {
                printf(".|");
            }
            printf("\n");
            printf("+");
            for (_c=0; _c<c; _c++) {
                printf("-+");
            }
            printf("\n");
        }
    }
}
int main()
{
    int T = 0, i=0;
    typedef struct { int R, C;} ROW_COL;
    ROW_COL *pRowCols, *pIter;
    scanf("%d", &T);
    
    pRowCols = (ROW_COL*)calloc(sizeof(ROW_COL),T);
    pIter = pRowCols;
    for (; i<T; i++) {
        pIter = pRowCols+i;
        scanf("%d %d", &(pIter->R), &(pIter->C));
    }
    
    printf("Test Cases>> %d\n",T);
    for (i=0; i<T; i++) {
        pIter = pRowCols + i;
        printf("%d %d\n", pIter->R, pIter->C);
        buildPunched(pIter->R, pIter->C);
    }
    pIter = NULL;
    free(pRowCols);
    return 0;
}

