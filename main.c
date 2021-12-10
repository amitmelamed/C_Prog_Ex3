//
// Created by 97252 on 10/12/2021.
//
#include <stdio.h>
#define TXT 1024
#define WORD 30
int main() {
    // printf() displays the string inside quotation
    printf("enter word and then sentence ");

    char name[WORD];
    char sentence[TXT];

    scanf("%s\n",name);
    scanf("%s",sentence);
    int nameGeometricValue=0;
    for(int i=0;i<sizeof (name);i++){
        nameGeometricValue=nameGeometricValue+name[i];
    }
    printf("the value of:%s is:%d\n",name,nameGeometricValue);
    return 0;
}