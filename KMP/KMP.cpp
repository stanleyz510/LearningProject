// KMP implementation

#include <cstdlib>
#include <cstring>


void get_overlap(char *p, int *p_succ, int size) {
    // Implement the overlap array
}

int KMP_locate(char* t, char* p) {
    int t_size = strlen(t);
    int p_size = strlen(p)

    if (t_size <= 0 || p_size <= 0) {
        return -1;
    }
    
    int *p_succ = malloc(sizeof(int) * p_size);
    get_overlap(*p, *p_succ, p_size);

    // Implement the search

}

int main() {
    char *target = "abababbaabbacabba";
    char *pattern = "ac";

    KMP_locate(target, pattern);

}
