# SecretSharingProtocols
A C++ project for PSS and DSS

Important Class Definition:
Polynomial
Tss
BigPrime

Example:
Class: Polynomial
  vector<mp::int1024_t> coefficients = {5, 7, 4}
  Polynomial PolyObject;  //Empty poly
  Polynomial PolyObject(coefficients);    // polynomial 5 + 7x + 4x^2
  
  Addition
------------
vector<mp::int1024_t> coefficients_poly1 = {5, 7, 4}
vector<mp::int1024_t> coefficients_poly2 = {2, 1, 3}
Polynomial Poly1(coefficients_poly1);  //  5 + 7x + 4x^2
Polynomial Poly2(coefficients_poly2);    // 2 + 1x + 3x^2

Polynomial Poly3;
Poly3 = Poly1 + Poly2;  // 7 + 8x + 3x^2
  
  





