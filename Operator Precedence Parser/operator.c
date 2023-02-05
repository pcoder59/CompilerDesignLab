#include<stdio.h>
#include<string.h>
int main() {
    int n, i, j, row, col;
    printf("Enter number of terminals: ");
    scanf("%d", &n);
    char ter[n], opt[n][n], temp, stack[20], top = 0, ip[20];
    printf("Enter the terminals: ");
    scanf("%s", ter);
    scanf("%c", &temp);
    printf("Enter the precedence of operators:\n");
    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            printf("Enter precedence of %c %c: ", ter[i], ter[j]);
            scanf("%c", &opt[i][j]);
            scanf("%c", &temp);
        }
    }
    printf("Operator precedence table:\n");
    for(i = 0; i < n; i++) {
        printf("\t%c\t", ter[i]);
    }
    printf("\n");
    for(i = 0; i < n; i++) {
        printf("%c\t", ter[i]);
        for(j = 0; j < n; j++) {
            printf("%c\t\t", opt[i][j]);
        }
        printf("\n");
    }
    stack[top] = '$';
    printf("Enter Input String (append with $): ");
    scanf("%s", ip);
    i = 0;
    printf("STACK\tINPUT STRING\tACTION\n");
    printf("%s\t%s\t", stack, ip);
    while(i <= strlen(ip)) {
        for(j = 0; j < n; j++) {
            if(stack[top] == ter[j]) {
                row = j;
            }
            if(ip[i] == ter[j]) {
                col = j;
            }
        }
        if(stack[top] == '$' && ip[i] == '$') {
            printf("\nString is Accepted!\n");
            break;
        } else if(opt[row][col] == '<' || opt[row][col] == '=') {
            stack[++top] = opt[row][col];
            stack[++top] = ip[i];
            printf("Shift %c\n", ip[i]);
            i++;
        } else {
            if(opt[row][col] == '>') {
                while(stack[top] != '<') {
                    --top;
                }
                top = top - 1;
                printf("Reduce\n");
            } else {
                printf("\nString is not accepted!\n");
                break;
            }
        }
        printf("%s\t%s\t", stack, ip);
    }
    return 0;
}
