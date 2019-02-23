//
//  Brain.h
//  FlexNN
//
//  Created by Rebel Rae on 2/23/19.
//  Copyright © 2019 TDR Studios. All rights reserved.
//

#pragma once
#include "Layer.h"
#include "Utilities.h"

class Brain {
private:
    std::vector<unsigned long> topology;
    std::vector<Layer> layers;
public:
    Brain(std::vector<unsigned long> topology) {
        this->topology = topology;
        //          Input layer init : at [0]
        layers.push_back(*new Layer(topology.at(0)));
        //          Because [0] and [1] are the I/O layers, add layers beginning at [2]
        for (int i=2; i<topology.size(); i++) {
            layers.push_back(*new Layer(topology.at(i)));
        }
        //          Output layer init : at [1]
        layers.push_back(*new Layer(topology.at(1)));
        //          Printing topology on brain init
        std::cout << "Topology:" << std::endl << "  [";
        for (int i=0; i<layers.size(); i++) {
            if (i == layers.size()-1)
                std::cout << layers.at(i).size();
            else
                std::cout << layers.at(i).size() << ", ";
        }
        std::cout << "]" << std::endl;
    }
    
    void Configure(Configuration configuration) {
        std::cout << "Do configuration stuff here" << std::endl;
    }
    
    void Learn(std::vector<std::vector<std::vector<double>>> trainingData) {
        //          For each entry in trainingData
        for (int i=0; i<trainingData.size(); i++) {
            //      Set input values to layers [0]
            for (int j=0; j<trainingData.at(i).at(0).size(); j++) {
                layers.at(0).setValue(j, trainingData.at(i).at(0).at(j), 1.0);
            }
            //      And for each layer up to output
            for (int j=0; j<layers.size()-1; j++) {
                //  Take each neuron in the next layer
                for (int k=0; k<layers.at(j+1).size(); k++) {
                    double sum = 0;
                    //  And multiply it's weight by the first layers neurons activations
                    for (int l=0; l<layers.at(j).size(); l++) {
                        double product = layers.at(j+1).getNeuron(k).getWeight()*layers.at(j).getNeuron(l).getActivation();
                        //  Add them all together
                        sum += product;
                    }
                    //  Set it's new value to the sum
                    layers.at(j+1).setValue(k, sum, 1.0);
                }
            }
            Print(false);
            //      To set errors
            std::cout << std::endl << "Answers" << std::endl;
            //      Iterate through output layer [1]
            for (int j=0; j<trainingData.at(i).at(1).size(); j++) {
                std::cout << "  answer: " << trainingData.at(i).at(1).at(j) << std::endl;
                //  Subtract
            }
        }
    }
    
    void Print(bool full) {
        std::cout << std::endl << "<--------------- status --------------->" << std::endl;
        for (int i=0; i<this->layers.size(); i++) {
            if (i == 0)
                std::cout << "        <----- Input layer ----->" << std::endl;
            else if (i == this->layers.size()-1)
                std::cout << "        <----- Output layer ----->" << std::endl;
            else
                std::cout << "       <----- Hidden Layer " << i << " ----->" << std::endl;
            for (int j=0; j<this->layers.at(i).size(); j++) {
                std::cout << "Neuron " << j+1 << std::endl;
                std::cout << "  value: " << this->layers.at(i).getNeuron(j).getValue() << std::endl;
                if (full) {
                    std::cout << "  activation: " << this->layers.at(i).getNeuron(j).getActivation() << std::endl;
                    std::cout << "  derivative: " << this->layers.at(i).getNeuron(j).getDerivative() << std::endl;
                    std::cout << "  weight: " << this->layers.at(i).getNeuron(j).getWeight() << std::endl;
                }
            }
        }
    }
};
