#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

class RandomList {
private :
    vector<int> *weights;            // possibilities.
    int getSum();
public:
    RandomList(int size);
    int getSize(){ return this->weights->size(); }
    void printPossibilities();
    int getRandomElement();
    int getPseudoRandomElement();
};

RandomList::RandomList(int size){
    this->weights = new vector<int>(size);
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
    // found i when it stops
    while(target < this->getSize() && (randomindex -= this->weights->at(target)) > 0) {
        target++;
    }
    // auto calibrate the possibilities.
    for(int i=0; i<this->weights->size(); i++) {
        i != target ? this->weights->at(i) += 1000 : this->weights->at(i) = 1;
    }
    return target;
}

// Test function
int main() {
    int range, tries;
    while(1) {
        cout << "please input the range of selection: ";
        cin >> range;
        cout << "please input how many tries you like to have : ";
        cin >> tries;
        vector<int> *ro = new vector<int>(range);
        vector<int> *pro = new vector<int>(range);
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
        cout << "Random Distribution: \n";
        for(int i=0; i<ro->size(); i++) {
            cout << i << ": " << ro->at(i) << "\n";
        }
    }
}
