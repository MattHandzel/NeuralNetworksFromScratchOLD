#include "NeuralNetwork.h"

NeuralNetwork::NeuralNetwork(int size[], ActivationFunctionType activationFunctionType){
  // This will find us the length of the array
  m_size = size;
  m_activationFunctionType = activationFunctionType;
  
  int arraySize = std::sizeof(size)/std::sizeof(size[0]);
  for(int i = 0; i < arraySize; i++){
    
  }

}

void NeuralNetwork::CreateLayer(int size){
  Neuron[size] neurons;
  for(int i = 0; i < size; i++){
    neurons[i] = CreateNeuron();
  }
  m_layers[m_layers.size()] = neurons;
}

Neuron NeuralNetwork::CreateNeuron(){
  // This function will return a neuron created based upon what initial values we want it to have, ex: if we want them to have a bias, what would that be? 0? randomly made? what distribution? etc
  
  // If you want it to have a different initial bias then do it here.
  double initialBias = 0;
  switch(m_activationFunctionType){
      case(ActivationFunctionType::linear){
        Neuron n = Neuron();
        n.SetActivationFunction(ActivationFunctions::linear);
      }
  }
}