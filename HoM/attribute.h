#ifndef ATTRIBUTE_H
#define ATTRIBUTE_H

class Attribute
{
public:
    Attribute();
    virtual void setValueBy(int modifyValue);
    virtual void setValueByPercent(int percent);
    int currentValue();

protected:
    int value;
    int minValue;
    int maxValue;
};

class HP : public Attribute
{
public:
    HP();
};

class MP : public Attribute
{
public:
    MP();
};

class Dodge : public Attribute
{
public:
    Dodge();
};

class Resistance : public Attribute
{
public:
    Resistance();
};

#endif // ATTRIBUTE_H
