#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <stdint.h>

struct Person{
    char firstName[128];
    char lastName[128];
    char nume_judet[3];
};

struct Car{
    char brand[128];
    char licencePlate[9];
    uint16_t yearOfFabrication;
    struct Person* owner;
    uint8_t no_of_owners;
};

struct Person* createPerson() {
    struct Person* my_person = (struct Person*) malloc(sizeof(struct Person));
    scanf("%s %s %s", my_person->firstName, my_person->lastName, my_person->nume_judet);

    return my_person;
}

struct Car* createCar() {
    struct Car* my_car = (struct Car*) malloc(sizeof(struct Car));
    scanf("%s %s %hd", my_car->brand, my_car->licencePlate, &my_car->yearOfFabrication);
    my_car->owner=createPerson();
    scanf("%hhd", &my_car->no_of_owners);
    return my_car;
}

void addCar(struct Car* car, struct Car** cars, uint32_t* no_of_cars) {
    int l = *no_of_cars;
    *(cars+l-1)=car;
}

struct Car** readData(uint32_t no_of_cars) {
    struct Car** my_cars;
    my_cars =(struct Car**) malloc(10*no_of_cars*sizeof(struct Car**));

    for(int i=1;i<=no_of_cars;i++){
        addCar(createCar(), my_cars, &i);
    }
    return my_cars;
}

void sell(struct Car* car, struct Person* new_owner) {
    car->no_of_owners++;
    car->licencePlate[0]=new_owner->nume_judet[0];
    car->licencePlate[1]=new_owner->nume_judet[1];
    for(int i=2;i<=6;i++){
        if(isdigit(car->licencePlate[i])){
            if(car->licencePlate[i]!='9')
                car->licencePlate[i]++;
        }
        if(isalpha(car->licencePlate[i])){
            if(car->licencePlate[i]!='z'&&car->licencePlate[i]!='Z')
                car->licencePlate[i]++;
        }
    }
    strcpy(car->owner->firstName, new_owner->firstName);
    strcpy(car->owner->lastName, new_owner->lastName);
}

void rabla(struct Car* car) {
    memset(&car->owner->firstName[0], 0, sizeof(car->owner->firstName));
    memset(&car->owner->lastName[0], 0, sizeof(car->owner->lastName));
    car->no_of_owners=0;
    memset(&car->licencePlate[0], 0, sizeof(car->licencePlate));
}

struct Car* find_car_by_licencePlate(struct Car** all_cars, int no_of_cars, char licencePlate[9]){
    for(int i=0;i<no_of_cars;i++){
        if(strcmp(licencePlate, all_cars[i]->licencePlate)==0)
            return all_cars[i];
    }

}

uint16_t from_char_to_int(char cnr[5]){
    uint16_t number=0;;

    for(int i=0;i<strlen(cnr);i++){
        number=number*10+(cnr[i]-'0');
    }

    return number;
}

void hq(struct Car** all_cars, char command[500], int *no_of_cars){
    char *tok;
    tok=strtok(command, " ");
    if(strcmp(command, "sell")==0){
        char licencePlate[9];
        char firstName[128];
        char lastName[128];
        char nume_judet[3];
        tok= strtok(NULL, " "); strcpy(licencePlate, tok);
        tok=strtok(NULL, " "); strcpy(firstName, tok);
        tok=strtok(NULL, " "); strcpy(lastName, tok);
        tok=strtok(NULL, " "); strcpy(nume_judet, tok);

        struct Person* new_owner = (struct Person*) malloc(sizeof(struct Person));
        strcpy(new_owner->firstName, firstName);
        strcpy(new_owner->lastName, lastName);
        strcpy(new_owner->nume_judet, nume_judet);

        sell(find_car_by_licencePlate(all_cars, *no_of_cars, licencePlate), new_owner);
    }
    if(strcmp(command, "rabla")==0){
        tok= strtok(NULL, " ");
        rabla(find_car_by_licencePlate(all_cars, *no_of_cars, tok));
    }
    if(strcmp(command, "add")==0){
        char brand[128];
        char licencePlate[9];
        uint16_t yearOfFabrication;
        char firstName[128];
        char lastName[128];
        char nume_judet[3];
        tok=strtok(NULL, " "); strcpy(brand, tok);
        tok=strtok(NULL, " "); strcpy(licencePlate, tok);
        tok=strtok(NULL, " "); yearOfFabrication=from_char_to_int(tok);
        tok=strtok(NULL, " "); strcpy(firstName, tok);
        tok=strtok(NULL, " "); strcpy(lastName, tok);
        tok=strtok(NULL, " "); strcpy(nume_judet, tok);

        //printf("%s %s %hd %s %s %s", brand, licencePlate, yearOfFabrication, firstName, lastName, nume_judet);
        struct Person* new_owner = (struct Person*) malloc(sizeof(struct Person));
        strcpy(new_owner->firstName, firstName);
        strcpy(new_owner->lastName, lastName);
        strcpy(new_owner->nume_judet, nume_judet);

        struct Car* new_car = (struct Car*) malloc(sizeof(struct Car));
        strcpy(new_car->brand, brand);
        strcpy(new_car->licencePlate, licencePlate);
        new_car->yearOfFabrication=yearOfFabrication;
        new_car->owner=new_owner;
        new_car->no_of_owners=0;

        *no_of_cars=*no_of_cars + 1;

        addCar(new_car, all_cars, no_of_cars);
    }
}

int main(){

    uint32_t no_of_cars, no_of_cars_copy;
    int no_of_commands;
    char command[500];

    scanf("%d %d", &no_of_cars, &no_of_commands);
    no_of_cars_copy=no_of_cars;

    struct Car** my_cars;

    my_cars=readData(no_of_cars);

    //printf("\n");

    struct Person new_owner;
    strcpy(new_owner.firstName,"matei");
    strcpy(new_owner.lastName,"matei");
    strcpy(new_owner.nume_judet,"NT");

    //rabla(my_cars[1]);
    //sell(my_cars[2], &new_owner);

    /*for(int i=0;i<no_of_cars_copy;i++){
        printf("%s %s %hd %s %s %s %hhd \n", my_cars[i]->brand, my_cars[i]->licencePlate, my_cars[i]->yearOfFabrication,
               my_cars[i]->owner->firstName, my_cars[i]->owner->lastName, my_cars[i]->owner->nume_judet,
               my_cars[i]->no_of_owners);
    }*/
    getchar();
    /*for(int i=0;i<no_of_commands;i++){
        scanf("%[^\n]", command);
        getchar();
        //printf("%s \n", command);
        hq(my_cars, command, &no_of_cars);
    }*/

    while(scanf("%[^\n]", command)!=EOF){
        getchar();
        hq(my_cars, command, &no_of_cars);
    }

    for(int i=0;i<no_of_cars;i++){
        if(my_cars[i]->licencePlate[0]!=0)
            printf("Masina %s cu nr. de inmatriculare %s a avut %hhd proprietari.\n", my_cars[i]->brand, my_cars[i]->licencePlate
                   , my_cars[i]->no_of_owners);
    }
    return 0;
}
