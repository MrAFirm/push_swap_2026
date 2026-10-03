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
```bash
./push_swap < Algo(--simple, --medium, --complex, --adaptive) OR None > [Numbers go here with spaces in-between]

i.e: ./push_swap --adaptive 82 199 3 2 1 4 5
```
If the input is correct, it'll print out the list of operations in the terminal, for example:
```bash
./push_swap --adaptive 82 199 3 2 1 4 5 | cat -e
pb$
pb$
ra$
ra$
ra$
ra$
...
```
You can use `algorithm flags` along with your `executable (./push_swap)` to `run the program` as well to `force` the `list of numbers` to `use` the `algorithm you choose`. `--simple for O(n²)`, `--medium for O(n√n)`, `--complex for O(n log n)` and `--adaptive for our adaptive algorithm`.
```
--simple
--medium
--complex
--adaptive
```
We can use `shuf` with the flag `-i` to specify which `range of numbers` of choose from, and `-n` to specify how many `numbers needed`. <br>
And as for the `--bench` flag, you can use it with fd 2 (which is stderr) to display it in a text file. It'll `display disorder percentage`, `strategy used`, `total ops`, and a `count` for `each ops`. <br>
Using `>`, we can `save the output` into a `file we want`, if the `file doesn't exist`, the `program` will `create the files we specified`. <br>
We can also use the `./checker_linux`, `./checker_Mac` or our own `./checker` (`bonus`) to check if `after` the `ops` are `displayed`, if the `list of numbers` are actually `sorted` in `fully ascending order`. <br><br>
Example usage:
```bash
shuf -i 0-9999 -n 500 > args.txt; ./push_swap --complex --bench $(cat args.txt) > text.txt 2> bench.txt | ./checker_linux $(cat args.txt)
```
`Not using an algorithm flag` means it'll `automatically` go into our `adaptive algorithm` and use a `disorder count` to `determine` which `algorithm` is `better suited` to `solve` the `list of numbers`. `Not using the --bench flag` or using it `without saving the output with fd 2 into a file` will `result` in the `benchmarks` `not displayed / called`. <br><br>
If there are any `duplicates` or `non-digit inputs`, it'll `not run` the `algorithms` and instead return `Error`. For example:
```bash
./push_swap 2 1 3 2 | cat -e
Error$

./push_swap 2 1 3 two --simple | cat -e
Error$
```
To run our **`bonus part`**, `custom checker program`, do:
```
make bonus
```
Then you're able to pipe the checker at the end after you ran ./push_swap like so:
```bash
shuf -i 0-9999 -n 500 > args.txt; ./push_swap --complex --bench $(cat args.txt) 2> bench.txt | ./checker $(cat args.txt)
OK <-- Given by checker if operations are correct and list of numbers is sorted.
```
Or something simple like:
```bash
./push_swap 2 3 4 1 | ./checker 2 3 4 1
OK <-- Given by checker if operations are correct and list of numbers is sorted.
```
Or you can just run ./checker directly and manually give it sorting operations / instructions, like:
```
./checker 2 3 4 1 [Tap the Enter key]
rra [Tap the Enter key]
[Ctrl + D to end User Input]
OK <-- Given by checker if operations are correct and list of numbers is sorted.
```
In order for our program to wait for user input, we used our own get_next_line and helper functions to read for user input. (One instruction only)
If you give the wrong operation or your ./push_swap algo used gave the wrong operations and the list of numbers aren't sorted, our ./checker program will output a KO. <br>
For example:
```
./checker 2 3 4 1
pa (Wrong operation, stack b has no node(s).)
KO

./checker 2 3 4 1
sa
ra
rra
pb
pa
KO <-- List not sorted.

./push_swap 2 3 4 1 | ./checker 2 3 4 1
KO <-- If your ./push_swap algorithm outputs the wrong operation(s), hence the list is not sorted.
```

## Resources
* (likhye-y) - I've had a conversation with Chatgpt after overhauling my medium algorithm, went from block-based partitioning method (block merge sort), to range based sort, since I came up with the range algo myself while rationalising my thoughts with AI, the only resources I used were for the scrapped algo, so there are no websites I used at all for the newly implemented algo.

* (amlee) - https://www.geeksforgeeks.org/dsa/radix-sort/
    * **A.I Usage**
        * (likhye-y) - I've only used A.I mainly help with debugging, catching bugs I've missed at times, rationalising thoughts, explaining concepts and `modify a bit of logic from Gemini for my bubble sort, instead of fulfilling a certain condition to rotate the list, rotate always.` **AI DID NOT GIVE ANY ANSWERS, I'VE SET THE PERSONALISATION INSTRUCTIONS TO ONLY GIVE HINTS AND GUIDANCE AND QUESTION ME LIKE SOCRATES. (Except Gemini for a specific part. Check my disclosure above this bolded part if needed.)**

        * (amlee) - I used AI for coming up with metaphors in order to understand the different algorithms better. Additionally, I used it for guidance on possible code optimisation. Same as Shaun, **AI did not give me answers.**

