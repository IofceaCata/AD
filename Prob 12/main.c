///\file main.c
///\brief Encrypting and decrypting a message
///
/// Created by Iofcea Albert Catalin  on 20/5/18

#include<stdio.h>
#include<time.h>
#include<string.h>

#include "primrandom.h"
#include "notprimrandom.h"
#include "isprim.h"
#include "random.h"
#include "randompoz.h"
#include "litererandom.h"
#include "verif_prim.h"



int nr_sir;
///\var int nr_sir
///\brief Iterator

int z;
///\var int z;
///\brief Iterator used for frequency vector


int fr[1000000];
///\var int fr[1000000];
///\brief frequency vector who contains only 0 and 1

char a[1000000];
///\var char a[1000000];
///\brief Vector where the initial message is stored


char cript[1000000];
///\var char cript[1000000];
///\brief Vector where the cripted message is stored

char decript[1000000];
///\var char decript[1000000];
///\brief Vector where the decripted message is stored

int power=10;
///\var int power=10;
///\brief Variable who sets how complicated the cripted message will be

///\fn void adaugare_nonrelevant()
void adaugare_nonrelevant(){
    ///\brief Function used to add nonrelevant letters to cod

    int i;
    ///\brief int i  - Iterator
    int j;
    ///\brief int j  - Iterator
    int nr_nonrelevant=random(power);
    ///\brief int nr_nonrelevant   - random generated number of nonrelevant letter
    int poz_random;
    ///\brief int  - random pozition of a letter
    for(i=0;i<nr_nonrelevant;i++){

        poz_random=randompoz(strlen(a));

        char litera=litererandom();

        for(j=strlen(a);j>poz_random;j--){
            if(a[j+1]==a[j])
                litera=litererandom();
            a[j+1]=a[j];
            fr[j+1]=fr[j];
        }
        a[poz_random+1]=litera;
        fr[poz_random+1]=1;
    }
    nr_sir=strlen(a);
}
///\fn void criptare()
void criptare(){
    ///\brief Function used to cript the cod


    int i;
    ///\brief int i  - Iterator
    int j;
    ///\brief int j  - Iterator
    int nr_relevant;
    ///\brief int nr_relevant  - variable used for storing the prim number of appearances of the relevant letter
    int nr_notrelevant;
    ///\brief int nr_notrelevant  - variable used for storing the nonprim number of appearances of the nonrelevant letter
    int nrcript=0;
    ///\brief int nrcript  - variable used for storing the lenght of the cripted vector


    for(j=0;j<nr_sir;j++){

        if(fr[j]==0){
            nr_relevant=primrandom();


            for(i=nrcript ; i < nrcript+nr_relevant ; i++)////////
                cript[i]=a[j];

            nrcript=nrcript+nr_relevant;
        }

        if(fr[j]==1){
            nr_notrelevant=notprimrandom();


            for(i=nrcript ;  i<nrcript+nr_notrelevant  ;  i++)
                cript[i]=a[j];
            nrcript=nrcript+nr_notrelevant;
        }

    }
}
///\fn void decriptare()
void decriptare(){

    ///\brief Function used to decript the cod
    int i;
    ///\brief int i  - Iterator
    int nr=1;
    ///\brief int nr  - Counter

    for(i=0;i<strlen(cript);i++){

        if(cript[i]==cript[i+1]){
            nr++;
        }
        else{
            if(verif_prim(nr)==1)
                decript[++z]=cript[i];
            nr=1;
        }
    }

}
///\fn int main()
int main(){
    ///\brief Main function.

    FILE *fp;
    fp = fopen("prob12.txt", "w+");

    int i;
    ///\brief int i  - Iterator
    int choice=5;
    ///\brief int choice  - Variable used to select options
    int ok1=0;
    int ok2=0;


    srand(time(NULL));
    printf("Set the power of the algorithm . Recommended between 10 and 40 . Go over at you'r own risk :) ");
    scanf("%d",&power);

    printf("Pentru a introduce mesajul de criptat selectati 1 \nPentru a cripta mesajul selectati 2 \nPentru a decripta mesajul apasati 3\nPentru a decripta mesajul apasati 4\n"); // MENU
    while(choice!=4){
        scanf("%d",&choice);
        if(choice==1){
            for(i=0;i<=1000000;i++){
                a[i]='\0';
                cript[i]='\0';
                decript[i]='0';
                fr[i]='\0';
            }
            scanf("%[^\n]s",&a);
            ok1=1;
            ok2=0;

        }
        else
        if(choice==2){
            if(ok1==0)
                printf("ERROR\n");
            else{
                adaugare_nonrelevant();
                criptare();
                printf("%s \n",cript);
                fputs(cript, fp);
                ok2=1;
                ok1=0;
            }
        }
        else
        if(choice==3){
            if(ok2==0)
                printf("ERROR\n");
            else{
                decriptare();
                for(i=1;i<=z;i++)
                    if(decript[i]!='0')
                        printf("%c",decript[i]);
                printf("\n");
                ok1=0;
                ok2=0;
            }
        }
    }
}
