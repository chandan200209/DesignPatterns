#pragma once
#include <iostream>
#include "../strategies/CustomQueueStrategy.hpp"
#include "../strategies/PlayStrategy.hpp"
#include "../strategies/RandomPlayStrategy.hpp"
#include "../strategies/SequentialPlayStrategy.hpp"
#include "../enums/PlayStrategyType.hpp"
using namespace std;

class StrategyManager
{
private:
    static StrategyManager *instance;
    SequentialPlayStrategy *sequentialStrategy;
    RandomPlayStrategy *randomStrategy;
    CustomQueueStrategy *customQueueStrategy;
    StrategyManager()
    {
        sequentialStrategy = new SequentialPlayStrategy();
        randomStrategy = new RandomPlayStrategy();
        customQueueStrategy = new CustomQueueStrategy();
    }

public:
    static StrategyManager *getInstance()
    {
        if (!instance)
        {
            instance = new StrategyManager();
        }
        return instance;
    }
    PlayStrategy *getStrategy(PlayStrategyType type)
    {
        if (type == PlayStrategyType::CUSTOM_QUEUE)
        {
            return customQueueStrategy;
        }
        else if (type == PlayStrategyType::RANDOM)
        {
            return randomStrategy;
        }
        else
        {
            return sequentialStrategy;
        }
    }
};
StrategyManager *StrategyManager::instance = nullptr;