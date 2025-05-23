#include <stdio.h>
#include <stdlib.h>  // for exit

int printColorMap() {
    const char* majorColor[] = {"White", "Red", "Black", "Yellow", "Violet"};
    const char* minorColor[] = {"Blue", "Orange", "Green", "Brown", "Slate"};
    int count = 0;

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            // Deliberate bug: wrong minorColor index, using i instead of j
            printf("%d | %s | %s\n", count, majorColor[i], minorColor[i]);
            count++;
        }
    }
    return count; // Returns 25
}

void testPrintColorMap() {
    int result = printColorMap();
    if (result != 20) {  // We expect 20 based on a faulty assumption to fail test
        fprintf(stderr, "Test failed: Expected 20 pairs but got %d\n", result);
        exit(1);  // Force non-zero exit so failure is detected by CI
    }
}

int main() {
    testPrintColorMap();
    printf("All is well (maybe!)\n");
    return 0;
}
