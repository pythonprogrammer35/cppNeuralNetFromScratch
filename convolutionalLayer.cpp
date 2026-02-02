#pragma once
#include <iostream>
#include <vector>
#include <cmath>
#include <random>
#include <chrono>
#include "vectorFunctions.cpp"
#include "Layer.cpp"

class convolutionalLayer: public Layer{
    public:
        /* This is 4D because it is a vector, holding each kernel, which has smaller
        *    matricies, which each have rows and colums
        */
        std::vector<std::vector<std::vector<std::vector<double>>>> kernels;
        std::vector<double> biases;
        double output_depth;
        int input_depth;
        int input_length;
        int input_width;
        

        convolutionalLayer(std::vector<int> input_shape, int kernel_shape, int output_depth){
            this->output_depth = output_depth;
            this->input_depth = input_shape[0];
            this->input_length = input_shape[1];
            this->input_width = input_shape[2];
            generateKernels(kernel_shape);
            generateBiases();
        }
        std::vector<std::vector<double>> input;
        //go through each kernel in the kernel matrix and cross correlate them with the matrix1
        std::vector<std::vector<std::vector<std::vector<double>>>> forward(std::vector<std::vector<double>> matrix1) {
            std::vector<std::vector<std::vector<std::vector<double>>>> holder;
            this->input = matrix1;
            return holder;
            
        }
        std::vector<std::vector<std::vector<std::vector<double>>>> backward(std::vector<std::vector<std::vector<double>>> output_gradient, double learning_rate) {
            std::vector<std::vector<std::vector<std::vector<double>>>> holder;
            return holder;
        }

        void generateKernels(int kernel_shape){
            double std_dev = std::sqrt(2.0/double(kernel_shape));
            unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();

            std::mt19937 gen(seed);

            std::normal_distribution<double> distrib(0.0, std_dev);

            double random_num;
            //for each kernel
            std::vector<std::vector<std::vector<std::vector<double>>>> holderKernel(
                this->output_depth, std::vector<std::vector<std::vector<double>>>(
                    input_depth, std::vector<std::vector<double>>(
                        kernel_shape, std::vector<double>(
                            kernel_shape, 0.0
                        )
                    )
            ));
            kernels = holderKernel;
            //printKernels();
            
            for(int i = 0; i < this->output_depth; i++){
                //for each sub matrix
                for(int j = 0; j < input_depth; j++){
                    //for each row
                    for(int k = 0; k < kernel_shape; k++){
                        //for each col(This is where the randomization needs to happen)
                        for(int w = 0; w < kernel_shape; w++){
                            random_num = (distrib(gen)) * std_dev;
                            kernels[i][j][k][w] = random_num;
                        }
                    }
                }
            }
                

        }
        void generateBiases(){
            std::vector<double> holder(kernels.size(), 0.0);
            biases = holder;
            double std_dev = std::sqrt(2.0/double(biases.size()));
            unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();

            std::mt19937 gen(seed);

            std::normal_distribution<double> distrib(0.0, std_dev);

            double random_num;


            for(int i = 0; i < biases.size(); i++){
                random_num = (distrib(gen)) * std_dev;
                biases[i] = random_num;
            }
        }
        
        void printKernels(){
            //for each kernel
            for(int i = 0; i < kernels.size(); i++){
                //for each submatrix
                std::cout << "Kernel " << i << std::endl;
                for(int j = 0; j < kernels[i].size(); j++){
                    std::cout << "Sub matrix " << j << std::endl;
                    printMatrix(kernels[i][j]);
                }
            }
        }
        

        virtual std::string getName() { return "Convolutional Layer"; }
};
/*
int main(){
    std::vector<int> input_dimensions = {1,28,28};
    convolutionalLayer layer(input_dimensions, 3, 5);
    std::vector<std::vector<double>> holder = {layer.biases};
    printMatrix(holder);


    return 0;
}*/