#ifndef SHAPE_H
#define SHAPE_H

class Shape
{
  private:
    bool wide, flipped;
    int width, length;
    char symbol;
  public:
    void setWidth( int);
    void setLength( int);
    void setWide( bool);
    void setFlipped( bool);
    void setSymbol( char);
    void screen() const;
    bool inputValidate( int, int);
    int getLength() const;
    int getWidth() const;
    char getSymbol() const;
    bool getWide() const;
    bool getFlipped() const;


};

#endif
