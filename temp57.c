#include <stdio.h>
#include <string.h>
#include <math.h>
#define TransportationText(TYPE) char *name;\
double speed;\
double distance;\
int (*price)(struct TYPE*);\
double (*time)(struct TYPE*)

typedef struct car_s {
    int oilPrice;
    int parkPrice;
    int tolls;
    TransportationText(car_s);
} car_t;

typedef struct bike_s {
    int rentPrice;
    TransportationText(bike_s);
} bike_t;

typedef struct bus_s {
    int ticketPrice;
    int additionalPrice;
    TransportationText(bus_s);
} bus_t;

typedef struct scooter_s {
    int oilPrice;
    TransportationText(scooter_s);
} scooter_t;

typedef struct transportation_s{
    char *name;
    int price;
    double time;
} transportation_t;

int CarPrice(car_t *obj){
    obj->oilPrice=obj->oilPrice*ceil(obj->distance/100)*10;
    obj->tolls=obj->tolls*ceil(obj->distance/100);
    return obj->oilPrice+obj->parkPrice+obj->tolls;
}

double CarTime(car_t *obj){
    return obj->distance/obj->speed;
}

void CarCreate(car_t *obj) {
    obj->name="Car";
    obj->speed=100;
    obj->price=CarPrice;
    obj->time=CarTime;
}

int BikePrice(bike_t *obj){
    return obj->rentPrice;
}

double BikeTime(bike_t *obj){
    return obj->distance/obj->speed;
}

void BikeCreate(bike_t *obj){
    obj->name="Bike";
    obj->speed=20;
    obj->price=BikePrice;
    obj->time=BikeTime;
}

int BusPrice(bus_t *obj){
    if(obj->distance>=100){
        obj->additionalPrice=obj->additionalPrice*ceil((obj->distance-100)/50);
    }
    else{
        obj->additionalPrice=0;
    }
    return obj->ticketPrice+obj->additionalPrice;
}

double BusTime(bus_t *obj){
    return obj->distance/obj->speed;
}

void BusCreate(bus_t *obj){
    obj->name="Intercity Bus";
    obj->speed=75;
    obj->price=BusPrice;
    obj->time=BusTime;
}

int ScooterPrice(scooter_t *obj){
    obj->oilPrice=obj->oilPrice*ceil(obj->distance/100)*4;
    return obj->oilPrice;
}

double ScooterTime(scooter_t *obj){
    return obj->distance/obj->speed;
}

void ScooterCreate(scooter_t *obj){
    obj->name="Scooter";
    obj->speed=50;
    obj->price=ScooterPrice;
    obj->time=ScooterTime;
}

void insert_sort(transportation_t *obj,int price)
{
    int num1;
    double num2;
    char *x1;
    for(int i=1;i<4;i++)
    {
        for(int k=i;k>0;k--)
        {
            if(obj[k].time>=obj[k-1].time)
            {
                break;
            }
            x1=obj[k].name;
            obj[k].name=obj[k-1].name;
            obj[k-1].name=x1;
            num1=obj[k].price;
            obj[k].price=obj[k-1].price;
            obj[k-1].price=num1;
            num2=obj[k].time;
            obj[k].time=obj[k-1].time;
            obj[k-1].time=num2;
        }
    }
    for(int i=0;i<4;i++)
    {
        if(obj[i].price<=price)
        {
            printf("%s\n",obj[i].name);
            printf("%d\n",obj[i].price);
            printf("%.2lf\n",obj[i].time);
            return;
        }
        if(i==3)
        {
            printf("%s\n","No Transportation");
        }
    }
}

int main(){
    car_t car;
    bike_t bike;
    bus_t bus;
    scooter_t scooter;
    transportation_t transportation[4];
    CarCreate(&car);
    BikeCreate(&bike);
    BusCreate(&bus);
    ScooterCreate(&scooter);
    int  distance,price;
    scanf("%d %d",&distance,&price);
    scanf("%d %d %d",&car.oilPrice,&car.parkPrice,&car.tolls);
    scanf("%d",&bike.rentPrice);
    scanf("%d %d",&bus.ticketPrice,&bus.additionalPrice);
    scanf("%d",&scooter.oilPrice);
    car.distance=distance;
    bike.distance=distance;
    bus.distance=distance;
    scooter.distance=distance;
    CarCreate(&car);
    BikeCreate(&bike);
    BusCreate(&bus);
    ScooterCreate(&scooter);
    transportation[0].name=car.name;
    transportation[0].price=car.price(&car);
    transportation[0].time=car.time(&car);
    transportation[1].name=bike.name;
    transportation[1].price=bike.price(&bike);
    transportation[1].time=bike.time(&bike);
    transportation[2].name=bus.name;
    transportation[2].price=bus.price(&bus);
    transportation[2].time=bus.time(&bus);
    transportation[3].name=scooter.name;
    transportation[3].price=scooter.price(&scooter);
    transportation[3].time=scooter.time(&scooter);
    insert_sort(&transportation[0],price);
}