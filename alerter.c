#include <stdio.h>
#include <assert.h>

int alertFailureCount = 0;

// Stub function to simulate network alert
int networkAlertStub(float celcius) {
    printf("ALERT: Temperature is %.1f celcius.\n", celcius);
    return 500; // Change this to simulate different responses
}

// Function to convert Fahrenheit to Celsius and alert
void alertInCelcius(float farenheit) {
    float celcius = (farenheit - 32) * 5 / 9;
    int returnCode = networkAlertStub(celcius);
    if (returnCode != 200) {
        alertFailureCount += 1; // Increment failure count on non-200 response
    }
}

// Test function to validate alert behavior
void testAlertInCelcius() {
    alertFailureCount = 0; // Reset failure count
    alertInCelcius(400.5); // Should trigger alert
    assert(alertFailureCount == 1); // Expect 1 failure due to stub returning 500

    alertFailureCount = 0; // Reset for next test
    alertInCelcius(303.6); // Should trigger alert
    assert(alertFailureCount == 1); // Expect 1 failure again
}

int main() {
    testAlertInCelcius(); // Run tests
    printf("%d alerts failed.\n", alertFailureCount);
    return 0;
}
