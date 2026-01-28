#pragma once  
#include <iostream>
#include <vector>
#include <cmath>
#include <random>
#include <chrono>
#include "vectorFunctions.cpp"
#include "Layer.cpp"

class activationLayer: public Layer{
    public:
        std::vector<std::vector<double>> input;
        std::string layerChoice;
        //store the passed through values from sigmoid perhaps to save time for back prop
        activationLayer(std::string desiredFunction){
            this->layerChoice = desiredFunction;
        }

        std::vector<std::vector<double>> forward(std::vector<std::vector<double>> passedMatrix) override {
            this->input = passedMatrix;
            if(layerChoice == "ReLU"){
                return(ReLU(passedMatrix));
            } else if(layerChoice == "Sigmoid"){
                return(Sigmoid(passedMatrix));
            }
            return(Sigmoid(passedMatrix));
            
        }

        std::vector<std::vector<double>> backward(std::vector<std::vector<double>> backwardsInput, double learning_rate) override {
            std::vector<std::vector<double>> holder;
            
            if(layerChoice == "ReLU"){
                holder = ReLUDeriv(this->input);
            } else if(layerChoice == "Sigmoid"){
                holder = SigmoidDeriv(this->input);
            }
            holder = elementMatrixMulti(holder, backwardsInput);
            return holder;

        }

        std::vector<std::vector<double>> Sigmoid(std::vector<std::vector<double>> passedMatrix){

            for(int i = 0; i<passedMatrix.size(); i++){
                for(int j = 0; j<passedMatrix[0].size(); j++){
                    passedMatrix[i][j] = (1.0 /(1.0 + std::exp(-passedMatrix[i][j])));
                }
            }
            return passedMatrix;
        }

        std::vector<std::vector<double>> SigmoidDeriv(std::vector<std::vector<double>> passedMatrix){

            for(int i = 0; i<passedMatrix.size(); i++){
                for(int j = 0; j<passedMatrix[0].size(); j++){
                    passedMatrix[i][j] = (1.0 - (1.0 /(1.0 + std::exp(-passedMatrix[i][j]))));
                }
            }
            return passedMatrix;
        }
        //Might try to optimize this at a later date by passing input as a reference
        std::vector<std::vector<double>> ReLU(std::vector<std::vector<double>> input){
            for(int i = 0; i<input.size(); i++){
                for(int j = 0; j<input[0].size(); j++){
                    if(input[i][j] > 0){
                        input[i][j] *= 1;
                    } else if (input[i][j] <= 0){
                        input[i][j] *= 0;
                    }
                }
            }
            return input;
        }



        std::vector<std::vector<double>> ReLUDeriv(std::vector<std::vector<double>> input){
            for(int i = 0; i<input.size(); i++){
                for(int j = 0; j<input[0].size(); j++){
                    if(input[i][j] > 0){
                        input[i][j] == 1;
                    } else if (input[i][j] <= 0){
                        input[i][j] == 0;
                    }
                }
            }
            return input;
        }
};

