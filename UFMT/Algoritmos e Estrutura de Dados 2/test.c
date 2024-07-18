#include <stdio.h>

int main() {
/*    
int a, b, sum;
printf("Enter two numbers: ");
scanf("%d %d", &a, &b);
sum = a + b;
printf("Sum: %d\n", sum);

//Estrutura de decisao
if (a > b) {
printf("a is greater than b\n");
} else {
printf("a is not greater than b\n");
}
*/
/*
//Estrutura de repeticao
for (int i = 0; i < 10; i++) {
printf("%d ", i);
}
*/


/*
int matrix[3][3] = {
{1, 2, 3},
{4, 5, 6},
{7, 8, 9}
};
*/

/*
int arr[11];
//Imprimindo vetor
for (int i = 0; i < 10; i++) {
    arr[i]=i;   
    printf("%d ", arr[i]);
}
*/

int mat[4][4];
//Imprimindo matrix
for (int i = 0, j = 0 ; i < 4 ; j++ ) {    
    printf("%d ", mat[i][j]);
    for (j; j < 4; j++) {
        printf("%d ", mat[i][j]);
        mat[i][j]=i+j;
    }   
}



return 0;
}