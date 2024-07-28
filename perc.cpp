#include<vector>
#include <random>
#include <ctime>
#include<iostream>


using namespace std;

class perceptron{

public:
    vector<float> inputs;
    vector<float> weights;
    float learningRate = 0.1;
    float totalError = 0;

    /*
        calling the constructor and initializing the weights randomly. for convention sake it's between -1,1. The
        inputs are not scaled so any other reasonable values can be used.
    */
    perceptron(){

        inputs.resize(2);
        weights.resize(2);

        for (int i = 0; i < weights.size(); i++){
            weights[i] = rnd(-11,11); 
        }
            
    }

    /*
        This is the function that does the assumptions based on the weights. This does half of the magic of perceptrons.
        the other half is the training part.
    */
    int think(vector<float> &inputs){

        float sum = 0;
        for (int i = 0; i < inputs.size(); i++){
            sum += inputs[i]*weights[i];
        }
        return act(sum);

    }


    /*
        This is the special sauce. It nudges the weight towards their optimal values based on the learning rate. although
        gradient descent would've been more optimal. I'm too dumb to implement that :3
    */
    void train(vector<float> &input, int target){
        int guess = think(input);
        int error = target - guess;
        for (int i = 0; i < weights.size(); i++){
            weights[i] = weights[i] + (error*input[i]*learningRate);
        }

    }

    vector<float> getWeights(){
        return weights;
    }

    /*
        this is the all important activation function. In this case, it's just a simple sign function that returns the
        sign of the input value.
    */
    int act(float x){
        if(x>=0){
            return 1;
        } else {
            return -1;
        }
    }

    /*
        This is just a random number generator I got from stackoverflow :p It returns a random float
    */

    float rnd(float min, float max) {

        srand(time(NULL)+rand());
	    return ((float)rand() / RAND_MAX) * (max - min) + min;

    }



};