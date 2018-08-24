#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "helper.h"

int* createVector(int size, int range) {
  int *vector;
  int index;

  /* Alocate memory for vector */
  vector = (int * ) malloc (sizeof(int) * (size+1));
  srand((unsigned)time(NULL));

  for(index = 0; index < size; index++) {
      vector[index] = create_random(range);
  }
  vector[index] = -1; /* Avoid sentinela has a value before search */
  return vector;
}

void destroyVector(int* vector){
  if(vector != NULL)
    free(vector);
}

void printVector(int *vector, int size) {
  printf("\n\n==================\n");
  for(int index = 0; index < size; index++)
    printf("%d: %d\n", index + 1, vector[index]);
  printf("==================\n\n");
}

/* Searches */

/* Sequential Search */
int sequentialSearch(int *vector, int size, int value) {
    int foundResults = 0;
    vector[size] = value; 
    
    for(int index = 0; index < size; index++) 
      if(vector[index] == value)
        foundResults++;

    return foundResults;
}

/* Binary Search */
int binarySearch(int arr[], int l, int r, int x) {
   if (r >= l) {
        int mid = l + (r - l)/2;
 
        if (arr[mid] == x)
            return mid;
 
        if (arr[mid] > x)
            return binarySearch(arr, l, mid-1, x);
 
        return binarySearch(arr, mid+1, r, x);
   }
 
   return -1;
}

/* Interpolation Search */
int interpolationSearch(int* vector, int n, int value) {
    int min = 0;
    int maxvalue = (n - 1);

    while (min <= maxvalue && value >= vector[min] && value <= vector[maxvalue]) {
      int position = min + (((double)(maxvalue - min) / (vector[maxvalue] - vector[min])) * (value - vector[min]));
      
      if (vector[position] == value)
          return position;

      if (vector[position] < value)
          min = position + 1;
      else
          maxvalue = position - 1;
    }

    return -1;
}


