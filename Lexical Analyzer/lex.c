#include<stdio.h>
#include<string.h>
#include<ctype.h>

int isKeyword(char *word)
{
int i;
char *keyword[8]={"int","char","float","void","for","if","while","else"};
for(i=0;i<8;i++)
{
if(strcmp(word,keyword[i])==0){
return 1;
}
}
return 0;
}


int main()
{
FILE *fp;
char line[100], word[100];
char identifier[100][100];
int line_counter=0, i, j, word_counter;
int keyword_counter=0;
int number_counter=0;
int special_counter=0;
int identifier_counter=0;
char nums[100];
char symbols[100];
int num = 0, sym = 0;
fp=fopen("code.txt","r");
if(fp==NULL)
{
printf("file not opening...");
return 0;
}
while(fgets(line,100,fp))
{
line_counter++;
i=0;
word_counter=0;
while(line[i])
{
j=0;
if(line[i]!=' ' && line[i]!='\0' && line[i]!='\n')
{
while(line[i]!=' ' && line[i]!='\0' && line[i]!='\n')
{
word[j++]=line[i++];
}
word[j]='\0';
word_counter++;
if(isKeyword(word)){
keyword_counter++;
printf("%s is a keyword\n",word);
}
else if(isalpha(word[0])){
strcpy(identifier[identifier_counter++],word);
printf("%s is an identifier\n",word);
}
else if(isdigit(word[0])){
number_counter++;
nums[num++] = word[0];
nums[num++] = ' ';
}
else
{
special_counter++;
symbols[sym++] = word[0];
}
}
i++;
}
}
symbols[sym] = '\0';
nums[num] = '\0';
printf("Special Symbols: %s\n", symbols);
printf("Numbers are: %s\n", nums);
printf("total lines in the code:%d\n",line_counter);
printf("total keywords in the code:%d\n",keyword_counter);
printf("total identifiers in the code:%d\n",identifier_counter);
printf("total special character in the code:%d\n",special_counter);
printf("total numbers in the code:%d\n",number_counter);

fclose(fp);
return 0;
}
