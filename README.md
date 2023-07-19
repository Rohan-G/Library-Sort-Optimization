# Run Instructions

* Open the LibSort2.cpp file - compile as is with g++ and run with ./a.out to run for purely randomized samples and get printed run times

* Uncomment lines 636 and 637 and repeat to run for reverse sorted samples.

* Uncomment lines 639 and 640 and repeat to run for partially (half) sorted samples.

## To test for the library sort and optimized library sort functions:
    * Comment out main and create a new main and initialize array, size and epsilon required.
    * Run normLibSort(arrayName, arraySize, epsilon) for normal libsort, and check_sorted(arrayName, arraySize) to check if array is sorted
    * Run preProcessingLibSort(arrayName, arraySize, epsilon) for optimized libSort, and the same as before for checking if sorted.

### View ans, ansPartialSort, ansReverse for the output from our runs
### View the graph folders for images of the graphs, and graph.py for the code used to generate the graphs

**Note** We had randomly generated as we ran, and didn't store the arrays which we ran with.
