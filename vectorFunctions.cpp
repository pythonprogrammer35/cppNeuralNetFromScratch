#include <iostream>
#include <vector>


std::vector<std::vector<double>> matrixMult(std::vector<std::vector<double>> vector1, std::vector<std::vector<double>> vector2){
    std::vector<double> vect1;
    std::vector<double> vect2;
    double holder = 0;
    std::vector<std::vector<double>> result(vector1.size(), std::vector<double>(vector2[0].size(), 0));

    // for every row in vector1, go through every value in every column of vector2
    for(int i = 0; i<vector1.size(); i++){
        vect1 = vector1[i];
        for(int j = 0; j<vector2[0].size(); j++){
            //This part is where the calculation is run
            for(int k = 0; k < vector2.size(); k++){
                holder += vect1[k] * vector2[k][j];
            }
            result[i][j] = holder;
            holder = 0;
        }
    }
    return result;
}

std::vector<std::vector<double>> biasAdd(std::vector<std::vector<double>> vector1, std::vector<std::vector<double>> vector2){
    std::vector<std::vector<double>> result = vector1;
    for(int k = 0; k<vector2.size(); k++){
        for (int i = 0; i<vector1.size(); i++){
            for(int j = 0; j<vector1[0].size(); j++){
                vector1[i][j] += vector2[k][j];
            }
        }
    }
    return result;
}

std::vector<std::vector<double>> transpose(std::vector<std::vector<double>> matrix){
    std::vector<std::vector<double>> result(matrix[0].size(), std::vector<double>(matrix.size(), 0));

    for(int i = 0; i<matrix.size(); i++){
        for(int j = 0; j<matrix[0].size(); j++){
            result[j][i] = matrix[i][j];
        }
    }
    return result;
}
//each value of matrix1 times factor
std::vector<std::vector<double>> elementMulti(std::vector<std::vector<double>> matrix1, double factor){
    std::vector<std::vector<double>> result(matrix1.size(), std::vector<double>(matrix1[0].size(), 0));

    for(int i = 0; i<matrix1.size(); i++){
        for(int j = 0; j<matrix1[0].size(); j++){
            result[i][j] = matrix1[i][j] * factor;
        }
    }
    return result;
}
//matrix1 * matrix2
std::vector<std::vector<double>> elementMatrixMulti(std::vector<std::vector<double>> matrix1, std::vector<std::vector<double>> matrix2){
    std::vector<std::vector<double>> result(matrix1.size(), std::vector<double>(matrix1[0].size(), 0));

    for(int i = 0; i<matrix1.size(); i++){
        for(int j = 0; j<matrix1[0].size(); j++){
            result[i][j] = matrix1[i][j] * matrix2[i][j];
        }
    }
    return result;
}
//matrix1 - matrix2
std::vector<std::vector<double>> elementSubtract(std::vector<std::vector<double>> matrix1, std::vector<std::vector<double>> matrix2){
    std::vector<std::vector<double>> result(matrix1.size(), std::vector<double>(matrix1[0].size(), 0));

    for(int i = 0; i<matrix1.size(); i++){
        for(int j = 0; j<matrix1[0].size(); j++){
            result[i][j] = matrix1[i][j] - matrix2[i][j];
        }
    }
    return result;
}
void printMatrix(std::vector<std::vector<double>> inputMatrix){
    std::string holder = "";
    std::string holder2 = "{";
    for (int i = 0; i<inputMatrix.size(); i++){
        for(int j = 0; j<inputMatrix[0].size(); j++){
            holder2 += std::to_string(inputMatrix[i][j]);
            holder2 += ",";
        }
        holder += holder2;
        holder += "}";
        holder2 = "{";
    }
    std::cout << holder;
}

/*int main(){
    std::vector<std::vector<double>> tester1 = {
        {3,2,1},
        {4,3,2}
        
    };
    std::vector<std::vector<double>> tester2 = {
        {1,4,2},
        {2,6,2},
        {3,3,2}
    };
    std::vector<std::vector<double>> output = transpose(tester1);

    std::string holder = "";
    std::string holder2 = "{";
    for (int i = 0; i<output.size(); i++){
        for(int j = 0; j<output[0].size(); j++){
            holder2 += std::to_string(output[i][j]);
            holder2 += ",";
        }
        holder += holder2;
        holder += "}";
        holder2 = "{";
    }
    std::cout << holder;

    output = transpose(output);

    holder = "";
    holder2 = "{";
    for (int i = 0; i<output.size(); i++){
        for(int j = 0; j<output[0].size(); j++){
            holder2 += std::to_string(output[i][j]);
            holder2 += ",";
        }
        holder += holder2;
        holder += "}";
        holder2 = "{";
    }
    std::cout << holder;

}*/
