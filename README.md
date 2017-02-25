<h1>C++ Program 6: Poly - Abstract Data Type (ADT) </h1>
<h2>Description</h2>
<p>This project is to create the abstract data type (ADT) for a polynomial called Poly.</p>

<p>Implement the internal representation of a polynomial (nonnegative exponents) as an array of terms. One array is sufficient to store one polynomial. One term is stored in one array element; each term contains an exponent and a coefficient. The array element subscript is the exponent and the content of the element is the coefficient value. A constructor receives at most two values, the coefficient of the term and the largest exponent currently expected. (The coefficient may be changed later using functions.) Dynamically allocate initial memory for your array using only as many elements as needed. (After the Poly object instantiation, the size of the array need not be tied to the largest exponent. i.e., you may want to make the array larger when needed, but typically an array is not made smaller as it is inefficient.)
</p>

<b>Develop a full class:</b><br>
<strong>1. All proper constructor and destructor functions, </strong> e.g.,<br>
Poly A(5,7); 	// Memory is reserved for polynomial A, with a largest power of 7 and the coefficient is set to 5: +5x^7. <br>
Poly B(2); 	  // B has one element, initialized to +2x^0. <br>
Poly X;       // Initialized to 0x^0 (zero polynomial). <br>
Poly C(A);    // C is an exact copy (deep copy) of A. <br>

<strong>2. Overload common operators:</strong><br>
(a). The addition, subtraction, and multiplication operators (+, -, *) to add, subtract, multiply two polynomials <br>
(b). The assignment operator (=) to assign one polynomial to another <br>
(c). The addition, subtraction, multiplication assignment operators (+=, -=, *=) <br>
(d). The equality and inequality operators (==, !=) <br>

<strong>3. Accessors:</strong><br>
(a). Overload << to output an entire polynomial, print “ +5x^3 -2x^2 +4” to represent the Poly
5 x cubed minus 2 x squared plus 4. Use the following exact formatting. Must-do rules for displaying polynomials: <br>
•	Use lowercase x <br>
•	A nonzero coefficient and its sign are always displayed (display exactly one blank before every sign) <br>
•	Do not display a new line in operator<< at the end of the polynomial <br>
•	Do not display extra blanks at the end or anywhere else in the polynomial <br>
•	A power of 1 is not displayed and x is not shown at all for a power of 0, e.g., +1x^4 +2x -10 <br>
•	Don't print a term if the coefficient is zero, except if all the coefficients are zero, then print " 0" <br>
(b). Get one term's coefficient, called getCoeff, e.g., <br>
int coeff = P.getCoeff(2); <br>
cout << "coeff of power 2 of P is: " << coeff << endl; <br>

<strong>4. Mutators:</strong><br>
(a). Overload >> to input all coeffs (sets all terms of one Poly, in a loop; it is expected that a user enters one coefficient and an exponent repeatedly, Enters -1 for both when done; no data type-checking). e.g.,<br> 
to set A, Poly A(2,7); so that A is +5x^7 -4x^3 +10x –2
the user enters the pairs in any order: 5 7 10 1 -4 3 -2 0 -1 -1 on one line or multiple lines. <br>

(b). Set one coefficient, called setCoeff, e.g., 
P.setCoeff(50,0); // set x^0 coeff to 50
