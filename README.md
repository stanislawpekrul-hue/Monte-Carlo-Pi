# Estimating π with Monte Carlo

A simple C program that estimates π by random sampling.

## Idea

Sample points uniformly from the unit square [0, 1] × [0, 1]. A point lies
inside the quarter of the unit circle if x² + y² ≤ 1. The quarter circle has
area π/4 and the square has area 1, so for large n:

    (points inside circle) / n ≈ π / 4

which gives π ≈ 4 · (points inside circle) / n.

## Build and run

    gcc -O2 -Wall -o pi_mc pi_mc.c
    ./pi_mc

The program reads the number of samples `n` (a positive integer) from stdin
and prints the estimate of π. The output varies between runs, for example:

    $ echo 1000000 | ./pi_mc
    3.141912

## Accuracy

The estimator is a random variable with standard deviation
4·√(p(1−p)/n), where p = π/4, i.e. roughly 1.64/√n. The error shrinks as
1/√n, so each additional digit of accuracy requires about 100× more samples.

## Limitations

- Uses the standard library `rand()`, which is low quality on some platforms
  (e.g. MSVC, where RAND_MAX is only 32767), limiting achievable precision.
- The seed comes from `time(NULL)`, so two runs within the same second
  produce identical results.
- A better PRNG (xorshift, `drand48`)
- Confidence interval output
- Convergence plot of the estimate against n
