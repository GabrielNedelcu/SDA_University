#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

struct Pizza{
    char tip[21];
    char dim[6];
    uint8_t blat;
};

void readPizza(struct Pizza* pizza) {

    uint8_t mBlat;
    scanf("%s %s %hhd", pizza->tip, pizza->dim, &mBlat);
    pizza->blat=mBlat;

}

struct Pizza* readAllPizza(int no_of_pizzas) {
    struct Pizza * pizzas = (struct Pizza*) malloc(no_of_pizzas*sizeof(struct Pizza));

    for(int i=0; i<no_of_pizzas; i++){
        readPizza(pizzas+i);
    }

    return pizzas;
}

double calc_price(struct Pizza* pizza) {
    double total_price=0;

    if(strcmp((pizza)->dim,"mica")==0) total_price+=15;
    if(strcmp((pizza)->dim,"medie")==0) total_price+=20;
    if(strcmp((pizza)->dim,"mare")==0) total_price+=35;
    if(strcmp((pizza)->dim,"XXL")==0) total_price+=40;


    if(pizza->blat==1) total_price+=15;
    if(pizza->blat==2) total_price+=17;
    if(pizza->blat==3) total_price+=18;

    return total_price;
}

int main() {
    int n;
    struct Pizza * pizzas;
    scanf("%d", &n);
    double total_price=0;
    double weitress_price;
    pizzas = readAllPizza(n);

    for(int i=0;i<n;i++){
        total_price+=calc_price(pizzas+i);
    }

    weitress_price=(double)0.1*total_price;
    total_price=total_price+weitress_price;

    printf("%.2lf", total_price);

    return 0;
}
