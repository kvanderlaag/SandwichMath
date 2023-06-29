# SandwichMath
Sandwich Engine Math Library

These are the Math functions for basic Matrix, Point, Quaternion, and Vector classes extracted from [SandwichEngine](https://github.com/kvanderlaag/Sandwich) for use elsewhere. The implementation is simplistic, with templated functions for common operations that should prove fairly flexible.

These classes should not be considered performant enough for use in larger projects; ideally they should be implemented using some flavour of platform SIMD, since matrix and vector operations especially lend themselves well to SIM parallelism.
