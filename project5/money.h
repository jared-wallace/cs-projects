#ifndef MONEY_H
#define MONEY_H

class Money
{
  private:

    int value;
    string displayValue;
    int index;
  public:
    setValue(int amount)
    {
        value = amount;
    }
    setDisplayValue(string amount)
    {
        displayValue = amount;
    }
