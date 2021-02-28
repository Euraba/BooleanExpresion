# BooleanExpresion
A C++ class that evaluates a boolean expression
This class works pretty good, but there are some limitations.
1) You can only have ONLY uppercase or ONLY lowercase. The default is lowercase but you can change it in the constructor
  Example: a^b is valid, but A^b&C is not valid
2) If the string had whitespaces the class will fail, so erase any spaces before using it.
It's based on recursion so it's not the fastest.
