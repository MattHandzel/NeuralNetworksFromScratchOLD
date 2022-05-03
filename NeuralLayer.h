#include "Neuron.h"

class NeuralLayer
{
public:
    // Constructor for the layer, you pass in the size of the layer as well as what activation function to use in the layer
    NeuralLayer(int size, std::function<double(double)> activationFunction);

    // This will return a neuron that is made to have the proper bias as well as activation function
    Neuron CreateNeuron();

    // This will process the data from the neurons in the layer
    void ProcessLayer();

    // This will connect one layer to another
    void ConnectLayer(NeuralLayer other);

    // This will return the neurons from the layer
    std::vector<Neuron> &GetNeurons();

    // This will return the connections of all neurons in the layers
    std::string ConnectionsToString();

    // This will return the values of the neurons in the layer
    std::string ValuesToString();

    // This will return the size of the layer
    int GetLayerSize();

    // This will run the function ConnectLayer if another layer is passed into it, but it allows me to use () which is what tensorflow does and i like that
    void operator()(NeuralLayer otherLayer);

    // This will run the function SetInput, if the variabled passed into it is a vector of doubles
    void operator()(std::vector<double> input);

    // This will the set the neurons of the function's value to be equal to the input
    void SetInput(std::vector<double> input);

private:
    // m_layerSize is the size of the layer which determines the number of neurons
    int m_layerSize;

    // activationFunction is the activation function used for the neurons in the entire layer
    std::function<double(double)> m_activationFunction;

    // m_neurons contains the neurons in the layer
    // || making m_neurons be a list might be better
    std::vector<Neuron> m_neurons;

    // This will make it so that we can point to the previous layer, this will allow us to run a function like SetInputs() on a layer deep in the netowrk, and then it would
    // set the inputs for the very first layer in the network
    NeuralLayer *m_previous = NULL;
};
