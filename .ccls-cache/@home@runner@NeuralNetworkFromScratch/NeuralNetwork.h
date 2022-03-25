#include <functional>
#include <vector>
#include <map>
#include "Neuron.h"
#include "ActivationFunctions.h"

enum ActivationFunctionType{
  linear,
  sigmoid,
  tanh,
  relu
};

template <typename T_INPUT, typename T_OUTPUT>
class NeuralNetwork{
  public:

    NeuralNetwork(int size[], ActivationFunctionType ActivationFunctionType);

    void CreateNetwork();

    /// TODO:: Make it so that you can create a layer of neurons that have a different activation function than the main :D
    void CreateLayer(int size);
    void CreateNeuron();


    T_OUTPUT operator()(T_INPUT input);
    
  private:
    
    int[] m_size;


    // These might need to be re-worked in the future if we make it so that each layer can have its own activation function
    ActivationFunction m_activationFunctionType;
    std::function<double(double)> m_activationFunction;

    // The actual layers of neurons
    std::map<int, std::vector<Neuron>> m_layers;

};