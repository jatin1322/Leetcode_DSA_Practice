METHOD  (Using **Moore’s Voting Algorithm**):
This algorithm works on the fact that if an element occurs more than N/2 times, it means that the remaining elements other than this would definitely be less than N/2. So let us check the proceeding of the algorithm.
​
​
Algorithm:
* Loop through each element and maintains a count of majority element, and a majority index, maj_index
* If the next element is same then increment the count if the next element is not same then decrement the count.
* if the count reaches 0 then changes the maj_index to the current element and set the count again to 1.
* Now again traverse through the array and find the count of majority element found.
* If the count is greater than half the size of the array, print the element
* Else print that there is no majority element