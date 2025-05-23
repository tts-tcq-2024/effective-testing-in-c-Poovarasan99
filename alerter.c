#include <stdio.h>
#include <assert.h>

int alertFailureCount = 0;

// Stub function to simulate network alert, returns failure always to simulate issues
int networkAlertStub(float celcius) {
    printf("ALERT: Temperature is %.1f celcius.\n", celcius);
    return 500; // Always returns failure
}

// Function to convert Fahrenheit to Celsius and alert
void alertInCelcius(float farenheit) {
    float celcius = (farenheit - 32) * 5 / 9;
    int returnCode = networkAlertStub(celcius);
    if (returnCode != 200) {
        // BUG: Failure count is not incremented (simulates bug)
        alertFailureCount += 0; // Should be += 1, but deliberately left broken
    }
}

// Test function to validate alert behavior, deliberately fails
void testAlertInCelcius() {
    alertFailureCount = 0;
    alertInCelcius(400.5);
    assert(alertFailureCount == 1); // Will fail since alertFailureCount remains 0

    alertFailureCount = 0;
    alertInCelcius(303.6);
    assert(alertFailureCount == 1); // Will fail again
}

int main() {
    testAlertInCelcius();
    printf("%d alerts failed.\n", alertFailureCount);
    return 0;
}
