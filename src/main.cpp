#include <Arduino.h>
#include <EloquentTinyML.h>
#include "model_data.h" // Your compiled INT8 model data header

// Global settings for the 1D-CNN
#define NUMBER_OF_INPUTS 180
#define NUMBER_OF_OUTPUTS 1
#define TENSOR_ARENA_SIZE (8 * 1024) // Allocate 8KB arena memory RAM

// Create the EloquentTinyML instance
Eloquent::TinyML::TfLite<NUMBER_OF_INPUTS, NUMBER_OF_OUTPUTS, TENSOR_ARENA_SIZE> ml;

void setup() {
    Serial.begin(115200);
    while (!Serial);
    Serial.println("\n--- IoMT Edge AI Engine Initialization ---");

    // Load the model array dynamically into the wrapper
    if (!ml.begin(optimized_model_tflite)) {
        Serial.println("Tensor allocation or model loading failed!");
        while (1);
    }
    
    Serial.println("1D-CNN Model Layers Loaded Successfully!");
}

void loop() {
    // 1. Create a buffer array using uint8_t to match the framework resolver expectations
    uint8_t input_features[NUMBER_OF_INPUTS];
    for (int i = 0; i < NUMBER_OF_INPUTS; i++) {
        float sample = sin(i * 0.05) + ((random(-100, 100) / 100.0) * 0.1);
        
        // Quantize incoming float sample directly into the unsigned byte array range
        input_features[i] = (uint8_t)((sample * 127.0f) + 128);
    }

    // 2. Profile edge inference runtime speed
    uint32_t start_time = micros();
    float confidence_score = ml.predict(input_features);
    uint32_t inference_time = micros() - start_time;

    // 3. Output results to the serial port
    Serial.print("Inference Speed: ");
    Serial.print(inference_time);
    Serial.print(" microseconds | Target Classification Confidence: ");
    Serial.println(confidence_score, 4);

    delay(1000); // Sample array cycle every second
}