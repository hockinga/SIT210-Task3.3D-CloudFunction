// Constants
const int NUM_BLINKS = 3; // Number of LED flashes per event
const int RED_LED = D8;   // Location of the red LED


/**
 * Setup the LED and setup the device to receive wave and pat events
 */
void setup() {

    // Setup the LED
    pinMode(RED_LED, OUTPUT);

    // Handle received pat and wave events
    Particle.subscribe("Deakin_RIOT_SIT210_Photon_Buddy", myHandler);
}


void loop() {

}


/**
 * Blinks the LED after receiving a wave or pat from the buddy device
 *
 * @param event the name of the buddy's published event
 * @param data the data sent in the buddy's published event
 */
void myHandler(const char *event, const char *data) {

    // Blink three times for a wave or pat
    if (strcmp(data, "wave") == 0) {

        // Fast blinks for a wave
        blink(RED_LED, 500);

    } else if (strcmp(data, "pat") == 0) {

        // Slow blinks for a pat
        blink(RED_LED, 1000);

    }

    // Don't blink for anything else
}


/**
 * Blinks an LED multiple times at a certain speed
 *
 * @param led the LED to blink
 * @param delay_time the duration of each blink (millis)
 */
void blink(int led, int delay_time) {

    // Blink the LED multiple times
    for (int i = 0; i < NUM_BLINKS; i++) {

        // Turn LED on and wait
        digitalWrite(led, HIGH);
        delay(delay_time);

        // Turn LED off and wait
        digitalWrite(led, LOW);
        delay(delay_time);
    }
}