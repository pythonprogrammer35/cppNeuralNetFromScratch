#include <iostream>
#include <vector>
#include <cmath>
#include <random>
#include <chrono>
#include "vectorFunctions.cpp"


//matrix1 is the training data(what the output should be)(yi) and matrix2 is the output of the network(yi^)
double MSE(std::vector<std::vector<double>> matrix1, std::vector<std::vector<double>> matrix2){
    double result = 0;

    for(int i = 0; i<matrix1.size(); i++){
        for(int j = 0; j<matrix1[0].size(); j++){
            result += std::pow(matrix1[i][j] - matrix2[i][j], 2.0);
        }
    }
    result = ((1.0/matrix1.size()) * result);
    return result;
}
//matrixs must be the same size(they really should be because they are being compared to the matrixes in the training dataset)
std::vector<std::vector<double>> MSEDerivative(std::vector<std::vector<double>> matrix1, std::vector<std::vector<double>> matrix2){
    std::vector<std::vector<double>> result(matrix1.size(), std::vector<double>(matrix1[0].size(), 0));
    for(int i = 0; i<matrix1.size(); i++){
        //std::cout << "hey" << std::endl;
        for(int j = 0; j<matrix1[0].size(); j++){
            result[i][j] = ((-2.0/matrix1.size())*(matrix1[i][j] - matrix2[i][j]));
        }
    }
    return result;
}

/*int main(){
    //Test

    //What the data should be(yi)
    std::vector<std::vector<double>> input = {
        {0,1,0,0,0,0,0,0,0,0}  
    };
    //What the data is(yi^)
    std::vector<std::vector<double>> output = {
        {0,0,1,0,0,0,0,0,0,0}  
    };
    double result = MSE(input, output);
    std::vector<std::vector<double>> resultD = MSEDerivative(input, output);

    std::cout << "MSE:" << std::endl;
    std::cout << result << std::endl;

    std::cout << "resultD" << std::endl;

    printMatrix(resultD);
    

}*/
