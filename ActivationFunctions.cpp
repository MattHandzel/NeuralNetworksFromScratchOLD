#include "ActivationFunctions.h""
#include <functional>
#include <cmath>



double ActivationFunctions::linear(double value){
      return value;
    }

double ActivationFunctions::sigmoid(double value){
    return 1 / (1 + pow(math.E, -value));
}

double ActivationFunctions::tanh(double value){
      return (1 / (1 + pow(math.E, -value)) - 0.5) * 2;
  }

double ActivationFunctions::relu(double value){
    return (((double)(-1) ^ value) < 0) * value;
}