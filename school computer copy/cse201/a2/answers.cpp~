#include <iostream>
#include <cassert>

using namespace std;

/*
  EXERCISE 1: Draw the UML class diagram for
              the BeanJar class.

+---------------------------------------------------------------+
|								|
|			BeanJar					|
|								|
+---------------------------------------------------------------+
|								|
| - maxNumberOfBeans : int					|
| - numberOfBeans : int						|
|								|
+---------------------------------------------------------------+
|								|
| + BeanJar(maxNumberOfBeans : int, initialNumberOfBeans: int)	|
| + addBeans(numberOfBeansToAdd : int) : bool			|
| + removeBeans(numberOfBeansToRemove : int) : bool		|
| + getNumberOfBeans() : int					|
|								|
+---------------------------------------------------------------+

*/
/*
Instances of the BeanJar class represent bean jars of varying capacity. The class provides functions to add beans, remove beans, and get the number of beans that are currently in the bean jar.  The functions to add and remove beans return a boolean value that indicates whether the operation succeeded or failed.  When one of these functions fails, the number of beans in the jar will not have been changed. In other words, if a bean jar has a capacity of 10 and there are 9 beans currently in the jar, then calling addBeans(2) will return false and the number of beans in the jar will remain at 9.
*/

class BeanJar
{
public:
   BeanJar(int maxNumberOfBeans, int initialNumberOfBeans);

   // addBeans returns true on success, false on failure.
   bool addBeans(int numberOfBeansToAdd);

   // removeBeans returns true on success, false on failure.
   bool removeBeans(int numberOfBeansToRemove);

   // getNumberOfBeans returns the number of beans
   // in the bean jar.
   int getNumberOfBeans();  

private:
   int maxNumberOfBeans;
   int numberOfBeans;
};

BeanJar::BeanJar(int maxNumberOfBeans, int initialNumberOfBeans)
{
   this->maxNumberOfBeans = maxNumberOfBeans;
   this->numberOfBeans = initialNumberOfBeans;
}

bool BeanJar::addBeans(int numberOfBeansToAdd)
{
   // PROBLEM 2: implement the addBeans function.
   
   if (numberOfBeans + numberOfBeansToAdd > maxNumberOfBeans)
   {
       return false;
   }
   else
   {
       numberOfBeans += numberOfBeansToAdd;
       return true;
   }

}

bool BeanJar::removeBeans(int numberOfBeansToRemove)
{
   if (numberOfBeansToRemove > numberOfBeans)
   {
       return false;
   }
   else
   {
       numberOfBeans -= numberOfBeansToRemove;
       return true;
   }
}

int BeanJar::getNumberOfBeans()
{
   return numberOfBeans;
}

int main(int argc, char * argv[])
{
   BeanJar beanJar(10, 5);
   assert(beanJar.getNumberOfBeans() == 5);

   assert(beanJar.addBeans(3));
   assert(beanJar.getNumberOfBeans() == 8);

   assert(!beanJar.addBeans(4));
   assert(beanJar.getNumberOfBeans() == 8);



   // PROBLEM 3: Add code to test the removeBeans function.
   // Make sure the test code executes all lines of code
   // in the removeBeans function.

   BeanJar beanJar(10, 5);
   assert(beanJar.getNumberOfBeans() == 5);

   assert(beanJar.removeBeans(3));
   assert(beanJar.getNumberOfBeans() == 2);

   assert(!beanJar.addBeans(5));
   assert(beanJar.getNumberOfBeans() == 7);



   cout << "All tests passed.\n";
}
