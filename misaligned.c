#include <stdio.h>
#include <assert.h>

// Function to print color map
int printColorMap() {
    const char* majorColor[] = {"White", "Red", "Black", "Yellow", "Violet"};
    const char* minorColor[] = {"Blue", "Orange", "Green", "Brown", "Slate"};
    int count = 0;

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            // Deliberate bug: wrong minorColor index, changed to use i instead of j
            printf("%d | %s | %s\n", count, majorColor[i], minorColor[i]);
            count++;
        }
    }
    return count; // Return total count of color pairs
}

// Test function to validate color map printing, deliberately fails
void testPrintColorMap() {
    int result = printColorMap();
    assert(result == 20); // Fail: 25 expected, test expects wrong 20 causing assertion failure
}

int main() {
    testPrintColorMap();
    printf("All is well (maybe!)\n");
    return 0;
}
