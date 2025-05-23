#include <stdio.h>
#include <assert.h>

// Function to print color map
int printColorMap() {
    const char* majorColor[] = {"White", "Red", "Black", "Yellow", "Violet"};
    const char* minorColor[] = {"Blue", "Orange", "Green", "Brown", "Slate"};
    int count = 0;

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            printf("%d | %s | %s\n", count, majorColor[i], minorColor[j]); // Fixed minorColor index
            count++;
        }
    }
    return count; // Return total count of color pairs
}

// Test function to validate color map printing
void testPrintColorMap() {
    int result = printColorMap();
    assert(result == 25); // Expect 25 pairs
}

int main() {
    testPrintColorMap(); // Run tests
    printf("All is well (maybe!)\n");
    return 0;
}
