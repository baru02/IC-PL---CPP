/*
 * ChargingBeast.cpp
 *
 *  Created on: 18 Jun 2011
 *  Author: Lukasz Kmiecik 
 */

#include "ChargingBeast.hpp"
#include "vehicle.hpp"
#include "dieselCar.hpp"
#include "petrolCar.hpp"
#include "lorry.hpp"
#include "bus.hpp"
#include <iostream>
#include <typeinfo>

using namespace std;


void ChargingBeast::charge(Vehicle * wheeledMachine){
	if(wheeledMachine -> get_was_charged()){
		wheeledMachine -> set_charge(0);
		wheeledMachine -> set_no_action(true);
		return;
	}
	if((wheeledMachine -> get_enter_time() < 9 or wheeledMachine -> get_enter_time() > 18) and
			(typeid(*wheeledMachine) == typeid(DieselCar) or typeid(*wheeledMachine) == typeid(PetrolCar)))
	{
	wheeledMachine -> set_charge(0);
	wheeledMachine -> set_goes_free(true);
	return;
	}
	//check types

	if(typeid(*wheeledMachine) == typeid(Lorry)){
		wheeledMachine -> set_charge(((Lorry*)wheeledMachine) -> get_axle_number() *Vehicle::get_rate());
		wheeledMachine -> set_was_charged(true);
	}
	else if(typeid(*wheeledMachine) == typeid(PetrolCar)){
		wheeledMachine -> set_charge(2 * Vehicle::get_rate());
		wheeledMachine -> set_was_charged(true);
	}
	else if(typeid(*wheeledMachine) == typeid(DieselCar)){
		if(((DieselCar*)wheeledMachine) -> get_emission() > ((DieselCar*)wheeledMachine) -> get_limit()) {
		    wheeledMachine -> set_charge(3 * Vehicle::get_rate());
		} else {
		    wheeledMachine -> set_charge(1 * Vehicle::get_rate());
		}
		wheeledMachine -> set_was_charged(true);
	}
	else if(typeid(*wheeledMachine) == typeid(Bus)){
			if(((Bus*)wheeledMachine) -> get_total_passengers() > 20){
			    wheeledMachine -> set_charge(0);
			    wheeledMachine -> set_goes_free(true);
			} else {
			    wheeledMachine -> set_charge(5 * Vehicle::get_rate());
			}
			wheeledMachine -> set_was_charged(true);
	}

}

/* 
 * Sto, przez trzy
 * Sto, pięć lewy 
 * Sto, cztery praw.. o kurwa co to jest?!
 */
