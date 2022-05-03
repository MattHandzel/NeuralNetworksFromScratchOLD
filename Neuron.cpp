#include "Neuron.h"
#include <functional>
#include <iostream>
#include <sstream>

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

  // ! The connection size, for some reason, is huge
  // TODO:: Figure out why the connections size is huge and fix it
  if (m_connections.size() > 100)
  {
    std::cout << "There was an error where the size of connections is greater than 100\n";
    std::cout << m_activationFunction(m_value);
    return m_activationFunction(m_value);
  }
  for(std::pair<Neuron*, double> connection : m_connections){
    // The current value is equal to what the previous neruon has plus the weight value
    m_value += connection.first->GetValue() * connection.second;
  }
  return m_activationFunction(m_value);
}

void Neuron::SetValue(double value){
  m_bias = value;
}

std::string Neuron::ConnectionsToString()
{
  std::string message = "CONNECTIONS:\n";
  int i = 0;
  for (std::pair<Neuron *, double> connection : m_connections)
  {
    std::ostringstream address;
    address << connection.first;
    message += "\tCONNECTION: " + std::to_string(i++) + "\tADDRESS:\t" + address.str() + "\tWEIGHT:\t" + std::to_string(connection.second) + "\n";
  }
  return message;
}

/*
int main()
{
  Neuron n0 = Neuron(1);
  Neuron n1 = Neuron(0);
  Neuron n2 = Neuron(0);
  Neuron n3 = Neuron(0);
  n1.SetActivationFunction(ActivationFunctions::relu);
  n2.AddConnection(std::pair<Neuron *, double>(&n1, 2));
  n1.AddConnection(std::pair<Neuron *, double>(&n0, 2));

  std::cout << n2.GetValue();
}*/