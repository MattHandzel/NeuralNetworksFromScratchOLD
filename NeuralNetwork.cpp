#include "NeuralNetwork.h"

NeuralNetwork::NeuralNetwork(int shape[], ActivationFunctionType activationFunctionType)
{
  // This will find us the length of the array
  int lengthOfArray = sizeof shape / sizeof *shape;

  for (int i = 0; i < lengthOfArray; i++)
  {
    this->CreateLayer(shape[i]);
  }

  this->m_networkDepth = lengthOfArray;
}

void NeuralNetwork::CreateNetwork()
{
}

void NeuralNetwork::CreateLayer(int size)
{
  // || In the future you can make it so that you pass in a different activation function
  m_layers.push_back(NeuralLayer(size, ActivationFunctions::relu));
}
