#include "Neuron.h"

class NeuralLayer
{
public:
    NeuralLayer(int size, std::function<double(double)> activationFunction);
    Neuron *CreateNeuron();
    void ProcessLayer();
    void ConnectLayer(NeuralLayer other);
    std::vector<Neuron *> &GetNeurons();
    std::string ConnectionsToString();
    std::string ValuesToString();
    int GetLayerSize();
    void operator()(NeuralLayer otherLayer);
    void operator()(std::vector<double> input);
    void SetInput(std::vector<double> input);

private:
    int m_layerSize;
    std::function<double(double)> m_activationFunction;
    std::vector<Neuron *> m_neurons;
    NeuralLayer *m_previous = NULL;
};
