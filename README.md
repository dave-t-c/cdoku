# Cdoku
A sudoku solver built in C

This program will take in a sudoku board as a csv file, and will 
output the solved puzzle.

### Example Input
```
.,.,.,.,.,.,.,.,.
.,.,.,.,7,6,.,2,.
.,.,4,8,.,.,1,.,.
.,.,5,9,4,.,8,.,.
.,.,.,7,.,.,.,5,.
.,9,6,.,.,.,.,7,2
8,.,.,5,.,4,.,.,7
.,.,.,.,3,.,2,.,.
1,4,.,.,.,.,.,.,.
```

### Example Output
```
|6|2|8|3|5|1|7|9|4|
|3|1|9|4|7|6|5|2|8|
|5|7|4|8|2|9|1|6|3|
|7|3|5|9|4|2|8|1|6|
|2|8|1|7|6|3|4|5|9|
|4|9|6|1|8|5|3|7|2|
|8|6|2|5|1|4|9|3|7|
|9|5|7|6|3|8|2|4|1|
|1|4|3|2|9|7|6|8|5|
```

## Running the program
The repo includes a copy of a Clion project. After importing 
the project, edit the run configurations to pass 
in the file path as a run parameter.

Alternatively you can build and run the program from the 
route project directory:
```shell
mkdir build
cd build
cmake ..
make
./cdoku path/to/sudoku/file
```