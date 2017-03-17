/*
UML Class Diagram for Numer:

+--------------------------------------------------------+
|							 |
|			Number				 |
|							 |
+--------------------------------------------------------+
|							 |
| - n: int						 |
|							 |
+--------------------------------------------------------+
|							 |
| + Number(n : int) 					 |
| + isPrime() : bool					 |
| + isDivisibleBy(k : int) : bool			 |
|							 |
+--------------------------------------------------------+

*/

class Number
{
public:
	Number(int n);
	bool isPrime();
	bool isDivisibleBy(int k);

private:
	int n;

};
