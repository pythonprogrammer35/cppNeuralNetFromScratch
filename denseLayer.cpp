#pragma once
#include <iostream>
#include <vector>
#include <cmath>
#include <random>
#include <chrono>
#include "vectorFunctions.cpp"
#include "Layer.cpp"

class Dense: public Layer{
    public:
        std::vector<std::vector<double>> weights;
        std::vector<std::vector<double>> biases;
        int rows;
        int cols;
        int batch_size = 1;
        std::vector<std::vector<double>> input;

        Dense(int rowsInput, int colsInput){
            rows = rowsInput;
            cols = colsInput;
            generateWeights(rows, cols);
            generateBiases(cols);
            
        }

        void generateWeights(int nrows, int ncols){
            for(int i = 0; i < nrows; i++){
                std::vector<double> holderWeight;
                weights.push_back(holderWeight);
            }
            double std_dev = std::sqrt(2.0/double(nrows));
            unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();

            std::mt19937 gen(seed);

            std::normal_distribution<double> distrib(0.0, std_dev);

            double random_num;
            for(int i = 0; i < weights.size(); i++){
                for(int j = 0; j < ncols; j++){
                    random_num = (distrib(gen)) * std_dev;
                    weights[i].push_back(random_num);
                }
            }

            
        }
        void generateBiases(int ncols){
            
            std::vector<std::vector<double>> holder(batch_size, std::vector<double>(ncols, 0));
            this->biases = holder;
        }


        std::vector<std::vector<double>> forward(std::vector<std::vector<double>> input) override {
            this->input = input;
            std::vector<std::vector<double>> resultedMatrix = matrixMult(input, weights);
            //printMatrix(resultedMatrix);
            resultedMatrix = biasAdd(resultedMatrix, biases);
            return resultedMatrix;
            
        }
        //might change later if needed
        std::vector<std::vector<double>> backward(std::vector<std::vector<double>> derivativeYMatrix, double learning_rate) override {
            std::vector<std::vector<double>> derivativeXMatrix = matrixMult(weights, transpose(derivativeYMatrix));
            std::vector<std::vector<double>> derivativeWMatrix = matrixMult(transpose(this->input),derivativeYMatrix);
            derivativeWMatrix = elementMulti(derivativeWMatrix, learning_rate);
            this->weights = elementSubtract(weights, derivativeWMatrix);
            this->biases = derivativeYMatrix;
            return transpose(derivativeXMatrix); 
        }
        void printWeights(){
            std::string holder = "";
            std::string holder2 = "{";
            for (int i = 0; i<weights.size(); i++){
                for(int j = 0; j<weights[0].size(); j++){
                    holder2 += std::to_string(weights[i][j]);
                    holder2 += ",";
                }
                holder += holder2;
                holder += "}";
                holder2 = "{";
            }
            std::cout << holder;
        }
        void printBiases(){
            std::string holder = "";
            std::string holder2 = "{";
            for (int i = 0; i<biases.size(); i++){
                for(int j = 0; j<biases[0].size(); j++){
                    holder2 += std::to_string(biases[i][j]);
                    holder2 += ",";
                }
                holder += holder2;
                holder += "}";
                holder2 = "{";
            }
            std::cout << holder;
        }
        virtual std::string getName() override { return "Dense Layer"; }
};
/*
int main(){
    Dense layer(4,10);
    layer.printWeights();
    std::cout << " " << std::endl;
    //layer.printBiases();
    std::vector<std::vector<double>> input = {
        {0,1,0,0},   
    };

    std::vector<std::vector<double>> output = {
        {0,0,1,0,0,0,0,0,0,0},   
    };
    layer.forwardPass(input);
    std::vector<std::vector<double>> holder = layer.backwardPass(output, 0.001);
    layer.printWeights();
    std::cout << "heeey";
    printMatrix(holder);
    

}*/
