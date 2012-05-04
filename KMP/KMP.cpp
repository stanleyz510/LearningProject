// KMP implementation

#include <cstdlib>
#include <cstring>
#include <iostream>

using namespace std;

void get_overlap(char *p, int *p_succ, int size) {
    // Implement the overlap array
    int n = 1;
    p_succ[0] = 0;
    while (n<size) {
        if (p[n] == p[p_succ[n-1]]) {
            p_succ[n] = p_succ[n-1] + 1; 
        }
        else if (p[n] == p[0]) {
            p_succ[n] = 1;
        }
        else {
            p_succ[n] = 0;
        }
        n++;
    }
}

int KMP_locate(char* t, char* p) {
    int t_size = strlen(t);
    int p_size = strlen(p);

    if (t_size <= 0 || p_size <= 0) {
        return -1;
    }
    
    // Generate the overlap array
    int *p_succ = (int*)malloc(sizeof(int) * p_size);
    get_overlap(p, p_succ, p_size);

    // output for debug
    for(int i=0; i<p_size; i++) {
        cout<<p[i]<<":["<<p_succ[i]<<"]\t"<<endl;
    }
    
    // Implement the search
    int i = 0;
    while(i<t_size) {
        int j = 0;
        while ( i+j < t_size && t[i+j] == p[j]) {
            if (j == p_size - 1) {   // Found
                return i;
            }
            j++;
        }
        if (j>0) {
            i += j - p_succ[j-1];
        }
        else {
            i++;
        }
    }
    return -1;
}

int main() {
    char *target = "aaaaaaaaaaaaaaaaaaaaaaaaaaaab";
    char *pattern = "ab";

    int index = KMP_locate(target, pattern);
    cout << target << strlen(target) << endl;
    cout << pattern << strlen(pattern) << endl;
    cout << "Found the pattern at: " << index << endl;

}
