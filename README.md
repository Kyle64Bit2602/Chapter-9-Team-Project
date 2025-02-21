# Test Scores Analyzer
Kyle, Xander

## Test Scores Analyzer Description
The Test Scores Analyzer is a program designed to process and analyze an unknown number of student test scores. It dynamically allocates memory for storing the scores, validates the inputs to ensure no negative scores are entered, sorts the scores in ascending order, and calculates the average score while dropping the lowest score. The program then displays the sorted scores and the calculated average on the screen and saves the results to a text file named `results.txt` for future reference.

### Test Scores Analyzer Flowchart
```mermaid
graph TD;
  A[Start] --> B[Input Handling and Validation];
  B --> C[Dynamic Memory Allocation];
  C --> D[Sorting Algorithm];
  D --> E[Average Calculation];
  E --> F[Display Results];
  F --> G[Save Results to File];
  G --> H[End];

#### Function Diagrams

inputHandling		Team member 1
scores:int*	Takes input from the user for test scores	
size:int	Dynamically allocates memory for scores	Returns pointer to allocated memory
validation:bool	Ensures no negative scores are entered	Returns true if valid, false otherwise

sortScores		Team member 2
scores:int*	Takes pointer to array of scores	
size:int	Sorts scores in ascending order	Modifies array in place
returns:void	No return value	Sorts the array

calculateAverage		Team member 1
scores:int*	Takes pointer to sorted array of scores	
size:int	Calculates average, dropping the lowest score	Returns calculated average
returns:float	Returns the average score	Outputs the average

displayResults		Team member 2
scores:int*	Takes pointer to sorted array of scores	
average:float	Displays sorted scores and average on screen	Outputs to console
returns:void	No return value	Displays results

saveToFile		Team member 2
scores:int*	Takes pointer to sorted array of scores	
average:float	Saves sorted scores and average to results.txt	Outputs to file
returns:void	No return value	Saves results to file
