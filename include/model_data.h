#ifndef MODEL_DATA_H
#define MODEL_DATA_H

// Change the type back to const unsigned char, but add the alignment attribute:
const unsigned char optimized_model_tflite[] __attribute__((aligned(4))) = {
    // ... your long hex data array values remain exactly here ...
};

#endif // MODEL_DATA_H