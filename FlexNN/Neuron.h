//
//  Neuron.h
//  Brain
//
//  Created by Rebel Rae on 2/13/19.
//  Copyright © 2019 TDR Studios. All rights reserved.
//

#pragma once

class Neuron {
private:
    int type;
    double value, activation, derivative, weight;
public:
    Neuron(double inputValue) {
        this->setValue(inputValue, 1.0);
        this->weight = ((double) rand() / (RAND_MAX));
    }
    int getType() { return this->type; }
    double getValue() { return this->value; }
    double getActivation() { return this->activation; }
    double getDerivative() { return this->derivative; }
    double getWeight() { return this->weight; }
    void setType(int type) { this->type = type; }
    void setValue(double inputValue, double sigmoidWeight) {
        this->value = inputValue;
        //  sigmoid can change by adding >0 ~ <=1 instead of 1 from strong to fast
        //  fast sigmoid : f(x) = x / (1 + |x|)
        this->activation = inputValue / (sigmoidWeight + abs(inputValue));
        //  derivative : f of (x) = f(x) * (1 - f(x))
        //  TODO : TEST : see if the sigmoid weight polls derivative correctly
        this->derivative = this->activation * (1 - this->activation);
    }
};
