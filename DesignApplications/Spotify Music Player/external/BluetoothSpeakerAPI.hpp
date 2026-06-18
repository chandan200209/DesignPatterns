#pragma once
#include <string>
#include <iostream>
using namespace std;

class BluetoothSpeakerAPI
{
public:
    void playSoundViaBluetooth(const string &data)
    {
        // mimics playing music
        cout << "[Bluetooth Speaker] playing : " << data << endl;
    }
};