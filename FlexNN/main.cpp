//
//  main.cpp
//  Brain
//
//  Created by Rebel Rae on 2/13/19.
//  Copyright © 2019 TDR Studios. All rights reserved.
//

#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <vector>
#include "Configuration.h"
#include "Brain.h"

int main(int argc, const char * argv[]) {
    //      Training data
    //      NOTE : All sets of inputs and outcomes must have the same size
    std::vector<std::vector<std::vector<double>>> trainingData;
    trainingData.push_back({{0.0, 0.0},{0.0}});
    trainingData.push_back({{0.0, 1.0},{1.0}});
    trainingData.push_back({{1.0, 0.0},{1.0}});
    trainingData.push_back({{1.0, 1.0},{0.0}});
    //      Mapping layers
    std::vector<unsigned long> topology = {
        trainingData.at(0).at(0).size(),      // Input neurons
        trainingData.at(0).at(1).size(),      // Output neurons
        2                                     // Each extra layer in between I/O
    };
    //      Initialize brain
    Brain brain = *new Brain(topology);
    //      Configure brain
    Configuration config = *new Configuration({});
    brain.Configure(config);
    //      Train brain
    brain.Learn(trainingData);
    //      Fucking around
    std::cout << "Press return to continue";
    std::cin.get();
    return EXIT_SUCCESS;
}
