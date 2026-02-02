# C++ Neural Network from Scratch

![Language](https://img.shields.io/badge/language-C++-00599C.svg)
![License](https://img.shields.io/badge/license-MIT-green)
![Status](https://img.shields.io/badge/status-Active-brightgreen)

A high-performance, fully connected Deep Neural Network (DNN) implemented entirely in C++ without the use of external machine learning libraries like PyTorch or TensorFlow.

The goal of this project is to demystify the "black box" of AI by manually implementing the core mathematical engines: Matrix Calculus, Backpropagation, and Gradient Descent.

## Features

* **Custom Matrix Engine**: A linear algebra library built from scratch handling dot products, transpositions, and element-wise operations.
* **Modular Layer Architecture**: Dynamic `Dense` layers supporting variable input/output sizes.
* **Activation Function**:
    * **ReLU**: With He Initialization for hidden layers.
* **Optimization**: Stochastic Gradient Descent (SGD) with Mean Squared Error (MSE) loss.
* **No External Dependencies**: Uses only the C++ Standard Library.
* **Plans for the Future**: Implement Convolutional Layers and CUDA optimization to allow for GPU assisted GEMM

---

## Mathematical Implementation

This project follows the **Row-Major** convention used by standard frameworks (TensorFlow/PyTorch) for memory efficiency with batch processing.

### 1. Forward Propagation
Data is processed in batches where rows represent samples.
$$Y = X \cdot W + B$$
* **Input ($X$)**: Shape $(BatchSize \times Inputs)$
* **Weights ($W$)**: Shape $(Inputs \times Outputs)$
* **Output ($Y$)**: Shape $(BatchSize \times Outputs)$

### 2. Loss Function (MSE)
We use the Mean Squared Error cost function. Note that the order of subtraction does not affect the derivative magnitude, only the sign convention.
$$E = \frac{1}{n} \sum (Y_{pred} - Y_{target})^2$$

**Derivative with respect to Output:**
$$\frac{\partial E}{\partial Y} = \frac{2}{n}(Y_{pred} - Y_{target})$$

### 3. Backward Propagation (Chain Rule)
The gradient flows backward through the network to update weights and biases.

**Gradient of Weights ($\frac{\partial E}{\partial W}$):**
To calculate the weight update, we multiply the Transposed Input by the Incoming Error.
$$\frac{\partial E}{\partial W} = X^T \cdot \frac{\partial E}{\partial Y}$$
* *Dimensional Logic:* $(Inputs \times Batch) \cdot (Batch \times Outputs) \rightarrow (Inputs \times Outputs)$

**Gradient of Biases ($\frac{\partial E}{\partial B}$):**
To calculate the bias update, we can see from the chain rule that when we derive with respect to b, we see that all b's in the equations become 1. 
Thanks to this we see that ($\frac{\partial E}{\partial B}$) is simply equal to ($\frac{\partial E}{\partial Y}$)

**Gradient of Inputs ($\frac{\partial E}{\partial X}$):**
To pass error to the previous layer, we multiply Weights by the Incoming Error Transposed and then transpose the finale result.
$$\frac{\partial E}{\partial X} =  W \cdot \frac{\partial E}{\partial Y}^T$$ and then transpose the final result to give us a row vector to pass backwards
* *Dimensional Logic:* $(Batch \times Outputs) \cdot (Outputs \times Inputs) \rightarrow (Batch \times Inputs)$

---

## Installation and Testing
git clone the repository and run the train.cpp file. Then run the train executable which is done with ./train 
