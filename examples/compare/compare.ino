#include <GammaTable.h>

static constexpr size_t TABLE_SIZE {256};
GammaTable<byte, TABLE_SIZE> gamma_a(1.5);
GammaTable<byte, TABLE_SIZE> gamma_b(2.8);

void setup()
{
    Serial.begin(115200);
    delay(2000);

    Serial.print(1.0);
    Serial.print(" ");
    Serial.print(1.5);
    Serial.print(" ");
    Serial.print(2.8);
    Serial.println();

    for(size_t i = 0; i < TABLE_SIZE; ++i)
    {
        Serial.print(i);
        Serial.print(" ");
        Serial.print(gamma_a[i]);
        Serial.print(" ");
        Serial.print(gamma_b[i]);
        Serial.println();
    }
}

void loop()
{
}
