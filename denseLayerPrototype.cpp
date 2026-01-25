#include <iostream>
#include <vector>
#include <cmath>
#include <random>
#include <chrono>

class Dense{
    public:
        std::vector<std::vector<double>> weights;
        std::vector<double> biases;
        int rows;
        int cols;

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
            
            biases = std::vector<double>(ncols, 0.0);
        }

        /*std::vector<std::vector<double>> forwardPass(){
            
        }
        //might change later if needed
        std::vector<std::vector<double>> backwardPass(){
            return nullptr;
        }*/
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
                holder2 += std::to_string(biases[i]);
                holder2 += ",";
            }
            holder += holder2;
            holder += "}";
            std::cout << holder;
        }
};

int main(){
    Dense layer(10,10);
    layer.printWeights();
    std::cout << " " << std::endl;
    layer.printBiases();

}
