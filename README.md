# GammaTable
Gamma Table for Arduino

## Usage

``` C++
#include <Gamma.h>
GammaTable<byte, 256> gamma_tbl(2.8);

void setup()
{
    for(size_t i = 0; i < gamma_tbl.size(); ++i)
    {
        Serial.print(i);
        Serial.print(" : ");
        Serial.println(gamma_tbl[i]);
    }
}
```

## License

MIT
