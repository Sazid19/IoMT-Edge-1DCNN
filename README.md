# IoMT Edge AI 1D-CNN Classifier

An optimized, edge-deployed 1D Convolutional Neural Network (1D-CNN) running on an ESP32 microcontroller for Internet of Medical Things (IoMT) real-time classification tasks.

## 🚀 Overview
This repository showcases an end-to-end TinyML pipeline:
1. **Training & Quantization:** A 1D-CNN model trained in Python and quantized into an INT8 TensorFlow Lite (TFLite) format to optimize its memory footprint.
2. **Edge Deployment:** Deployed onto an ESP32 microcontroller using the `EloquentTinyML` library framework to run microsecond-level local inferences without cloud dependency.

## 🛠️ Project Structure
* `src/main.cpp`: Main firmware execution loop handling signal simulation and running edge inferences via the runtime engine.
* `include/model_data.h`: Aligned memory byte array (`uint8_t`) housing the quantized INT8 model weights.
* `platformio.ini`: PlatformIO configuration managing build flags and dependencies for the `esp32dev` environment.

## 📊 Performance Statistics
* **Inference Speed:** ~310 to 340 microseconds per sample execution on the ESP32 silicon.
* **Precision:** INT8 post-training quantization.
