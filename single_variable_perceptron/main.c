#include <stdio.h>
#include <time.h>
#include <stdlib.h>

float train[][2] = {
    {0, 0},
    {1, 2},
    {2, 4},
    {3, 6},
    {4, 8},
};
#define train_count sizeof(train)/sizeof(train[0])

float rand_float() {
    return (float)rand() / (float)RAND_MAX;
}

float loss(float w, float b) {
    float result = 0.0f;

    for (size_t i = 0; i < train_count; ++i) {
        float x = train[i][0];
        float y = x*w + b; 
        float d = y - train[i][1];
        result += d*d;
    }
    result /= train_count;
    return result;
}

int main() {
    srand(69);

    float w = rand_float() * 10.0f;
    float b = rand_float() * 5.0f;
    float eps = 1e-3;
    float learning_rate = 1e-3;

    for (;loss(w,b) > 1e-4;) {
        float dw = (loss(w + eps, b) - loss(w, b)) / eps;
        float db = (loss(w, b + eps) - loss(w, b)) / eps;
        w -= learning_rate * dw;
        b -= learning_rate * db;
        printf("loss : %f , value : %f, bias : %f\n", loss(w,b) , w, b);
    }

    return 0;
}
