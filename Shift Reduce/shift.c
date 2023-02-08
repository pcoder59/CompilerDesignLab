#include<stdio.h>
#include<string.h>
#include<stdlib.h>

char ip_sym[15], temp[2], act[15], temp2[2], stack[15];
int ip_ptr = 0, st_ptr = 0, len, i, flag;

void check() {
    flag = 0;
    temp2[0] = stack[st_ptr];
    temp2[1] = '\0';
    if(!strcmp(temp2, "a") || !strcmp(temp2, "b")) {
        stack[st_ptr] = 'E';
        if(!strcmp(temp2, "a")) {
            printf("$%s\t%s$\tE->a\n", stack, ip_sym);
        } else {
            printf("$%s\t%s$\tE->b\n", stack, ip_sym);
        }
        flag = 1;
    }
    if(!strcmp(temp2, "+") || !strcmp(temp2, "*") || !strcmp(temp2, "/")) {
        flag = 1;
    }
    if(!strcmp(stack, "E+E") || !strcmp(stack, "E/E") || !strcmp(stack, "E*E")) {
        strcpy(stack, "E");
        st_ptr = 0;
        if(!strcmp(temp2, "E+E")) {
            printf("$%s\t%s$\tE->E+E\n", stack, ip_sym);
        } else if(!strcmp(temp2, "E/E")) {
            printf("$%s\t%s$\tE->E/E\n", stack, ip_sym);
        } else {
            printf("$%s\t%s$\tE->E*E\n", stack, ip_sym);
        }
        flag = 1;
    }
    if(!strcmp(stack, "E") && ip_ptr == len) {
        printf("$%s\t%s$\tACCEPT\n", stack, ip_sym);
        exit(0);
    }
    if(flag == 0) {
        printf("$%s\t%s$\tREJECT\n", stack, ip_sym);
        exit(0);
    }
}

int main() {
    printf("GRAMMER\n");
    printf("E->E+E\nE->E/E\nE->E*E\nE->a/b\n");
    printf("\nEnter the input string: ");
    scanf("%s", ip_sym);
    printf("Stack Implementation Table:\n");
    printf("Stack\tInput Symbol\tAction\n");
    printf("$\t%s$\t\n", ip_sym);
    strcpy(act, "Shift ");
    temp[0] = ip_sym[ip_ptr];
    temp[1] = '\0';
    strcat(act, temp);
    len = strlen(ip_sym);
    for(i = 0; i < len; i++) {
        stack[st_ptr] = ip_sym[ip_ptr];
        stack[st_ptr+1] = '\0';
        ip_sym[ip_ptr] = ' ';
        ip_ptr++;
        printf("$%s\t%s$\t%s\n", stack, ip_sym, act);
        strcpy(act, "Shift ");
        temp[0] = ip_sym[ip_ptr];
        temp[1] = '\0';
        strcat(act, temp);
        check();
        st_ptr++;
    }
    st_ptr++;
    check();
    return 0;
}
