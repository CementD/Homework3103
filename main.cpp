#include <iostream>
using namespace std;

class Lift {
private:
	int lowerFloor;
	int upperFloor;
	bool isWorking;
	int currentFloor;
	static int liftCount;

public:
	Lift(int lower, int upper) : lowerFloor(lower), upperFloor(upper), isWorking(false), currentFloor(lower) {
		liftCount++;
	}

	void turnOn() {
		isWorking = true;
	}

	void turnOff() {
		isWorking = false;
	}

	bool isLiftWorking() {
		return isWorking;
	}

	int getCurrentFloor() {
		return currentFloor;
	}

	void callLift(int floor) {
		if (isWorking) {
			if (floor >= lowerFloor && floor <= upperFloor) {
				cout << "Lift called to floor " << floor << endl;
				currentFloor = floor;
			}
			else
				cout << "Invalid floor. Lift cannot reach." << endl;
		}
		else
			cout << "Lift isn't working." << endl;
	}

	static int getLiftCount() {
		return liftCount;
	}
};

int Lift::liftCount = 0;

int main() {
	Lift lift(1, 10);
	lift.turnOn();
	cout << "Lift is working: " << lift.isLiftWorking() << endl;
	lift.callLift(10);
	cout << "Lift current floor: " << lift.getCurrentFloor() << endl;
	cout << "Total lifts created: " << Lift::getLiftCount() << endl;
	lift.turnOff();
	return 0;
}