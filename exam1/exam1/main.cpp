//I affirm that all code given below was written solely by me, Vince Porporato, and that any help I received adhered to the rules stated for this exam.
#include <iostream>
#include <string>
#include <vector>
using std::cout;
using std::endl;
using std::string;
using std::vector;

namespace Exam1 // NAMESPACE
{
	class Wheel
	{
	private:
		int _radius;
	public:
		Wheel(int radius) { _radius = radius; }
	};


	class Vehicle
	{
	protected:
		string _color;
		int _topspeed;
		vector<Wheel> wheels;

	public:
		Vehicle(string color) {
			_color = color;
		}
		virtual void Description() = 0;
	};


	class RaceCar : public Vehicle{
	public:
		RaceCar(string color) : Vehicle(color) {
			_topspeed = 250;

			//Places the radius of the wheels into the wheel vector stored in the vehicle class
			Wheel w1(305);
			Wheel w2(305);
			Wheel w3(305);
			Wheel w4(305);
			wheels.push_back(w1);
			wheels.push_back(w2);
			wheels.push_back(w3);
			wheels.push_back(w4);
		}
	
		//What gets displayed to the user
		void Description() {
			cout << "I am a " << _color << " race car that can race " << _topspeed << "mph." << endl;
		}
	};

	class Sedan : public Vehicle{
	private:
		int number_of_seats;
	public:
		Sedan(string color,int seats) :Vehicle(color) {
			_topspeed = 95;
			number_of_seats = seats;

			//Places the radius of the wheels into the wheel vector stored in the vehicle class
			Wheel w1(381);
			Wheel w2(381);
			Wheel w3(381);
			Wheel w4(381);
			wheels.push_back(w1);
			wheels.push_back(w2);
			wheels.push_back(w3);
			wheels.push_back(w4);
		}
		//what gets displayed to the user by using the values for topspeed and number of seats from the constructor
		void Description() {
			cout << "I am a " << _color << " sedan that can carry "<<number_of_seats<<" people at " << _topspeed << "mph." << endl;
		}
	};

	class Pickup : public Vehicle{
	private:
		int hauling_capacity;
	public:
		Pickup(string color, int capacity) :Vehicle(color) {
			_topspeed = 85;
			hauling_capacity = capacity;

			//Places the radius of the wheels into the wheel vector stored in the vehicle class
			Wheel w1(432);
			Wheel w2(432);
			Wheel w3(432);
			Wheel w4(432);
			wheels.push_back(w1);
			wheels.push_back(w2);
			wheels.push_back(w3);
			wheels.push_back(w4);
		}
		//what gets displayed to the user by getting the values for _topspeed and hauling_capacity from the constructor
		void Description() {
			cout << "I am a " << _color << " pickup that can haul " << hauling_capacity << " sq. feet at " << _topspeed << "mph." << endl;
		}
	};
}


int main()
{
	Exam1::Vehicle * Garage[3];

	// STEP 3: Assign ONE RaceCar, ONE Sedan, AND ONE Pickup object to each of the elements 
	// in the Garage array.  Remember the classes are defined in the namespace Exam1.
		Garage[0] = new Exam1::RaceCar("Red");
		Garage[1] = new Exam1::Sedan("Brown", 5);
		Garage[2] = new Exam1::Pickup("Black", 600);

	for (int i = 0; i < 3; ++i)
	{
		// The method Description() should display an output like 
		// "I am a red sedan (or racecar/pickup) and I can go 95 (or 250 or 85) mph"
		Garage[i]->Description();
	}
}

