#include <GammaTable.h>

GammaTable<byte, 256> gamma_tbl(2.8);

void setup()
{
    Serial.begin(115200);
    delay(2000);

    for(size_t i = 0; i < gamma_tbl.size(); ++i)
    {
        Serial.print(i);
        Serial.print(" : ");
        Serial.println(gamma_tbl[i]);
    }
}

void loop()
{
}
