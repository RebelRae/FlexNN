#pragma never

// SAMPLE : How to create a 3D vector and iterate values
//          In this case, variable size training data for NNs
std::vector<std::vector<std::vector<double>>> trainingData;
//          Each push_back contains two vectors of inputs and outcomes
//          XOR example data
trainingData.push_back({{0.0, 0.0},{0.0}});
trainingData.push_back({{0.0, 1.0},{1.0}});
trainingData.push_back({{1.0, 0.0},{1.0}});
trainingData.push_back({{1.0, 1.0},{0.0}});
//          Outer vector
for (int i=0; i<trainingData.size(); i++) {
    std::cout << "outer vector " << i << std::endl;
    //      Each of the [two] inner vectors, 0 and 1
    for (int j=0; j<trainingData.at(i).size(); j++) {
        std::cout << "vector " << j << " in vector " << i << std::endl;
        //  Inner vectors [inputs and outcomes]
        for (int k=0; k<trainingData.at(i).at(j).size(); k++) {
            std::cout << "data " << trainingData.at(i).at(j).at(k) << " at vector " << j << " in vector " << i << std::endl;
        }
    }
}
