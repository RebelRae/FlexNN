# FlexNN
<img src="https://images.pexels.com/photos/724994/pexels-photo-724994.jpeg?auto=compress&cs=tinysrgb&dpr=2&h=325&w=470" 
alt="Testing images" width="240" height="180" border="2" />

>A neural network learning series to expand our collective understanding of NNs and their usability. The beginning of this series is no longer on **<a href="https://www.Twitch.tv/Rebel_Rae">twitch</a>** in the streamed section, however, I will be editing the video for asthetics and to eliminate monotony

>The GUI will be made available for download once we complete the series
## Contents
* [Installation](#installation)
* [Examples](#examples)
* [Tests](#tests)
* [Contributors](#contributors)
* [License](#license)

## <a name="installation"></a>Installation
**Currently in development stage**

## <a name="examples"></a>Examples
**Training Data**
Our training data is structured as a vector of vectors of vectors of doubles.
* The outer vector is all of the training data
* Each entry is a vector that contains a vector of inputs and a vector of outputs
* An example for the standard eXclusive OR follows
```c++

//      Training data : XOR
std::vector<std::vector<std::vector<double>>> trainingData;
trainingData.push_back({{0.0, 0.0},{0.0}});
trainingData.push_back({{0.0, 1.0},{1.0}});
trainingData.push_back({{1.0, 0.0},{1.0}});
trainingData.push_back({{1.0, 1.0},{0.0}});

```
**Topology**
The topology of this lobe begins with the I/O layers at [0] and [1] respectively and is then followed by any number of any size of hidden layers
```c++

//      Mapping layers
std::vector<unsigned long> topology = {
trainingData.at(0).at(0).size(),      // Input neurons
trainingData.at(0).at(1).size(),      // Output neurons
2                                     // Each extra layer in between I/O
};

```
**Brain Functions**
###### Initializer
```c++

//      Initialize brain
Brain brain = *new Brain(topology);

```
###### Configure
Currently does nothing
```c++

//      Initialize configuration
Configuration config = *new Configuration({});
//      Configure brain
brain.Configure(config);

```
###### Learn
Currently in feed forward only
```c++

//      Train on data
brain.Learn(trainingData);

```
###### Print
Takes 1 bool argument
* true = will print neuron value, activation, derivative, and weight
* false = will print only neuron value
```c++

//      Print current state of brain
brain.Print(false);

```

## <a name="tests"></a>Tests
**Updates soon**

## <a name="contributors"></a>Contributors
**Sole contributor to this repository: Rebel Rae**

## <a name="license"></a>License
**Not under MIT until I can scrutinize my code more**
