#include<stdio.h>
#include<ctype.h>

int n;
char prod[10][10];

void input() {
    int i;
    printf("Enter Number of Productions: ");
    scanf("%d", &n);
    printf("Enter Each Production:\n");
    for(i = 0; i < n; i++) {
        scanf("%s", prod[i]);
    }
}

void replace(char c, char num, int no) {
    int i, j;
    for(i = no + 1; i < n; i++) {
        j = 2;
        if(prod[i][0] == c) {
            break;
        }
        while(prod[i][j] != '\0') {
            if(prod[i][j] == c) {
                prod[i][j] = num;
                break;
            }
            j++;
        }
    }
}

void check() {
    int i;
    for(i = 0; i < n; i++) {
        if(isdigit(prod[i][2]) && prod[i][3] == '\0') {
            replace(prod[i][0], prod[i][2], i);
        }
    }
}

void display() {
    int i;
    printf("Optimized Code:\n");
    for(i = 0; i < n; i++) {
        printf("%s\n",prod[i]);
    }
}

int main() {
    input();
    check();
    display();
    return 0;
}