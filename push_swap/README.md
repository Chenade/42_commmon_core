
- [x] get input
- [x] check validation
  - [x] ft_isdigit
  - [x] int_max
  - [x] duplication
- [x] convert into order
- [x] stack operation
  - [x] push
  - [x] pop
  - [x] clear
- [x] push in stack a
- [x] progam cmd
  - [x] sa
  - [x] sb
  - [x] ss : sa + sb
  - [x] pa
  - [x] pb
  - [x] ra
  - [x] rb
  - [x] rr : ra + rb
  - [x] rra
  - [x] rrb
  - [x] rrr : rra + rrb
- [ ] sorting
  - [x] small sort (3)(4)(5)
  - [X] redix sort - Score 7
    - 100: 1084
    - 500: 6784
  - [X] LIS optmize - Score 10
    - find lis in stack A
    - push all other num not in lis to stack B
    - do a rb if num is larger than median
    - calculate all the move for selection sort
    - find the cheapest one
      - 100: Avg 538.7 (539, 568, 652, 633, 493, 550, 609, 628, 583, 627)
      - 500: Avg 4747  (4760, 4565, 4952, 4464, 4833, 5023, 4676, 4603, 4833, 4761)
    - Optimze option
      - [ ] combine move when send to stack B
      - [ ] combine move when calcultate
      - [X] combine move when printing
  - [ ] quick sort
    - 100: 
    - 500: 
  - [ ] others
    - pb * 2
    - Foreach stackA
    - calculate the least step move to top
    - get numB
        - if the numA is less than all the num in B: find the the grestest num in B
        - else: find the grestest num in B less than num
    - calculate the least step move to top
    - combine 
        - ra + rb = rr
        - rra + rrb = rrr
    - take the least move
    - do rb or rrb to make max to the top
    - Foreach stackB : pa