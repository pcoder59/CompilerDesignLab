#include<stdio.h>
#include<ctype.h>
#include<string.h>
char expression[100];
int count=0, flag = 0;
void E();
void T();
void Eprime();
void check();
void Tprime();

int main() {
    
    printf("Enter an Expression: ");
    scanf("%s", expression);
    E();
    if ((strlen(expression)==count)&&(flag==0))
    {
        printf("valid");
    }
    else
    {
        printf("not valid");
    }
}

void E() {
    T();
    Eprime();
}

void T() {
    check();
    Tprime();
}

void check()
{
    if(isalnum(expression[count]))
    {
        count++;
    }
    else if(expression[count]=='(')
    {
        count++;
        E();
        if(expression[count]==')')
        {
            count++;
        }
        else
        {
            flag=1;
        }
    }
    else
    {
        flag=1;
    }
}

void Eprime()
{
    if(expression[count]=='+')
    {
        count++;
        T();
        Eprime();
    }
}
void Tprime()
{
    if(expression[count]=='*')
    {
        count++;
        check();
        Tprime();
    }
}
