// Online C++ compiler to run C++ program online
#include <iostream>
#include <random>
#include <string>
#include <array>
#include "time.h"
#include <vector>

#include "Neuron.h"
#include "ActivationFunctions.h"

std::pair<Neuron*, double> GetPair(Neuron neuron, double weight){
  return std::pair<Neuron*, double>(&neuron, weight);
}

int main() {
    Neuron n0 = Neuron(1);
    Neuron n1 = Neuron(0);
    Neuron n2 = Neuron(0);

    n0.SetActivationFunction(Neuron::linear);
    n1.SetActivationFunction(Neuron::linear);
    n2.SetActivationFunction(Neuron::linear);
  
    n2.AddConnection(std::pair<Neuron*, double>(&n1, 1));
    n1.AddConnection(GetPair(n0, 1));
  
    std::cout << n2.GetValue();
    
    return 0;
}