#include <iostream>
#include <vector>
#include <cmath>
#include <random>
#include <chrono>
#include "vectorFunctions.cpp"
#include "activationLayer.cpp"
#include "denseLayer.cpp"
#include "Layer.cpp"





//training loop
int main(){
    std::vector<std::vector<std::vector<double>>> trainingSetX = {
        {{1,0,0,0}},
        {{1,1,0,0}},
        {{0,1,0,0}},
        {{0,0,1,0}}
    };

    std::vector<std::vector<std::vector<double>>> trainingSetY = {
        {{1}},
        {{1}},
        {{0}},
        {{0}}
    };

    int epochs = 10000;
    double learning_rate = 0.01;

    std::vector<Layer*> neuralNet = {
        new Dense(4,10), 
        new activationLayer("ReLU"), 
        new Dense(10, 1), 
        new activationLayer("Sigmoid")
    };
    std::vector<std::vector<double>> output;
    std::vector<std::vector<double>> gradients;
    std::vector<std::vector<double>> input;
    double error = 0;

    for(int i = 0; i<10000; i++){
        for(int j = 0; j<trainingSetX.size(); j++){
            output = trainingSetX[j];
            for(int k = 0; k < neuralNet.size(); k++){
                output = neuralNet[k].forward(output);
            }
            error = MSE(trainingSetY[j],output);

            gradients = MSEDeriv(trainingSetY[j], output);

            for(int k = neuralNet.size()-1; k>=0; k--){
                gradients = neuralNet[k].backward(gradients, learning_rate);
            }
            
        }
        
    }
    return 0;
}
