///\file main.c
///\brief Encrypting and decrypting a message
///
/// Created by Iofcea Albert Catalin  on 20/5/18

#include<stdio.h> ///> printf()
#include<time.h> ///> srand(time(NULL))


#include "primrandom.h" ///> primrandom()
#include "notprimrandom.h" ///> notprimrandom()
#include "isprim.h" ///> isprim(int p);
#include "random.h" ///> random()
#include "randompoz.h" ///> randompoz(int strlena)
#include "litererandom.h" ///> litererandom()
#include "verif_prim.h" ///> verif_prim( int nr )

///Global Variables

int nr_sir; ///\var nr_sir iterator
int z; ///\var z iterator used for frequency vector
int fr[1000000]; ///\var fr frequency vector who contains only 0 and 1
char a[1000000]; ///\var a vector where is stored the initial message
char cript[1000000]; ///\var cript vector where is stored the cripted message
char decript[1000000]; ///\var decript vector where is stored the decripted message


void adaugare_nonrelevant(){
    ///\fn void adaugare_nonrelevant()

    int i; ///\var i iterator
    int j; ///\var j iterator
    int nr_nonrelevant=random(); ///\var nr_nonrelevant random generated number of nonrelevant letter
    int poz_random; ///\var poz_random random pozition of a letter

    for(i=0;i<nr_nonrelevant;i++){

        poz_random=randompoz(strlen(a)); ///\brief generate the pozition ( of a letter ) wich has to be smaller than the lenght of a (message)

        char litera=litererandom(); ///\brief random generated letter

        for(j=strlen(a);j>poz_random;j--){ ///\brief adding the nonrelevant letter
            a[j+1]=a[j];
            fr[j+1]=fr[j];
        }
        a[poz_random+1]=litera;
        fr[poz_random+1]=1;
    }
    nr_sir=strlen(a); ///\brief the new lenght of the message
}

void criptare(){
    ///\fn void criptare()


    int i; ///\var i iterator
    int j; ///\var j iterator
    int nr_relevant; ///\var nr_relevant variable used for storing the prim number of appearances of the relevant letter
    int nr_notrelevant; ///\var nr_notrelevant variable used for storing the nonprim number of appearances of the nonrelevant letter
    int nrcript=0; ///\var nrcript variable used for storing the lenght of the cripted vector

    for(j=0;j<nr_sir;j++){ ///\brief go through the cripted message

        if(fr[j]==0){ ///\brief if the position of the frequency vector corresponding to the cripted is 0 , the letter is relevant
            nr_relevant=primrandom(); ///\brief generating the prim number of appearances of the relevant letter

            for(i=nrcript ; i < nrcript+nr_relevant ; i++) ///\brief adding the relevant letters to the cripted vector
                cript[i]=a[j];

            nrcript=nrcript+nr_relevant;
        }

        if(fr[j]==1){ ///\brief if the position of the frequency vector corresponding to the cripted is 1 , the letter is nonrelevant
            nr_notrelevant=notprimrandom();  ///\brief generating the nonprim number of appearances of the nonrelevant letter


            for(i=nrcript ;  i<nrcript+nr_notrelevant  ;  i++) ///\brief adding the nonrelevant letters to the cripted vector
                cript[i]=a[j];
            nrcript=nrcript+nr_notrelevant;
        }

    }
}

void decriptare(){
    ///\fn void decriptare()
    int i; ///\var i iterator
    int nr=1;

    for(i=0;i<strlen(cript);i++){ ///\brief go through the cripted message

        if(cript[i]==cript[i+1]){ ///\brief count the number of letters
            nr++;
        }
        else{  ///\brief reseting at new letter
            if(verif_prim(nr)==1) ///\brief verify if the number of letters is prim
                decript[++z]=cript[i]; ///\brief adding the relevant leters in decripted vector
            nr=1;
        }
    }

}

int main(){
    ///\fn int main()
    int i; ///\var i iterator
    int choice=5; /// NULL chase
    int ok1=0;
    int ok2=0;
    int ok3=0;

    srand(time(NULL)); /// number generator iniialized by the seed (time)

    printf("Pentru a introduce mesajul de criptat selectati 1 \nPentru a cripta mesajul selectati 2 \nPentru a decripta mesajul apasati 3\nPentru a decripta mesajul apasati 4\n"); // MENU
    while(choice!=4){ ///\brief chase 4 (exit)
        scanf("%d",&choice);///\brief insert choice
        if(choice==1){///\brief chase 1 : the original message
            for(i=0;i<=1000000;i++){ ///\brief initializing the vector with \0
                a[i]='\0';
                cript[i]='\0';
                decript[i]='0';
                fr[i]='\0';
            }
            scanf("%[^\n]s",&a); ///\brief the message
            ok1=1;
            ok2=0;
            ok3=0;
        }
        else
        if(choice==2){ ///\brief chase 2 : cripting the message
            if(ok1==0)
                printf("ERROR\n");
            else{
                adaugare_nonrelevant();
                criptare();
                printf("%s \n",cript);
                ok2=1;
                ok1=0;
            }
        }
        else
        if(choice==3){ ///\brief chase 3 : decripting the message
            if(ok2==0)
                printf("ERROR\n");
            else{
                decriptare();
                for(i=1;i<=z;i++)
                printf("%c",decript[i]);
                printf("\n");
                ok1=0;
                ok2=0;
            }
        }
    }
}
