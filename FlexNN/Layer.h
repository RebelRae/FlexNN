//
//  Layer.h
//  Brain
//
//  Created by Rebel Rae on 2/13/19.
//  Copyright © 2019 TDR Studios. All rights reserved.
//

#pragma once
#include "Neuron.h"

class Layer {
private:
    std::vector<Neuron> layer;
public:
    Layer(unsigned long depth) {
        for(int i=0; i<depth; i++) {
            Neuron neuron = *new Neuron(0.0);
            this->layer.push_back(neuron);
        }
    }
    void setValue(int depth, double value, double sigmoidWeight) {
        this->layer.at(depth).setValue(value, sigmoidWeight);
    }
    Neuron getNeuron(int depth) {
        return layer.at(depth);
    }
    unsigned long size() {
        return layer.size();
    }
};
