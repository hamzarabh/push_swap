# push_swap Project
*This project has been created as part of the 42 curriculum by hrabh*

## Description

push_swap is a sorting algorithm project that sorts a stack of integers using a limited set of operations with the minimum number of moves. The program receives integers as arguments and outputs operations to sort them in ascending order using two stacks (A and B).

## Available Operations

- **sa**, **sb**, **ss** - swap first 2 elements
- **pa**, **pb** - push top element from one stack to another
- **ra**, **rb**, **rr** - rotate stack up (first becomes last)
- **rra**, **rrb**, **rrr** - reverse rotate stack down (last becomes first)

## Algorithm

The implementation uses a chunk-based sorting algorithm:

### How it works

- **Indexing**: Assign each number an index based on its sorted position (0 = smallest, n-1 = largest)
- **Small stacks (2-5 elements)**: Optimized solutions
  - 2 elements: simple swap
  - 3 elements: hardcoded optimal cases
  - 4-5 elements: push smallest to B, sort 3 in A, push back
- **Large stacks (6+ elements)**:
  - **Phase 1 - Push to B**:
    - Divide numbers into chunks (15 for ≤100 numbers, 35 for larger sets)
    - Push numbers in chunk ranges to stack B
    - Keep smaller numbers at bottom of B with rotation
  - **Phase 2 - Push back to A**:
    - Find maximum index in B
    - Rotate B to bring max to top (shortest path)
    - Push to A
    - Repeat until B is empty

## Performance

- 100 numbers: ~550 operations (limit: 700)
- 500 numbers: ~5000 operations (limit: 5500)

## Instructions

### Compilation

# make          # Compile
# make clean    # Remove objects
# make fclean   # Remove objects and executable
# make re       # Recompile

## Testing

Test with random numbers
./push_swap $(shuf -i 1-100 -n 100) | wc -l
./push_swap $(shuf -i 1-500 -n 500) | wc -l
 ARG=$(shuf -i 1-500 -n 500); ./push_swap $ARG | ./checker_linux $ARG

## Error Handling
The program outputs "Error" to stderr in the following cases:

Duplicate numbers
Non-numeric arguments
Numbers outside the INT range (-2147483648 to 2147483647)
Any other invalid input
## Project Structure

push_swap/
├── Makefile
├── README.md
├── main.c
├── includes/
│   └── push_swap.h
└── sources/
    ├── ft_addtostack.c      # Stack creation
    ├── ft_atol.c            # String to long
    ├── ft_check_input.c     # Input validation
    ├── ft_creat_stack.c     # Stack initialization
    ├── ft_is_unique.c       # Duplicate detection (hash table)
    ├── ft_push_swap.c       # Main sorting logic
    ├── ft_push_to_a.c       # Retrieve from B to A
    ├── ft_push_to_b.c       # Distribute A to B (chunks)
    ├── ft_split.c           # Argument parsing
    └── opera_of_stack.c     # Stack operations

## Technical Choices

### Why Chunk Algorithm?

Initially, I implemented Radix Sort (bit-by-bit sorting), experimenting with both single-bit and two-bit processing. However, this approach resulted in higher operation counts (~700-800 moves for 100 numbers), which was close to or over the project's limits in some cases.

I switched to the Chunk Algorithm because it provided:
- Better performance (~550 operations for 100 numbers)
- More efficient use of both stacks (A and B)
- Simpler and more predictable logic
- Fewer unnecessary rotations

**Key learning**: Theoretical algorithm efficiency (like O(n log n) for Radix) doesn't always translate to the best practical performance under the specific constraints of limited operations and only two stacks.

## Resources

### Documentation
- 42 Push_swap Subject
- Sorting Algorithms - GeeksforGeeks

### Community Resources
- GitHub: Analyzed implementations from other 42 students for algorithmic insights
- Stack Overflow: Solutions for debugging and C programming issues
- YouTube: Tutorial videos on sorting algorithms and optimization

## AI Usage

AI (Claude) was used for:

### Algorithm Understanding
- Exploring different sorting algorithms and their trade-offs
- Understanding chunk-based strategies
- Learning about algorithm complexity

### Debugging
- Analyzing segmentation faults and memory errors
- Identifying edge cases
- Understanding valgrind output

**Important**: All core algorithm logic and implementation were developed independently. AI was used strictly as a learning tool and debugging assistant, not for generating code solutions.