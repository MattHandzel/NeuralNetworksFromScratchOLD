#include <functional>
#include <vector>
#include <map>
#include "NeuralLayer.h"

enum ActivationFunctionType{
  linear,
  sigmoid,
  relu
};

class NeuralNetwork{
  public:

    NeuralNetwork(int shape[], ActivationFunctionType ActivationFunctionType);

    void CreateNetwork();

    /// TODO:: Make it so that you can create a layer of neurons that have a different activation function than the main :D
    void CreateLayer(int shape);

    // private:

    // The actual layers of neurons
    std::vector<NeuralLayer> m_layers;

    int m_networkDepth = 0;

    // shape of the neural network
};