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

    Lift(const Lift& other) : lowerFloor(other.lowerFloor), upperFloor(other.upperFloor), isWorking(other.isWorking), currentFloor(other.currentFloor) {
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

    static Lift& higherLift(Lift& lift1, Lift& lift2) {
        return (lift1.currentFloor > lift2.currentFloor) ? lift1 : lift2;
    }

    static Lift& closestLift(int floor, Lift& lift1, Lift& lift2) {
        int distance1 = abs(lift1.currentFloor - floor);
        int distance2 = abs(lift2.currentFloor - floor);

        return (distance1 < distance2) ? lift1 : lift2;
    }
};

int Lift::liftCount = 0;

int main() {
    Lift lift1(1, 10);
    Lift lift2(1, 9);

    lift1.turnOn();
    lift2.turnOn();

    cout << "Lift1 is working: " << lift1.isLiftWorking() << endl;
    cout << "Lift2 is working: " << lift2.isLiftWorking() << endl;

    lift1.callLift(10);
    lift2.callLift(4);
    cout << "Lift1 current floor: " << lift1.getCurrentFloor() << endl;
    cout << "Lift2 current floor: " << lift2.getCurrentFloor() << endl;

    cout << "Total lifts created: " << Lift::getLiftCount() << endl;

    Lift higherLift = Lift::higherLift(lift1, lift2);
    cout << "Higher lift is at floor: " << higherLift.getCurrentFloor() << endl;

    int floorToCheck = 5;
    Lift closestLift = Lift::closestLift(floorToCheck, lift1, lift2);
    cout << "Closest lift to floor " << floorToCheck << " is at floor: " << closestLift.getCurrentFloor() << endl;

    lift1.turnOff();
    lift2.turnOff();

    return 0;
}