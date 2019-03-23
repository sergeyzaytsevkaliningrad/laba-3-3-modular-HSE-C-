
//
//  main.c
//  3 laba
//
//  Created by Sergey on 26/02/2019.
//  Copyright © 2019 Sergey. All rights reserved.
//

#include <stdio.h>
#include <string.h>
#define MAXSTR 10
#define MAXLEN 81






void part1(int n, char str[][MAXLEN], char str1[][MAXLEN], int *n1, int num[])
{
    char *s, *s1;
    *n1 = 0;
    for (int i = 0; i < n; i++)
    {
        s = str[i];
        s1 = s;
        for (; *s; s++)
        {
            if (*(s-1) == '/' && *s == '*')
            {
                s1 = ++s;
                for (; *s && !(*s == '*' && *(s+1) == '/'); s++);
                if (s1 != s && *s == '*' && *(s+1) == '/')
                {
                    num[*n1] = i;
                    strncpy(str1[*n1], s1, s - s1);
                    str1[*n1][s-s1] = '\0';
                    (*n1)++;
                }
            }
        }
    }
}
void part2(char str1[][MAXLEN], int n1, int *maxstr)

{
    int max = 0;
    char *s;
    for (int i = 0; i < n1; i++) {
        s = str1[i];
        int k=0;
        while (*s)
        {
            if ((*s >= 'a' && *s <= 'z') || (*s >= 'A' && *s <= 'Z'))
            {
                ++k;
                //printf("%s", *s);
                //printf("max = %d", max);
                //printf("k = %d", k);
                //printf("\n");
                max = k;
                *maxstr = i;
            }
            s++;
        }
    }
}

void part3(int num[], int maxstr, char str[][MAXLEN], char str1[][MAXLEN], int n, char **flag)
{
    char *s; int i;
    for (i = 0; *flag == NULL && i < n; ++i)
        *flag = strstr(str[i], str1[maxstr]);
    if (**flag)
        for (s = str[i-1]; *s; ++s)
            switch (*s)
        {
            case 'A': *s = '0'; break;
            case 'B': *s = '1'; break;
            case 'C': *s = '2'; break;
            case 'D': *s = '3'; break;
            case 'E': *s = '4'; break;
            case 'F': *s = '5'; break;
            case 'G': *s = '6'; break;
            case 'H': *s = '7'; break;
            case 'I': *s = '8'; break;
            case 'J': *s = '9'; break;
        }
}
int changestr(char str1[][MAXLEN], int n1)
{char *s, *s1, *s2; int n ,f=0;
    for (int i=0; i<n1; ++i)
    {
    for (s = str1[i]; *s; s++)
        { for (s1=++s; isdigit(*s); s++);
            if (s1!=s) /*Замена цифровой подстроки */
            { n=*s1-'0'; /* Вычисляемое значение типа int */
                for (s2=s1; *s; *s2++=*s++); /* Удаление подстроки из
                                              цифр */ *s2='\0'; f=1;
            }
        }
    }
    puts("---------------------");
    for (int i = 0; i < n1; i++)
        puts(str1[i]);
    return f;
}

int main()
{
  
    char str[MAXSTR][MAXLEN], str1[MAXSTR+20][MAXLEN], *flag = NULL;
    int num[MAXSTR], n1, n = 0, maxstr = 0;
    puts("Input strings:");
    while (*gets(str[n]) && n < MAXSTR) n++;
    part1(n, str, str1, &n1, num);
    if (n1 == 0) puts ("No substrings.");
    else
    {
        puts("Substrings:");
        for (int i = 0; i < n1; i++)
            puts(str1[i]);
    }
    part2(str1, n1, &maxstr);
    if (maxstr != 0)
    {
        puts("The substring which starts with maximum number of letters has been found:");
        puts(str1[maxstr]);
        part3(num, maxstr, str, str1, n, &flag);
        puts("The matrix after executing part3:");
        for (int i = 0; i < n; ++i)
            puts(str[i]);
    }
    else puts("The substring hasn't been found.");
    
    changestr(str1, n1);
    
}

/*/*dsa*/
/*ABCdae*//*wqd/*DFWHWE*/
/*asdf*/
