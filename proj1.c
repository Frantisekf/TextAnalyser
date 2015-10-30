#include<stdio.h>


int main(int argc, char* argv[]){

    printf("cislo %d", 10);



    return 0;

}




int detect_number(){

    int number;
    if(scanf("%d",&number) == 1){
        return 1;
    }else {
        return 0;
    }

}