#include <iostream>

/*
Input Validation Explanation - This function returns an integer. Although, a long could perform larger nth value calculations, it would take significantly longer for testing than
an integer, resulting in me choosing to return an integer value. With the integer value, I am able to set a maximum possible nth value of 19, where further nth values would cause 
integer overflow. However, by choosing to return an integer with these bounds, I can still demonstrate the recursion process to calculate the Catalan sequence.

If needed for larger calculations, the program could be modified to return long, but it might be better to calculate the Catalan using a different approach for larger calculations.
*/ 
int catalan(int n)
{
  // Check if valid input. Inputs over 19 cause integer overflow.
  if(n < 0 || n > 19)
  {
    std::cout << "Input " << n << " out of range. (Range: 0 <= n <= 19)\n";
    return -1;
  }
  else if(n <= 1) // Base case
  {
    return 1;
  }
  else
  {
    int temp = 0;
    for(int i = 0; i < n; i++)
    {
      temp += catalan(i) * catalan(n - i - 1);
    }
    return temp;
  }
}

int main()
{
  std::cout << "Enter Input for Catalan (Range: 0 <= n <= 19): " << "\n";
  int input = 0;
  std::cin >> input;
  std::cout << catalan(input) << "\n";

  return 0;
}