## Algorithms Explanations
* Simple Algorithm (Time Complexity: `O(n²)`)
    * What is `O(n²)` and why is this associated with the `simple` algorithm? <br><br>
    The formula `n²`, is basically our first and `slowest` time complexity calculation, take a `100 numbers` for example, `n` will `hold` the 100 numbers (`n = 100`), `100²` or `100 x 100` is `10,000`! Therefore, on the `worst case scenario` where the whole list is the total opposite of ascending order (`All Pairs Inverted`, `Fully Descending Order`), it'll take `roughly 10,000 calls` to `solve` the `order` of the whole list of numbers. <br>
    So basically, `100 numbers`, `first element` has `100 comparisons`, `second element` has `99 comparisons...` `last element` has `only 1 comparison`. <br><br>
    **Sorting 3 and 5 numbers' challenge:**
        * For `Sort 3` and `Sort 5`, no matter what we try to do in terms of the `Big-O Time Complexity`, it'll `never` be `O(n²)`, only `O(1)`, because the `input` is `fixed`, since we need `ops <= 5` to `pass` for `3 numbers` and `ops <= 15` for `5 numbers`, we could've only `integrated elements` of `O(n²)`, but we `couldn't guarantee` its `"efficientness"`, so we just utilised `0(1)`, and the `manual` way to `solve` it for `maximum eifficiency`.

* Medium Algorithm (Time Complexity: `O(n√n)`)
    * What is `O(n√n)` and why is this associated with the `medium` algorithm? <br><br>
    The formula `O(n√n)`, is basically a `faster` way of solving the order of a list of numbers, take a `100 numbers` again, `n = 100`, so `100 √100` is equivalent to 100 x 10, which is 1000, that means that one element will have approximately `√n` (in this case, `10`) comparisons. And since we can only call each element 10 times instead of approximately 100 times, we have to improvise, meaning, giving each `number` an `index` to `sort` based on `index` than `actual value`, and `partitioning` them to their `ranges`, if `current range` being sorted is `found`, `push` to `stack b`, `sort` in `stack b first`, then `push back` after `all ranges` are `sorted in descending order`. As `pushing` all back to `stack A` will become `ascending order` (`stack B top` to `stack A top`). Since `stack b` has its `own range` each time, it can do `√n` `repeatedly` for `each element`. For `√n` to be the `amount of numbers per block / partition / range`, it can also be the same for ranges, `√n` for the `amount of blocks / partitions / ranges` too.

* Complex Algorithm (Time Complexity: `O(n log n)`)
    * What is `O(n log n)` and why is this associated with the `complex` algorithm? <br><br>
    The formula `O(n log n)`, is basically the `fastest` way of solving the order of a list of numbers, take a `100 numbers` again, `n = 100`, so `log₂​(100) ≈ (approximate) 6.64 (Math Ceiling: 7 or Math Floor: 6)`, so give or take 7 comparisons per element. Basically halving. Think `100 -> 50 -> 25 -> 12 -> 6 -> 3 -> 1`. That's what our `radix` algorithm is doing in terms of `halving`. We first check the `Least Significant Digit` (`LSD`), which is the `most right side` of the `binary number`, yes, we also give `each number an index to sort` by, since we only have `two stacks` to work with, `binary (base 2)` is the `best` option, then we `check` if the `digit` is `0 or 1`, if it's `0`, `push to stack b`, if `1`, `rotate stack a` and `check` the `next` one, after it finishes `checking that LSD digit` for the `whole list`, it'll `push the 0's back to stack a`, and `shift the bits` to `check the next LSD` and `repeat`.

## Algorithm Justifications
* **Bubble Sort (Simple)** - We are using this mainly because we are `"familiar"` with it, as we have done it before in `C01` and `C06` back in the `Piscine`, though the `adaptation` to `fit push_swap standards` were pretty `tricky`, in terms of treating it as a `stack` right? We can only `modify` numbers / nodes at the `top two` or the `very bottom number(s)` `instead` of `iterating through the whole list`. <br><br>
* **Custom Range Sort (Medium)** - We are using this because it's `relatively simple` to `partition the numbers` based on their `ranges` and having a `sort` to `sort them in descending order` then `push back` to the `correct order` seems `straightforward`. If `one block / partition` will `hold approx 10 numbers`, a `100 numbers` also mean `10 blocks / partitions` And applying a `Selection Sort` to find the `Max index` of the `block / range` and soon `all ranges`, then after `all` are `sorted` in `descending order` in `stack B`, we can just `drain all` back to `stack A`. Straightforward! <br><br>
* **Radix Sort (Complex)** - It's one of the `most straightforward algorithms` to `implement` in terms of `n log n`, and we can just use `bits and shift them left or right` depending on our implementation, also in terms of only having `two stacks / buckets` to work with. In my radixsort, I first `indexed the numbers` using a `counter` of `total numbers smaller than itself`. After that we proceed to use it's `index' binary value` to `sort` the `numbers`. <br>
