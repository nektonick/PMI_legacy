#include <iostream>
using namespace std;

class Device {
    public:
        int serial_number = 12345678;

        void turn_on() {
            cout << "Device is on" << endl;
        }
};

class Computer: private Device {
    public:
        void say_hello() {
            turn_on();
            cout << "Welcome to Windows 95!" << endl;
        }
};

int main() {
    Device Device_instance;
    Computer Computer_instance;

    cout << "\t Device" << endl;
    cout << "Serial number is: "<< Device_instance.serial_number << endl;
    Device_instance.turn_on();

    // cout << "Serial number is: " << Computer_instance.serial_number << endl;
    // Computer_instance.turn_on();
    // will cause compile time error

    cout << "\t Computer" << endl;
    Computer_instance.say_hello();
    return 0;
}