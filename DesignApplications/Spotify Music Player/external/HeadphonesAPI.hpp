#pragma once
#include <iostream>
#include <string>
using namespace std;

class HeadphonesAPI
{
public:
    void playSoundViaJack(const string &data)
    {
        // mimics playing music
        cout << "[Headphones] playing : " << data << endl;
    }
};