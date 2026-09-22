*This project has been created as part of the 42 curriculum by &lt;likhye-y&gt;, &lt;amlee&gt;.*

## Description
New Core's first collaborative project! This project teaches us the Math of Time Complexity, creating variations of algorithms based off the time complexity formulas, and an adaptive algorithm that will assign the list of numbers to specific algorithms based off the disorder count function, and to sort the list of numbers from whatever order they may be in into ascending order, with the use of only two stacks (stack_a & stack_b).

## Instructions
To execute the push_swap program...<br>
In the terminal of the root directory, run...
```
make
```
or
```
make push_swap
```
To compile the push_swap and libft program's files. <br>
<br>To re-compile the program, run...
```
make re
```
<br>To leave only the static library `push_swap` and removes all libft object files, run...
```
make clean
```
<br>And to remove both static libraries `libft.a` and `push_swap` and / or object files as well, run...
```
make fclean
```
<br>Then, to execute `push_swap` with custom numbers and algos, run...
```
./push_swap < Algo(--simple, --medium, --complex, --adaptive) OR None > [Numbers go here with spaces in-between]

i.e: ./push_swap --adaptive 82 199 3 2 1 4 5
```
If the input is correct, it'll print out the list of operations in the terminal, for example:
```
./push_swap --adaptive 82 199 3 2 1 4 5 | cat -e
pb$
pb$
ra$
ra$
ra$
ra$
...
```
If there are any duplicates or non-digit inputs, it'll not run the algorithms and instead return `Error`. For example:
```
./push_swap 2 1 3 2 | cat -e
Error$

./push_swap 2 1 3 two --simple | cat -e
Error$
```

## Resources
* (likhye-y) - I've had a conversation with Chatgpt after overhauling my medium algorithm, went from block-based partitioning method (block merge sort), to range based sort, since I came up with the range algo myself while rationalising my thoughts with AI, the only resources I used were for the scrapped algo, so there are no websites I used at all for the newly implemented algo.
    * **A.I Usage**
        * (likhye-y) - I've only used A.I mainly help with debugging, catching bugs I've missed at times, rationalising thoughts, explaining concepts and `modify a bit of logic from Gemini for my bubble sort, instead of fulfilling a certain condition to rotate the list, rotate always.` **AI DID NOT GIVE ANY ANSWERS, I'VE SET THE PERSONALISATION INSTRUCTIONS TO ONLY GIVE HINTS AND GUIDANCE AND QUESTION ME LIKE SOCRATES. (Except Gemini for a specific part. Check my disclosure above this bolded part if needed.)**

## Algorithms Explanations
* Simple Algorithm (Time Complexity: `O(n²)`)
    * What is `O(n²)` and why is this associated with the `simple` algorithm? <br><br>
    The formula `n²`, is basically our first and `slowest` time complexity calculation, take a `100 numbers` for example, `n` will `hold` the 100 numbers (`n = 100`), `100²` or `100 x 100` is `10,000`! Therefore, on the `worst case scenario` where the whole list is the total opposite of ascending order (`fully descending`), it'll take `roughly 10,000 calls` to `solve` the `order` of the whole list of numbers. <br>
    `So basically, 100 numbers, first number has 100 comparisons, second element has 99 comparisons...last element has only 1 comparison.`
    However, it still remains the `quickest` to solve `5 numbers or less`, due to the fact that we `don't need` to utilise `pushing` to `stack b` and `pushing back`.

* Medium Algorithm (Time Complexity: `O(n√n)`)
    * What is `O(n√n)` and why is this associated with the `medium` algorithm? <br><br>
    The formula `O(n√n)`, is basically a `faster` way of solving the order of a list of numbers, take a `100 numbers` again, `n = 100`, so `100√100` is equivalent to 100 x 10, which is 1000, that means that one element will have approximately `√n` (in this case, `10`) comparisons. And since we can only call each element 10 times instead of approximately 100 times, we have to improvise, meaning, giving each `number` an `index` to `sort` based on `index` than `actual value`, and `partitioning` them to their `ranges`, if `current range` being sorted is `found`, `push` to `stack b`, `sort` in `stack b first`, then `push back`. Since `stack b` has its `own range` each time, it can do `√n` `repeatedly` for `each element`.

* Complex Algorithm (Time Complexity: `O(n log n)`)
    * What is `O(n log n)` and why is this associated with the `complex` algorithm? <br><br>
    The formula `O(n log n)`, is basically the `fastest` way of solving the order of a list of numbers, take a `100 numbers` again, `n = 100`, so `log₂​(100) ≈ (approximate) 6.64 (Math Ceiling: 7)`, so give or take 7 comparisons per element. Basically halving. Think `100 -> 50 -> 25 -> 12 -> 6 -> 3 -> 1`. That's what our `radix` algo is doing in terms of `halving`. We first check the `Least Significant Digit` (`LSD`), which is the `most right side` of the `binary number`, yes, we also give `each number an index to sort` by, since we only have `two stacks` to work with, `binary (base 2)` is the `best` option, then we `check` if the `digit` is `0 or 1`, if it's `0`, `push to stack b`, if `1`, `rotate stack a` and `check` the `next` one, after it finishes `checking that LSD digit` for the `whole list`, it'll `push the 0's back to stack a`, and `shift the bits` to `check the next LSD` and `repeat`.

## Algorithm Justifications
* **Bubble Sort (Simple)** - We are using this mainly because we are `familiar` with it, as we have done it before in `C01` and `C06` back in the `Piscine`, though the `adaptation` to `fit push_swap standards` were pretty `tricky`, in terms of treating it as a `stack` right? We can only `modify` numbers / nodes at the `top two` or the `very bottom number(s)` `instead` of `iterating through the whole list`. <br><br>
* **Custom Range Sort (Medium)** - We are using this because it's `relatively simple` to `partition the numbers` based on their `ranges` and having a `sort` to `sort them in descending order` then `push back` to the `correct order` seems `straightforward`. If `one block / partition` will `hold approx 10 blocks`, a `100 numbers` also mean `10 blocks / partitions`. <br><br>
* **Radix Sort (Complex)** - It's one of the `most straightforward algorithms` to `implement` in terms of `n log n`, and we can just use `bits and shift them` in terms of only having `two stacks / buckets` to work with.