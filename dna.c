#include <stdio.h>

#include "dna.h"


void load_string(FILE *file, int *p, char *s, int t) {
    if (fscanf(file, "%d", p) != 1) {
        fprintf(stderr, "erro ao ler string do teste %d\n", t);
    }

    char c;
    do {
        c = getc(file);
    } while (c != '\n');

    fgets(s, *p + 1, file);
}


int mlcs_w(char a[], int n, char b[], int m, int length[MAX_SIZE+1][MAX_SIZE+1]) {
    if ((n==0) || (m==0)){
        length[n][m]=0;
        return 0;
    }
    if (a[n-1]==b[m-1]){
        length[n][m]=mlcs_w(a,n-1,b,m-1,length)+1;
    }else{
        int i=mlcs_w(a, n-1, b, m, length);
        int x=mlcs_w(a, n, b, m-1, length);
        if (i>x){
            length[n][m]=i;
        }else{
            length[n][m]=x;
        }
    }
    return length[n][m];


    // if ((n==0) || (m==0)){
    //     length[n][m]=0;
    //     return 0;
    // }
    // if (a[n-1]==b[m-1]){
    //     length[n][m]=length[n-1][m-1]+1;
    // }else{
    //     if ((length[n-1][m])>(length[n][m-1])){
    //         length[n][m]=length[n-1][m];
    //     }else{
    //         length[n][m]=length[n][m-1];
    //     }
    // }
    // return length[n][m];
}


int mlcs(char a[], int n, char b[], int m) {
    int length[MAX_SIZE+1][MAX_SIZE+1];
    for (int i=0; i<n+1; i++){
        for (int j=0; j<m+1; j++){
            length[i][j]=-1;
        }
    }
    mlcs_w(a,n,b,m,length);
    // for (int i=0; i<MAX_SIZE+1; i++){
    //     for (int j=0; j<MAX_SIZE+1; j++){
    //         mlcs_w(a,n,b,m,length);
    //     }
    // }
    return length[n][m];
}


int dlcs(char a[], int n, char b[], int m) {
    return 2;
}
