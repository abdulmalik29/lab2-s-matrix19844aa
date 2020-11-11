#include <iostream>
#include <fstream> 
#include "Matrix.h"
#include <sstream>
#include <iterator>

Matrix::Matrix()
{
}

int Matrix::rows()
{
  return (_matrix.size());
}


int Matrix::columns()
{
  return (_matrix[0].size());
}


int Matrix::fill_from_file(char *path)
{
  string myText;
  ifstream input(path);
  while (getline (input, myText)) 
  {
    istringstream iss(myText);
    _matrix.emplace_back(istream_iterator<int>(iss),istream_iterator<int>());
  }
  return 0;
}


int Matrix::store_in_file(char *path)
{
  ofstream outputFile(path);
  for(int i = 0; i<_matrix.size(); i++)
  {
    for(int j = 0; j< _matrix[i].size(); j++)
    {
      outputFile << _matrix[i][j]<< " ";
      if(j == ((_matrix[i].size())-1))
      {
      outputFile <<endl;
      }
    }
  }
  outputFile.close();
  return 0;
}


void Matrix::print()
{
  for(int i = 0; i<_matrix.size(); i++)
  {
    for(int j = 0; j< _matrix[i].size(); j++)
    {
      cout << _matrix[i][j]<< " ";
      if(j == ((_matrix[i].size())-1))
      {
      cout <<endl;
      }
    }
  }
}


int Matrix::index(int row, int column)
{
  return _matrix[row][column];
}

int Matrix::add(Matrix *m)
{
  Matrix mat = *m;
  for(int i = 0; i <_matrix.size() ; i++)
  {
    for(int j = 0; j < _matrix[0].size(); j++)
    {
        _matrix[i][j] += mat.index(i,j);
    }
  }
  return 0;
}

int Matrix::add(int val)
{
  for(int i = 0; i<_matrix.size(); i++)
  {
    for(int j = 0; j< _matrix[0].size(); j++)
    {
      _matrix[i][j] += val;
    }
  }
  return 0;
}

int Matrix::mult(Matrix *m)
{
  Matrix mat = *m;
  for(int i=0; i<_matrix.size(); i++)    
  {    
      for(int j=0; j< mat.columns(); j++)    
      {   
          for(int k=0; k<_matrix[0].size(); k++)    
          {    
              _matrix[i][j]+=_matrix[i][k]*mat.index(k,j);
          }
      }
  }
  return 0;   
}


int Matrix::mult(int val)
{
  for(int i = 0; i<_matrix.size(); i++)
  {
    for(int j = 0; j< _matrix[0].size(); j++)
    {
      _matrix[i][j] *= val;
    }
  }
  return 0;
}
