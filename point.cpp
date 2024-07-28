#include<vector>
#include <random>
#include <ctime>

using namespace std;

class point{
public:
    float x;
    float y;
    float label;

    point(int height, int width){
        x = rnd(1,height);
        y = rnd(1,width);

        if(x > y){
            label = 1;
        } else {
            label = -1;
        }

    }
    
    
    float rnd(float min, float max) {

        srand(time(NULL)+rand());
	    return ((float)rand() / RAND_MAX) * (max - min) + min;

    }

};