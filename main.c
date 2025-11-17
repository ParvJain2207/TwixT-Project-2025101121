#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

typedef struct {
    int r1, c1, r2, c2;
} Link;

int place(char arr[24][24], int x, int y,char str[]) {
    if (x < 0 || x >= 24 || y < 0 || y >= 24)
        return 0;
    if(strcmp(str,"RED")==0){
        if((x==0) && (0<y<=22) || (x==23) && (0<y<=22)){
            return 2;
        }
    }
    if(strcmp(str,"BLACK")==0){
        if((y==0) && (0<x<=22) || (y==23) && (0<x<=22)){
            return 3;
        }
    }
    if ((x==0 && y==0) || (x==23 && y==23) || (x==23 && y==0) || (x==0 && y==23))
        return 0;
    
    if (arr[y][x] != '.')
        return 0;

    return 1;
}

void mainscreen(char arr[24][24], char str[]);

void options(int x, char arr[24][24], char str[]) { 
    switch(x) {

        case 1: {
            int x1,y1;
            printf("Where do you want to place your peg? ( write in coordinate format x1 y1 , where (x1,y1)=(COLUMN,ROW))\n");
            scanf("%d %d",&x1,&y1);

            int l = place(arr,x1,y1,str);  

            if(l==1){
                if(strcmp(str,"RED")==0){
                    arr[y1][x1]='R';   
                    strcpy(str,"BLACK");
                    mainscreen(arr,str);
                }

                if(strcmp(str,"BLACK")==0){
                    arr[y1][x1]='B';   
                    strcpy(str,"RED");
                    mainscreen(arr,str);
                }

            } else {
                printf("Cant place the peg here ! Invalid move !\n");
                mainscreen(arr,str);    
            }

            break;  
        }

        case 2: {

    
            printf("The Rules:\n\n");
            printf("1. TwixT is played on a 24x24 board.\n");
            printf("   - RED connects TOP to BOTTOM.\n");
            printf("   - BLACK connects LEFT to RIGHT.\n\n");
            printf("2. Players alternate turns.\n");
            printf("   - RED always starts.\n");
            printf("   - A player may place a peg, add a link, or remove their own link.\n\n");
            printf("3. Pegs can be placed only on empty cells (not the 4 corners).\n\n");
            printf("4. Links are allowed only in a knight's move:\n");
            printf("   (+-2, +-1) or (+-1, +-2)\n");
            printf("   Links may NOT cross each other.\n\n");
            printf("5. RED wins by connecting TOP to BOTTOM.\n");
            printf("6. BLACK wins by connecting LEFT to RIGHT.\n\n");
            printf("7. A player may resign anytime.\n\n");
            printf("Enjoy playing TwixT!\n\n");
printf("Do you want to go back to the main screen ?(y/n)(else exit program and delete the current game)\n");
char o;
scanf(" %c",&o);
if(o=='y'){
mainscreen(arr,str);
break;
}
else{
    exit(0);
}
        
        }
case 3:{
    printf("Will be implemented in phase 2!\n");
    printf("Do you want to go back to the main screen ?(y/n)(else exit program and delete the current game)\n");
char p;
scanf(" %c",&p);
if(p=='y'){
mainscreen(arr,str);
break;
}
else
exit(0);}

case 4:{printf("Will be implemented in phase 2!\n");
    printf("Do you want to go back to the main screen ?(y/n)(else exit program and delete the current game)\n");
char b;
scanf(" %c",&b);
if(b=='y'){
mainscreen(arr,str);
break;}
else
exit(0);}

case 5:{printf("Will be implemented in phase 2!\n");
    printf("Do you want to go back to the main screen?(y/n)(else exit program and delete the current game)\n");
char c;
scanf(" %c",&c);
if(c=='y'){
mainscreen(arr,str);
break;}
else
exit(0);
}
 case 6:{
     exit(0);}
    }



}


void mainscreen(char arr[24][24], char str[]) {

    printf("\n  ");
    for (int i = 0; i < 24; i++) {
        printf("%2d ", i);  
    }
    printf("\n");

    for (int i = 0; i < 24; i++) {
        printf("%2d ", i); 
        for (int j = 0; j < 24; j++) {  
            printf("%c  ", arr[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    printf("Tell the function you want to perform !: \n");
    printf("CURRENT PLAYER= %s\n",str);
    printf("1.Place your next move!\n");
    printf("2.Show the Rules\n");
    printf("3.Show the links\n");
    printf("4.Resign and clear board!\n");
    printf("5.Delete a link\n");
    printf("6.Exit!\n");
    printf("TELL THE NUMBER: \n");

    int x;
    scanf("%d",&x);

    options(x,arr,str); 
}

int main(){
    char arr[24][24];
    for(int i=0;i<24;i++){
        for(int j=0;j<24;j++){
            arr[i][j]='.';
        }
    }

    char str[20];
    strcpy(str,"RED");

    mainscreen(arr,str);

    return 0;
}
