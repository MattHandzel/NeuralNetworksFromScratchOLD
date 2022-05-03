#include <vector>
#include <functional>
#include <string>
#include "ActivationFunctions.h"

class Neuron{
 public:
    Neuron();
    Neuron(double bias);

    // This allows neurons to connect to each other
    void AddConnection(std::pair<Neuron*, double> connection);
    void AddConnection(Neuron neuron, double weight);
    void AddConnections(std::vector<std::pair<Neuron*, double>> connections);

    // Activation function
    void SetActivationFunction(std::function<double(double)> func);
    
    // Data STuff
    double GetValue();
    void SetValue(double value);

    std::vector<std::pair<Neuron *, double>> m_connections;

    std::string ConnectionsToString();

 private:
    double m_bias = 0;
    double m_weight = 0;    
    double m_value = 0;
  
    //double *m_activationFunction(double) = &Neuron::linear;
    std::function<double(double)> m_activationFunction = ActivationFunctions::linear;
};