#include "attribute.h"

Attribute::Attribute()
{

}

void Attribute::setValueBy(int modifyValue)
{
    value += modifyValue;
    if (value > maxValue) {
        value = maxValue;
    }
    else if (value < minValue)
    {
        value = minValue;
    }
}

void Attribute::setValueByPercent(int percent)
{
    setValueBy(percent*value);
}

int Attribute::currentValue()
{
    return value;
}

HP::HP()
{
    value = 100;
    minValue = 0;
    maxValue = 100;
}

MP::MP()
{
    value = 100;
    minValue = 0;
    maxValue = 100;
}

Dodge::Dodge()
{
    value = 0;
    minValue = 0;
    maxValue = 100;
}

Resistance::Resistance()
{
    value = 0;
    minValue = 0;
    maxValue = 100;
}
