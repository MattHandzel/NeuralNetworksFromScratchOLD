#include "Neuron.h"
#include <functional>

Neuron::Neuron(){}
Neuron::Neuron(double bias){
  m_bias = bias;
}

void Neuron::AddConnection(std::pair<Neuron*, double> connection){
  m_connections.push_back(connection);
}

void Neuron::AddConnection(Neuron neuron, double value){
  // This is a different version of AddConnection that lets you pass in a neuron and a value instead, this is a bit less typing :)
  m_connections.push_back(std::pair<Neuron*, double>(&neuron, value));
}

void Neuron::AddConnections(std::vector<std::pair<Neuron*, double>> connections){
  // This can probably be done better than a for loop
  for(std::pair<Neuron*, double> connection : connections){
    m_connections.push_back(connection);
  }
}

void Neuron::SetActivationFunction(std::function<double(double)> func){
  // Sets the activation function so that we can do cool machine learning stuff
  m_activationFunction = func;
}

double Neuron::GetValue(){
  m_value = m_bias;
  for(std::pair<Neuron*, double> connection : m_connections){
    m_value += connection.first->GetValue() * connection.second;
  }
  return m_activationFunction(m_value);
}

void Neuron::SetValue(double value){
  m_value = value;
}

double Neuron::linear(double value){return value;}