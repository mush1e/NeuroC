#include <stdio.h>
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
    return (float)rand() / (float)RAND_MAX * 10.0f;
}

float loss(float w) {
    float result = 0.0f;

    for (size_t i = 0; i < train_count; ++i) {
        float x = train[i][0];
        float y = x*w;
        float d = y - train[i][1];
        result += d*d;
    }
    result /= train_count;
    return result;
}

int main() {
    srand(69);

    float w = rand_float();
    float eps = 1e-3;
    float learning_rate = 1e-3;

    for (size_t i = 0; i < 500; ++i) {
        float dloss = (loss(w+eps) - loss(w)) / eps;
        w -= learning_rate * dloss;
        printf("loss : %f , value : %f\n", loss(w) , w);
    }

    return 0;
}