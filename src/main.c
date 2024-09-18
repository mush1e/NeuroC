#include <stdio.h>
#include <stdlib.h>
#include <time.h>

float rand_float() {
    return (float)rand() / (float)RAND_MAX;
}

// Training set for OR gate
float train[][3] = {
    {0, 0, 0},
    {1, 0, 1},
    {0, 1, 1},
    {1, 1, 1},
};

// Training set size
#define train_size sizeof(train) / sizeof(train[0])

// Cost function with bias
float cost(float w1, float w2, float b) {
    float result = 0;
    for (size_t i = 0; i < train_size; i++) {
        float x1 = train[i][0];
        float x2 = train[i][1];
        // Include the bias term
        float y = (x1 * w1 + x2 * w2 + b) >= 0.5 ? 1 : 0;
        float d = y - train[i][2];
        result += d * d;
    }
    result /= train_size;
    return result;
}

int main(void) {
    srand(69);
    float w1 = rand_float();
    float w2 = rand_float();
    float b = rand_float();  // Initialize bias

    float eps = 1e-3;
    float learning_rate = 1e-3;  // Increased learning rate
    float c = cost(w1, w2, b);
    
    for (int i = 0; i < 500; i++) {

        // Calculate gradient approximations
        float dw1 = (cost(w1 + eps, w2, b) - c) / eps;
        float dw2 = (cost(w1, w2 + eps, b) - c) / eps;
        float db  = (cost(w1, w2, b + eps) - c) / eps;

        // Update weights and bias (apply learning rate to bias)
        w1 -= learning_rate * dw1;
        w2 -= learning_rate * dw2;
        b -= learning_rate * db;  // Apply learning rate to bias

        c = cost(w1, w2, b);
        printf("loss : %f , weight1 : %f, weight2 : %f, bias : %f\n", c, w1, w2, b);
    }

    return 0;
}
