#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;

const int SAMPLES = 20;

class RandomList {
private :
    vector<int> *group;
    int getSize(){ return this->group->size(); }
    int output(int i) { this->group->at(i) ++; return i; }
    int translateTimesToPossibility(int times);
public:
    RandomList();
    RandomList(int size);
    int getRandomElement();
    int getPseudoRandomElement();
    void outputDistribution();
};

RandomList::RandomList(int size){
    this->group = new vector<int>(size);
}

RandomList::RandomList() {
    new (this)RandomList(20);
}

int RandomList::translateTimesToPossibility(int times){
    if(times==0) {
        return 1;
    }
    else {
        return times * 10;
    }
}

int RandomList::getRandomElement() {
    int i =  rand() % this->getSize();
    return output(i);
}

int RandomList::getPseudoRandomElement() {
    int range = 0;
    for(int i=0; i<this->getSize(); i++) {
        range += translateTimesToPossibility(this->group->at(i));
    }
    int randomindex = rand() % range;
    for(int i=0; i<this->getSize(); i++) {
        if (randomindex - translateTimesToPossibility(this->group->at(i)) < 0) {
            return i;
        }
    }
    // for some reason, no pseudo random returned. just return a plan random number.
    return this->getRandomElement();
}

void RandomList::outputDistribution() {
    cout << "Total elements: " << getSize() << endl;
    for(int i=0; i<getSize(); i++) {
        cout << i << "\t: ";
        cout << this->group->at(i);
        cout << "\n";
    }
    cout.flush();
}


// Test
int main() {
    RandomList* rl = new RandomList();
    cout << SAMPLES << " times :" << endl;
    for(int i=0; i<SAMPLES; i++) {
        rl->getPseudoRandomElement();
    }
    rl->outputDistribution();
}
