#pragma once
#include <iostream>
#include <string>
using namespace std;

class WiredSpeakerAPI
{
public:
    void playSoundViaCable(const string &data)
    {
        // mimics playing music
        cout << "[Wired Speaker] playing : " << data << endl;
    }
};