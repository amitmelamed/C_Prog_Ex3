//
// Created by 97252 on 10/12/2021.
//
#include <stdio.h>
#include <string.h>
#define TXT 1024
#define WORD 30

void funcA(int nameGioValue,char * str){
    char output [TXT]={0};
    int outputIndexCount=0;
    int countGim;
    for(int i=0;i<strlen(str);i++){
        countGim=0;
        for(int k=i;k< strlen(str);k++){
            if(str[k]>=65&&str[k]<=90){
                countGim=countGim+str[k]-64;
            } else if(str[k]>=96 && str[k] <=122){
                countGim=countGim+str[k]-96;
            }
                if(countGim==nameGioValue && ((str[i]>=65 && str[i]<=90 )||(str[i]>=96 && str[i] <=122))){
                    for(int t=i;t<=k;t++){
                        output[outputIndexCount]=str[t];
                        outputIndexCount++;
                    }
                    output[outputIndexCount]='~';
                    outputIndexCount++;
                    break;
                }
        }
    }
    output[strlen(output)-1]='\0';
    printf("Gematria Sequences: %s\n",output);

}
void funcB(char* name,char* atbashSentence){

    //make atbach name from name
    char atbashName [WORD]={0};
    for(int i=0;i< strlen(name);i++){
        if(name[i]>=65&&name[i]<=90)
        {
            int charAbs=name[i]-65;
            atbashName[i]=90-charAbs;

        }else if(name[i]>=96 && name[i] <=122)
        {
            int charAbs=name[i]-96;
            atbashName[i]=123-charAbs;
        }

    }
    //make atbash opposite
    char atbashNameOpossite [WORD]={0};
    for(int i=0;i< strlen(atbashName);i++){
        atbashNameOpossite[strlen(atbashName)-i-1]=atbashName[i];
    }
    char output [TXT] ={0};
    int outputIndex=0;
    for(int i=0;i< strlen(atbashSentence);i++){
        int flag=0;
        int spaces=0;
        for(int k=0;k< strlen(atbashName);k++){
            if(atbashSentence[i+k+spaces]!=atbashName[k]){
                if(atbashSentence[i+k+spaces]==' '||atbashSentence[i+k+spaces]=='\n'||atbashSentence[i+k+spaces]=='\t'){
                    spaces++;
                    k--;
                } else{
                    flag=1;
                }
            }
        }
        if(flag==0){
            for(int t=0;t< strlen(atbashName)+spaces;t++){
                output[t+outputIndex]=atbashSentence[i+t];
            }
            outputIndex=outputIndex+ strlen(atbashName);
            output[outputIndex]='~';
            outputIndex++;
        }

        flag=0;
        spaces=0;
        for(int k=0;k< strlen(atbashNameOpossite);k++){
            if(atbashSentence[i+k+spaces]!=atbashNameOpossite[k]){
                if(atbashSentence[i+k+spaces]==' '||atbashSentence[i+k+spaces]=='\n'||atbashSentence[i+k+spaces]=='\t'){
                    spaces++;
                    k--;
                } else{
                    flag=1;
                }
            }
        }
        if(flag==0){
            for(int t=0;t< strlen(atbashNameOpossite)+spaces;t++){
                output[t+outputIndex]=atbashSentence[i+t];
            }
            outputIndex=outputIndex+ strlen(atbashName);
            output[outputIndex]='~';
            outputIndex++;

        }

    }

    output[outputIndex-1]='\0';
    printf("Atbash Sequences: %s\n",output);
}
void funcC(char* name,char* sentence){

    //first we will count how many char is in the name and map them
    int values[256];

    for(int i = 0; i <256; ++i) {
        values[i]=0;
    }
    for(int i=0; i< strlen(name); i++){
        values[(int) name[i]]++;
    }


    char output[TXT]={0};
    int outputIndex=0;
    for(int i=0;i< strlen(sentence);i++){
        for(int k=i;k< strlen(sentence);k++){
            int currentArray[256];
            for(int i = 0; i <256; ++i) {
                currentArray[i]=0;
            }
            for(int t=i;t<=k;t++){
                currentArray[(int)sentence[t]]++;
            }
            int flag=0;
            for(int t=0;t<256;t++){
                if(currentArray[t]!=values[t] && t!= (int)' '){
                    flag=1;
                }
            }
            if(sentence[i]==' '|| sentence[k]== ' '){
                flag=1;
            }
            if(flag==0){
                for(int t=i;t<=k;t++){
                    output[outputIndex]=sentence[t];
                    outputIndex++;
                }
                output[outputIndex]='~';
                outputIndex++;
            }

        }
    }
    output[outputIndex-1]='\0';
    printf("Anagram Sequences: %s",output);







}


int main() {
    // printf() displays the string inside quotation
    char name[WORD]={0};
    char sentence[TXT]={0};

    scanf("%s\n",name);
    int nameGeometricValue=0;
    for(int i=0;i<sizeof(name)/sizeof(char);i++){
        if(name[i]>=65&&name[i]<=90){
            nameGeometricValue=nameGeometricValue+name[i]-64;
        } else if(name[i]>=96 && name[i] <=122){
            nameGeometricValue=nameGeometricValue+name[i]-96;
        }
    }
    char ch;
    int index=0;


    while (index<256){
        scanf("%c",&ch);
        if(ch=='~'){
            break;
        }
        sentence[index]=ch;
        index++;
    }
    funcA(nameGeometricValue,sentence);
    funcB(name,sentence);
    funcC(name,sentence);
    return 0;
}