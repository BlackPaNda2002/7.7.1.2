#include <iostream>
#include "Array.h"
#include "Excep.h"

using namespace std;


int main()
{
   
    try
    {
        Int_Array array(10);

        for (int i=0; i <10; ++i)
            array[i] = i + 89;
        
        

             array.Resize(8);
       
            array.insertBefore(10,7);
       
       

         array.remove(3);


        array.insertAtEnd(30);
        array.insertAtBeginning(40);


        {
            Int_Array b{ array };
            b = array;
            b = b;
            array = array;
        }


        for (int i{ 0 }; i < array.getLength(); ++i)
            std::cout << array[i] << ' ';

        std::cout << '\n';
    }
    catch (const bad_length& c)
    {
        cout << c.what() << endl;
    }
    catch (const bad_range& r)
    {
        cout << r.what() << endl;
    }
       

    return 0;
}