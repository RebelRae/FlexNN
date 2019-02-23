//
//  Utilities.h
//  Brain
//
//  Created by Rebel Rae on 2/18/19.
//  Copyright © 2019 TDR Studios. All rights reserved.
//

#pragma once

//          NOTE : This would need to return layer if used
//          NOTE : This is examplified in the Brain.h Learn() function
void MultiplyLayers(Layer layerA, Layer layerB) {
    for (int i=0; i<layerB.size(); i++) {
        double sum = 0;
        for (int j=0; j<layerA.size(); j++) {
            double product = layerB.getNeuron(i).getWeight()*layerA.getNeuron(j).getActivation();
            sum += product;
        }
        layerB.setValue(i, sum, 1.0);
    }
}
