#include<stdio.h>
#include<string.h>
int main() {
    FILE *fp1, *fp2;
    char op[2], arg1[5], arg2[5], result[5];
    fp1 = fopen("input.txt", "r");
    fp2 = fopen("output.txt", "w");
    while(!feof(fp1)) {
        fscanf(fp1, "%s%s%s%s", op, arg1, arg2, result);
        if(strcmp(op, "+") == 0) {
            fprintf(fp2, "MOV R0, %s\n", arg1);
            fprintf(fp2, "ADD R0, %s\n", arg2);
            fprintf(fp2, "MOV %s, R0\n", result);
        } else if(strcmp(op, "*") == 0) {
            fprintf(fp2, "MOV R0, %s\n", arg1);
            fprintf(fp2, "MUL R0, %s\n", arg2);
            fprintf(fp2, "MOV %s, R0\n", result);
        } else if(strcmp(op, "/") == 0) {
            fprintf(fp2, "MOV R0, %s\n", arg1);
            fprintf(fp2, "DIV R0, %s\n", arg2);
            fprintf(fp2, "MOV %s, R0\n", result);
        } else if(strcmp(op, "-") == 0) {
            fprintf(fp2, "MOV R0, %s\n", arg1);
            fprintf(fp2, "SUB R0, %s\n", arg2);
            fprintf(fp2, "MOV %s, R0\n", result);
        } else if(strcmp(op, "=") == 0) {
            fprintf(fp2, "MOV R0, %s\n", arg1);
            fprintf(fp2, "MOV %s, R0\n", result);
        }
    }
    fclose(fp1);
    fclose(fp2);
}
