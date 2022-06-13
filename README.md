# A note on O-Notation

When functions/algorithms are implemented abstractly through mathematical notation, the following notations are used as tight estimates: $O, \Omega, \Theta$. These estimates are based on their mathematical definition or the pseudocode's complexity.

When these same functions are implemented in actual code, the same notation shall be abused to give more specific estimates. For example, instead of $O(n)$, it might instead say $O(3n)$. This is not in violation of the notation's definition, yet it is abusing it slightly. This is done to give better estimates of how efficiently these functions are currently implemented.

Real-World tests and benchmarks specifically, however, give a much better and much more useful estimate on the function's expected running time and should always be preferred over the big O or similar notations.
