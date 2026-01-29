#include <iostream>
#include <vector>
#include <cmath>
#include <random>
#include <chrono>
#include "vectorFunctions.cpp"
#include "activationLayer.cpp"
#include "denseLayer.cpp"
#include "Layer.cpp"
#include "errorCalc.cpp"
#include <utility>




//training loop
//input becomes the output, I think i'll just have output be the default name to keep confusion to a minimum
std::vector<std::vector<double>> passThroughNeuralNetForward(std::vector<Layer*>& neuralNet, std::vector<std::vector<double>> output){
    double error = 0;
    
    for(int k = 0; k < neuralNet.size(); k++){
        output = neuralNet[k]->forward(output);
    }
    return output;

}

std::vector<std::vector<double>> passThroughNeuralNetBackward(std::vector<Layer*>& neuralNet, std::vector<std::vector<double>> gradients, double learning_rate){
    for(int k = neuralNet.size()-1; k>=0; k--){
            gradients = neuralNet[k]->backward(gradients, learning_rate);
    }
    return gradients;
}

double networkTest(std::vector<Layer*>& neuralNet,  std::vector<std::vector<std::vector<double>>> trainingSetX, std::vector<std::vector<std::vector<double>>> trainingSetY) {
    double error = 0;
    
    for(int i = 0; i < trainingSetX.size(); i++){
        auto returnedOutput = passThroughNeuralNetForward(neuralNet,trainingSetX[i]);
        error += MSE(trainingSetY[i], returnedOutput);
    }
    return error;
}

void trainingLoop(std::vector<Layer*>& neuralNet, std::vector<std::vector<std::vector<double>>> trainingSetX, std::vector<std::vector<std::vector<double>>> trainingSetY, int epochs, double learning_rate){
    std::vector<std::vector<double>> output;
    std::vector<std::vector<double>> gradients;
    double error = 0;
    double returnedError = 0;
    for(int i = 0; i<epochs; i++){
        for(int j = 0; j<trainingSetX.size(); j++){
            output = trainingSetX[j];

            //forward prop step
            output = passThroughNeuralNetForward(neuralNet, output);
            
            //error and gradient calculation
            error += MSE(trainingSetY[j], output);
            

            gradients = MSEDerivative(trainingSetY[j], output);
            //backprop
            passThroughNeuralNetBackward(neuralNet, gradients, learning_rate);
        }

        //print error
        if(i % 100 == 0){
            error = error/100;
            std::cout << "epoch: " << i << std::endl;
            std::cout<< "error: " << error << std::endl;
            error = 0;
        }
    }
}


/*std::vector<std::vector<double>> testingLoop(){

}*/

int main(){
    /*The hidden rule for this XOR type game is that if the index of the 
    * first column is a 1, the output is a one. If it is a 0, the output is a zero.

    */
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

    //Modular Training Loop
    trainingLoop(neuralNet, trainingSetX, trainingSetY, epochs, learning_rate);
    
    //Final pass through test
    std::cout << "Final error:" << std::endl;
    std::cout << (double) networkTest(neuralNet, trainingSetX, trainingSetY) << std::endl;

    //testing portion
    std::vector<std::vector<double>> testInput = {
        {0,0,1,0}
    };

    std::vector<std::vector<double>> returnedOutput = passThroughNeuralNetForward(neuralNet, testInput);

    std::cout << "Test output" << std::endl;
    printMatrix(returnedOutput);

    return 0;
}
