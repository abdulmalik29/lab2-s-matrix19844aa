#include <iostream>
#include "Matrix.h"
#include <string.h>
using namespace std;

int main(int argc, char **argv) 
{
  Matrix mat1, mat2;

  if(argc != 5)
  {
    cout <<"ERROR: incorrect number of arguments\n";
  }

  else if (strlen(argv[2]) > 1)
  {
    cout <<"ERROR: invalid argument\n";
  }

  else
  {
    mat1.fill_from_file(argv[1]);
    if (argv[2][0] == '+' && strlen(argv[3]) == 1)
    {
      mat1.add(atoi(argv[3]));
      mat1.store_in_file(argv[4]);
    }
    else if (argv[2][0] == 'x' && strlen(argv[3]) == 1)
    {
      mat1.mult(atoi(argv[3]));
      mat1.store_in_file(argv[4]);
      
    }

    else if (argv[2][0] == 'x' && strlen(argv[3]) > 1)
    {
      mat2.fill_from_file(argv[3]);
      mat1.mult(&mat2);
      mat1.store_in_file(argv[4]);
    }
    
    else if (argv[2][0] == '+' && strlen(argv[3]) > 1)
    {
      mat2.fill_from_file(argv[3]);
      mat1.add(&mat2);
      mat1.store_in_file(argv[4]);
    }
  }

  return 0;
} 
