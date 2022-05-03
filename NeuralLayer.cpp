#include "NeuralLayer.h"
#include <iostream>

NeuralLayer::NeuralLayer(int size, std::function<double(double)> activationFunction) : m_layerSize(size), m_activationFunction(activationFunction)
{
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
    if (input.size() != m_layerSize)
    {
        throw std::invalid_argument("Input (size: " + std::to_string(input.size()) + " )" + "must be equal in size to layer size (size: " + std::to_string(m_layerSize) + ") ");
    }
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
    double weightValue = 1;
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
    if (m_previous != NULL)
    {
        m_previous->SetInput(input);
        return;
    }
    this->SetInput(input);
}

std::string NeuralLayer::ValuesToString()
{
    std::string message = "";
    int i = 0;
    std::cout << "ASD" << std::endl;
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