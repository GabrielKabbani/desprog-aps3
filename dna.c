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
        if (length[n-1][m-1]!=-1){
            length[n][m]=length[n-1][m-1]+1;
        }else{
            length[n][m]=mlcs_w(a,n-1,b,m-1,length)+1;
        }
    }else{
        int i;
        int x;
        if (length[n][m-1]!=-1){
            i=length[n][m-1];
        }else{
            i=mlcs_w(a, n, b, m-1, length);
        }
        if (length[n-1][m]!=-1){
            x=length[n-1][m];
        }else{
            x=mlcs_w(a, n-1, b, m, length);
        }
    
        if (i>x){
            length[n][m]=i;
        }else{
            length[n][m]=x;
        }
    }
    return length[n][m];
}


int mlcs(char a[], int n, char b[], int m) {
    int length[MAX_SIZE+1][MAX_SIZE+1];
    for (int i=0; i<n+1; i++){
        for (int j=0; j<m+1; j++){
            length[i][j]=-1;
        }
    }
    mlcs_w(a,n,b,m,length);
    return length[n][m];
}


int dlcs(char a[], int n, char b[], int m) {
    int length[n+1][m+1];
    for (int i=0; i<n+1; i++){
        for (int j=0; j<m+1; j++){
            length[i][j]=-1;
        }
    }
    for (int i=0; i<=n; i++){
        for (int j=0; j<=m; j++){
            if ((i==0) || (j==0)){
                length[i][j]=0;
            }
            else if (a[i-1]==b[j-1]){
                length[i][j]=length[i-1][j-1]+1;
            }else{
                int z=length[i-1][j];
                int x=length[i][j-1];
                if (z>x){
                    length[i][j]=z;
                }else{
                    length[i][j]=x;
                }
            }
        }
    }
    return length[n][m];

}
