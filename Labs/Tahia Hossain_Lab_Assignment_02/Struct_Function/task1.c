#include <stdio.h>
#include<stdlib.h>
#include <unistd.h>

struct Item{
    float quantity;
    float unit_price;
};


float calculate_total_bill(struct Item paratha, struct Item vegetable, struct Item water){
    float paratha_total = paratha.quantity * paratha.unit_price;
    float vegetable_total = vegetable.quantity * vegetable.unit_price;
    float water_total = water.quantity * water.unit_price;
    return paratha_total + vegetable_total + water_total;
}

float calculate_amount_per_person(float grand_total, int num_people){
    return grand_total / num_people;
}

int main(){
    struct Item paratha, vegetable, water;

    printf("Quantity Of Paratha: ");
    scanf("%f", &paratha.quantity);
    printf("Unit Price: ");
    scanf("%f", &paratha.unit_price);

    printf("Quantity Of Vegetables: ");
    scanf("%f", &vegetable.quantity);
    printf("Unit Price: ");
    scanf("%f", &vegetable.unit_price);

    printf("Quantity Of Mineral Water: ");
    scanf("%f", &water.quantity);
    printf("Unit Price: ");
    scanf("%f", &water.unit_price);

    int num_people;
    printf("Number of People: ");
    scanf("%d", &num_people);

    float grand_total = calculate_total_bill(paratha, vegetable, water);

    float amount_per_person = calculate_amount_per_person(grand_total, num_people);

    printf("Individual people will pay: %.2f tk\n", amount_per_person);

    return 0;
 }