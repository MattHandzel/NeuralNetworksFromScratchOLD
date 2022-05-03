#include "NeuralLayer.h"
#include <iostream>

NeuralLayer::NeuralLayer(int size, std::function<double(double)> activationFunction) : m_layerSize(size), m_activationFunction(activationFunction)
{
    // Creates neurons based on the size of the layer
    for (int i = 0; i < size; i++)
    {
        this->m_neurons.push_back(CreateNeuron());
    }
}

Neuron NeuralLayer::CreateNeuron()
{
    // Initial bias is so that in the future we can make the initial bias 0, random, etc.
    double initialBias = 0;
    Neuron n = Neuron(initialBias);
    n.SetActivationFunction(m_activationFunction);

    return n;
}

void NeuralLayer::ProcessLayer()
{
    for (Neuron n : m_neurons)
    {
        n.GetValue();
    }
}

void NeuralLayer::SetInput(std::vector<double> input)
{
    // If the size of the input is not the same as the layer size then it will throw an exception
    if (input.size() != m_layerSize)
    {
        throw std::invalid_argument("Input (size: " + std::to_string(input.size()) + " )" + "must be equal in size to layer size (size: " + std::to_string(m_layerSize) + ") ");
    }

    // Set the value of the neurons in the layer to the inputs
    for (int i = 0; i < m_layerSize; i++)
    {
        m_neurons.at(i).SetValue(input[i]);
    }
}

std::vector<Neuron> &NeuralLayer::GetNeurons()
{
    return m_neurons;
}

void NeuralLayer::ConnectLayer(NeuralLayer other)
{
    this->m_previous = &other;

    // Change the weight value here, default to 1, you might wanna make it random, i dunno how this stuff works
    double weightValue = 1;

    // For each neuron in this layer, connect it to the neuron in the other layer
    for (int i = 0; i < m_layerSize; i++)
    {
        for (int b = 0; b < other.GetLayerSize(); b++)
        {
            m_neurons[i].AddConnection(std::pair<Neuron *, double>(&other.m_neurons[b], weightValue));
        }
    }
}

int NeuralLayer::GetLayerSize()
{
    return m_layerSize;
}

std::string NeuralLayer::ConnectionsToString()
{
    // Concatenates the connection message from all of the neurons into one string
    std::string message = "";
    for (Neuron n : m_neurons)
    {
        message += n.ConnectionsToString();
    }
    return message;
}

void NeuralLayer::operator()(NeuralLayer otherLayer)
{
    this->ConnectLayer(otherLayer);
}

void NeuralLayer::operator()(std::vector<double> input)
{
    // If there is another layer before this layer, then set the input of that layer to the passed inputs
    if (m_previous != NULL)
    {
        m_previous->SetInput(input);
        return;
    }

    // If that is not true, set the values of the neurons to the input
    this->SetInput(input);
}

std::string NeuralLayer::ValuesToString()
{
    std::string message = "";
    int i = 0;
    // for each neuron, get the value and concatenate it into one string
    for (Neuron n : m_neurons)
    {
        message += "NEURON:\n\tVALUE:\t" + std::to_string(n.GetValue()) + "\n";
    }
    return message;
}

int main()
{
    NeuralLayer layer = NeuralLayer(2, ActivationFunctions::relu);
    NeuralLayer other = NeuralLayer(6, ActivationFunctions::relu);
    Neuron n = Neuron();
    std::vector<double> input = {1.2, 5};

    // Connects the neurons from other to the nerons to layer

    other(layer);
    layer(input);
    Neuron n0 = Neuron(10);
    Neuron n1 = Neuron(10);

    n1.AddConnection(n0, 10);
    std::cout << other.ValuesToString() << "\n";

    // std::cout << other.GetNeurons().at(1).GetValue();

    std::cout << "\n";
}