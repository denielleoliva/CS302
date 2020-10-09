What is the program?

This program tests two different sorts with three different lists of
varying size. The goal of this program is to mainly see the time difference
as well as the difference in effeciency of two different sorts.

The first sort I used in the program is the Insertion Sort. This sort goes
through the list in a linear pattern. In this sort, you compare one element
to the one before it and if it's smaller compare it to the already sorted 
elements if they exist. If a smaller value is found, simply move the sorted
elements up one index. This would repeat until the list is sorted.

The second sort was the Quick Sort. The quick sort divides a list and sorts
the two sub arrays. This sort has two parts. The first part is to divide the
list into two parts. After this, you sort the two parts of the list recursively
until the entire list is sorted.

Development

One issue that I came across during development was reading from the files of 
data. When I initially tried to read from the files, the program did not seem 
to open the files. This issue was actually unrelated to opening the file, but
with how I was initializing the sort objects.

There were other issues pertaining to the sorts like how the comparisons and 
swaps wouldn't increment at the appropriate times as well as the files would 
have unsorted outputs.

Usage

To use this program, you must compile the generateData class first. This will 
provide you with all the data sets required. (1000, 10000, 100000) After these
data files are created you just have to use the Makefile for the execuatble. 
The intended output is also included in a log png in the data folder.