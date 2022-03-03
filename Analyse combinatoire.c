#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int rep, ord;

int fact(int x){
    int i, res=1;
    for(i=2; i<=x; i++){
        res *= i;
    }
    return res;
}
float combin(int n, int p){
    float res;
    res = fact(n)/(fact(p)*fact(n-p));
    return res;
}

float combin_rep(int n, int p){
    float res;
    res = fact(n+p-1)/(fact(p)*fact(n-1));
    return res;
}

float arrang(int n, int p){
    float res;
    res = fact(n)/fact(n-p);
    return res;
}
float arrang_rep(int n, int p){
    float res;
    res = pow(n, p);
    return res;
}

float permut(int n){
    float res;
    res = fact(n);
    return res;
}

float permut_rep(int n){
    int ni, chifr;
    float res, denom =1;
    printf("Combien de chifres vous allez ecrire dans le denominateure?: ");
    scanf("%d", &ni);
    printf("\n");

    for (int i=1; i<=ni; i++){
        printf("Tapez le chifre numero %d: ",i);
        scanf("%d",&chifr);
        denom *= fact(chifr);
    }
    res = fact(n)/denom;
    return res;
}

void menu(){
    do{
        printf("Remarque: s'il vous plait repondez par 1 ou 0 (oui=1/ non =0)\n");
        printf("> Est-ce-que l'ordre est important? ");
        scanf("%d",&ord);
    }while(ord!=1 && ord!=0);
        printf("\n");
    do{
        printf("Remarque: s'il vous plait repondez par 1 ou 0 (oui=1/ non =0)\n");
        printf("> Est-ce-que la repitition est permise? ");
        scanf("%d", &rep);
    }while(rep!=1 && rep!=0);
    printf("\n");

}


void calcul(int n, int p){
    int permt_rep;
    if (ord==0) {
        if(rep==0){
            printf("Donc c'est une combinison sans repetition\n");
            printf("Voici le resultat: %0.1f\n", combin(n,p));        }
        else {
            printf("Donc c'est une combinison avec repetition\n");
            printf("Voici le resultat: %0.1f\n", combin_rep(n,p));        }
    }
    else {
        if (rep==0){ // j'ai prefere utiliser 3 if prcq la probabilite d'avoir (p<n) est plus grand que les autres donc j'ai commance par elle
            if (p<n){
            printf("Donc c'est un arrangement sans repetition\n");
            printf("Voici le resultat: %0.1f\n", arrang(n, p));
            }
            if(n==p){
            printf("Donc c'est une permutation sans repetition\n");
            printf("Voici le resultat: %0.1f\n", permut(n));
            }
            if (p>n){
                printf("Ce calcul est non realisable car on ne peut pas trouver p>n dans ce cas (rep=0 et ord=1)\n");
            }

        }
        else {
            if (p>n){
                printf("Donc c'est un arrangement avec repetition\n");
                printf("Voici le resultat: %0.1f\n", arrang_rep(n,p));
            }

            printf("\n Etes vous sure que ce n'est pas une permutation avec repetition?\n");
            do {
            printf("Remarque: s'il vous plait repondez par 1 ou 0 (oui= '1' / non= '0')\n");
            printf("> Est-ce-que c'est permutation avec repetition?:  ");
            scanf("%d",&permt_rep);
            }while(permt_rep!=1 && permt_rep!=0);

            if (permt_rep==0){
                printf("Merci,et boncourage.\n");
            }
            else {
                printf("Donc c'est une permitation avec repetition\n");
                printf("Voici le resultat: %0.1f\n", permut_rep(n));
            }
        }
    }
}


int main()
{
    int n, p;
    printf("||---------------------------------------||\n");
    printf("\n Bienvenu dans le programme de calcul d'analyse combinatoire \n");

    do {
        printf("tapez le n: ");
        scanf("%d",&n);
        printf("\n");
    }while (n<1);

    do {
        printf("tapez le p: ");
        scanf("%d",&p);
    }while(p<1);

    printf("\n");
    menu();
    calcul(n, p);

    return 0;
}
