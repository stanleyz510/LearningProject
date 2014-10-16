#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <cmath>

using namespace std;

class RandomList {
private :
    vector<ulong> *weights;            // possibilities.
    int getSum();
public:
    RandomList(int size);
    int getSize(){ return this->weights->size(); }
    void printPossibilities();
    int getRandomElement();
    int getPseudoRandomElement();
};

RandomList::RandomList(int size){
    this->weights = new vector<ulong>(size);
    fill(this->weights->begin(), this->weights->end(), 1);
    srand(time(0));
}

int RandomList::getSum() {
    int sum = 0;
    for(int i : *this->weights) {
        sum += i;
    }
    return sum;
}

void RandomList::printPossibilities() {
    cout << "The Possibility is : \n";
    for(int i=0; i<this->getSize(); i++) {
        cout << i << ": " << this->weights->at(i) << "\n";
    }
}

int RandomList::getRandomElement() {
    int i =  rand() % this->getSize();
    return i;
}

int RandomList::getPseudoRandomElement() {
    int randomindex = rand() % this->getSum();
    int target = 0;
    // found target when it stops
    while(target < this->getSize() && (randomindex -= this->weights->at(target)) > 0) {
        target++;
    }
    // auto calibrate the possibilities.
    for(int i=0; i<this->weights->size(); i++) {
      if(i != target){
          this->weights->at(i) == 1 ? this->weights->at(i) = 100 : this->weights->at(i) *= 2;
      }
      else {
          this->weights->at(i) = 1;
      }
    }
    return target;
}

// calculate the Var(X)
double calvar(vector<uint> *v) {
    ulong sum = 0;
    for (uint &x : *v) {
        sum += x;
    }
    ulong mean = sum / v->size();

    ulong variance = 0;
    for (uint &x : *v) {
        variance += (x - mean) * (x - mean);
    }
    return sqrt(variance);

}

// Test function
int main() {
    int range, tries;
    cout.precision(3);
    while(1) {
        cout << "please input the range of selection: ";
        cin >> range;
        cout << "please input how many tries you like to have : ";
        cin >> tries;
        vector<uint> *ro = new vector<uint>(range);
        vector<uint> *pro = new vector<uint>(range);
        RandomList* rl = new RandomList(range);
        RandomList* prl = new RandomList(range);

        cout << tries << " times :" << endl;

        for(int i=0; i<tries; i++) {
            int r = prl->getPseudoRandomElement();
            pro->at(r) ++;
        }
        for(int i=0; i<tries; i++) {
            int r = rl->getRandomElement();
            ro->at(r) ++;
        }

        cout << "Pseudo Random Distribution: \n";
        for(int i=0; i<pro->size(); i++) {
            cout << i << ": " << pro->at(i) << "\n";
        }
        cout << "The Variance is " << calvar(pro) << endl;

        cout << "Random Distribution: \n";
        for(int i=0; i<ro->size(); i++) {
            cout << i << ": " << ro->at(i) << "\n";
        }
        cout << "The Variance is " << calvar(ro) << endl;
    }
}
