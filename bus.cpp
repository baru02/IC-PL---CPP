#include <string>
#include "vehicle.hpp"
#include "bus.hpp"

using namespace std;

Bus::Bus(string plate_number) : Vehicle(plate_number){
    ra_passengers = 0;
    total_passengers = 0;
    type = "bus";
    print(Registration);
}

int Bus::get_total_passengers(){
    return total_passengers;
}

int Bus::get_ra_passengers(){
    return ra_passengers;
}

void Bus::board(int passengers){
    total_passengers += passengers;
    ra_passengers = passengers;
    print(BusIn);
}

void Bus::leave(int passengers){
    total_passengers -= passengers;
    ra_passengers = passengers;
    print(BusOut);
}

void Lorry::charge(){
    ChargingBeast::charge(this);
}

void Lorry::print(messageType msg){
    PrintingParrot::print_message(this, msg);
}

