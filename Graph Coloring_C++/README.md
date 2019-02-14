Algorithm Steps:

Step 0: G <- given input graph

usedColorSet <- 0

Step 1: newNode <- get the next node from G

Step 2: usedColor <- find a used color from usedColorSet that can be used to color the newNode.

findUsedColor() <- it returns the first color that found which can be used and if none of these used color can be used to color the newNode then return 0.

Step 3: if usedColor > 0

Then color newNode with usedColor

Else, newColor <- get a new Color

Color newNode with newColor

Put newColor into usedColorSet

Step 4: Repeat step 1 -> 3 until no more newNode 


                                              ****** Thank You ******

