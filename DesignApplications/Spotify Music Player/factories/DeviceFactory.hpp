#pragma once
#include <iostream>
#include "../device/BluetoothSpeakerAdapter.hpp"
#include "../device/HeadphonesAdapter.hpp"
#include "../device/IAudioOutputDevice.hpp"
#include "../device/WiredSpeakerAdapter.hpp"
#include "../enums/DeviceType.hpp"
using namespace std;

class DeviceFactory
{
public:
    static IAudioOutputDevice *createDevice(DeviceType deviceType)
    {
        if (deviceType == DeviceType::BLUETOOTH)
        {
            return new BluetoothSpeakerAdapter(new BluetoothSpeakerAPI());
        }
        else if (deviceType == DeviceType::HEADPHONES)
        {
            return new HeadphonesAdapter(new HeadphonesAPI());
        }
        else // WIRED
        {
            return new WiredSpeakerAdapter(new WiredSpeakerAPI());
        }
    }
};