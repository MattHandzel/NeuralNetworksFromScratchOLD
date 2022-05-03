// Online C++ compiler to run C++ program online
#include <iostream>
#include <random>
#include <string>
#include <array>
#include "time.h"
#include <vector>

#include "NeuralNetwork.h"

std::pair<Neuron *, double> GetPair(Neuron neuron, double weight)
{
  return std::pair<Neuron *, double>(&neuron, weight);
}

int main()
{
  int shape[] = {1, 1, 1};
  NeuralNetwork nn = NeuralNetwork(shape, ActivationFunctionType::relu);
  nn.CreateLayer(2);

  auto search = nn.m_layers.find(0);
  std::cout << &search->second.at(0);
  return 0;
}