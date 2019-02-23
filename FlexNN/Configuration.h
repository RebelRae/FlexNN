//
//  BrainConfig.h
//  Brain
//
//  Created by Rebel Rae on 2/14/19.
//  Copyright © 2019 TDR Studios. All rights reserved.
//

#pragma once
#include <iostream>
#include <stdlib.h>
#include <string>
#include <vector>
#include <map>

class Configuration {
private:
    bool sigmoid, tahn, gaussian, lowSinc;
    std::vector<unsigned long> topology;
    std::vector<double> memory;
public:
    Configuration() {
        this->sigmoid = true;
        this->tahn = false;
        this->gaussian = false;
        this->lowSinc = false;
        this->topology = {0, 0};
        this->memory = {0.0, 0.0};
    }
};
