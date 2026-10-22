# CS 210 Project Three - Corner Grocer

## Project Summary
For this project I made a C++ program for the Corner Grocer. The program reads a text file with grocery items in it and keeps track of how many times each item shows up. The user can search for one item, print out all of the item counts, look at the counts as a histogram, or exit the program. It also makes a `frequency.dat` file so the item counts are saved.

## What I Did Well
I think the way I organized the program came out pretty good. I did not want everything sitting inside `main()`, so I made a `GroceryTracker` class and split the project into separate files. I also used a `map` for the item names and counts. That made the counting part a lot easier because I did not have to manually keep track of every item. I also added a little input checking for the menu so the program could handle bad input better.

## Areas I Could Improve
One thing I noticed is that the search is picky about capitalization. If the file says `Apples` and somebody types `apples`, it will not find the same result. If I worked on it more, I would probably change that first. I would also go back through the code and see where I could make it a little shorter or avoid copying strings when I do not need to.

## Challenges and How I Overcame Them
The part I had the most trouble with was actually getting the input file where Visual Studio could read it. The code was working, but the program could not find the file at first. After I got the file in the right project folder, that problem went away. I also had to make sure the item counts were being stored correctly. Breaking the program into smaller functions helped because I could look at one part at a time instead of trying to figure out the whole program at once. I used zyBooks, the examples from class, and Visual Studio's error messages when I got stuck.

## Transferable Skills
I got more practice with classes, maps, file input and output, loops, and functions from this project. I also got more used to working with multiple files in one C++ project. I think that will help later because bigger programs are probably not going to be written in one giant file.

## Maintainability, Readability, and Adaptability
I tried to keep the code easy to follow by using separate files for the class and `main()`. I also used function names that say what the functions actually do, like `LoadItems()`, `PrintHistogram()`, and `GetItemFrequency()`. I added comments in places where I thought they helped. Since the program is already split into different functions, adding another menu option or changing how the output looks should not require changing everything else.
