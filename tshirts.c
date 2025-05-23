#include <stdio.h>
#include <assert.h>

// Function to determine t-shirt size based on centimeters
char size(int cms) {
    if (cms < 38) {
        return 'S'; // Small
    } else if (cms >= 38 && cms < 42) {
        return 'M'; // Medium
    } else {
        return 'L'; // Large
    }
}

// Test function to validate size determination
void testSize() {
    assert(size(37) == 'S'); // Expect Small
    assert(size(38) == 'M'); // Expect Medium (boundary case)
    assert(size(40) == 'L'); // <-- Deliberate failure here: 40 should be 'M', but test expects 'L'
    assert(size(42) == 'L'); // Expect Large (boundary case)
    assert(size(43) == 'L'); // Expect Large
}

int main() {
    testSize(); // Run tests
    printf("All is well (maybe!)\n");
    return 0;
}

