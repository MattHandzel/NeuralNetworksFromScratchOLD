#include "Neuron.h"
#include <functional>
#include <iostream>
#include <sstream>

// Constructors for the neuron, if you do not pass in a bias then the
// bias will be the default which is in the header file
Neuron::Neuron(){}
Neuron::Neuron(double bias){
  m_bias = bias;
}

// Adds the connection into the connections vector
void Neuron::AddConnection(std::pair<Neuron*, double> connection){
  m_connections.push_back(connection);
}

// This is a different version of AddConnection that lets you pass in a neuron and a value instead, this is a bit less typing :)
void Neuron::AddConnection(Neuron neuron, double value)
{
  m_connections.push_back(std::pair<Neuron*, double>(&neuron, value));
}

// This will add a vector of connections to the neruons connections.
void Neuron::AddConnections(std::vector<std::pair<Neuron*, double>> connections){
  // || This can probably be done better than a for each loop
  for(std::pair<Neuron*, double> connection : connections){
    m_connections.push_back(connection);
  }
}

// Sets the activation function so that we can do cool machine learning stuff
void Neuron::SetActivationFunction(std::function<double(double)> func)
{
  m_activationFunction = func;
}

// this will return the value, THE DATA IS NOT PROCESSED HERE
double Neuron::GetValue()
{

  // ! The connection size, for some reason, is huge
  // TODO:: Figure out why the connections size is huge and fix it
  // TODO:: Once this is fixed, then remove this
  if (m_connections.size() > 100)
  {
    std::cout << "There was an error where the size of connections is greater than 100\n";
    std::cout << m_activationFunction(m_value);
    return m_activationFunction(m_value);
  }

  return m_value;
}

// This will prcoess data
void Neuron::ProcessData()
{
  m_value = m_bias;
  // For each connection in connections, get the value from that neuron and multiply it by the weight
  for (std::pair<Neuron *, double> connection : m_connections)
  {
    // The current value is equal to what the previous neruon has plus the weight value
    // TODO:: Make this work with the new ProcessData() function, this will make it so that the neurons don't have to process the data each time
    m_value += connection.first->GetValue() * connection.second;
  }
  m_value = m_activationFunction(m_value);
}

// Sets the value of the neuron
void Neuron::SetValue(double value){
  m_value = value;
}

// Returns a string with data about the connections it has, including the number, the address of the neuron its connected to, as well as the value of the weight of the connection
std::string Neuron::ConnectionsToString()
{
  std::string message = "CONNECTIONS:\n";
  int i = 0;
  //! This can break if the size of m_connections is super big for some reason
  for (std::pair<Neuron *, double> connection : m_connections)
  {

    // || There is probably a better way to get the address of the neuron
    // This thing right here allows us to get the address of the neuron
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