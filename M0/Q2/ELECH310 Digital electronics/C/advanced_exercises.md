# Advanced C Exercises (101+)

101. Implement a custom `memcpy` and benchmark it against the standard library for multiple buffer sizes.
102. Implement a custom `memmove` that correctly handles overlapping regions.
103. Write a function that reverses an array in-place using only pointer arithmetic (no indexing syntax).
104. Implement a dynamic vector (`push_back`, `pop_back`, `reserve`) using `malloc/realloc/free`.
105. Add bounds-checked accessors to your vector and return error codes instead of exiting.
106. Implement a fixed-size memory pool allocator for objects of equal size.
107. Build a linked list library (insert/delete/search) with full memory cleanup.
108. Extend your linked list with an iterator-like API using function pointers.
109. Implement a stack and queue on top of a singly linked list and compare performance.
110. Implement a circular buffer with head/tail indices and overwrite mode.

111. Write a function that parses a CSV line into dynamically allocated fields.
112. Build a line-based file parser that resizes buffers as needed for arbitrarily long lines.
113. Design a binary file format for sensor samples and implement serializer/deserializer.
114. Implement endian conversion utilities and verify correctness on test patterns.
115. Pack bit-fields from multiple logical signals into a byte stream and unpack them.
116. Implement parity, population count, and bit-reversal functions without compiler intrinsics.
117. Write a routine to extract and set arbitrary bit ranges in a 32-bit register value.
118. Emulate memory-mapped I/O registers with `volatile` globals and test read-modify-write macros.
119. Implement safe register write macros that preserve unrelated bits using masks.
120. Build a small command interpreter for register operations (`read`, `write`, `setbit`, `clrbit`).

121. Implement matrix multiplication with cache-blocking and compare against naive triple-loop.
122. Implement transpose in-place for square matrices and out-of-place for rectangular matrices.
123. Optimize histogram computation using loop unrolling and compare timing.
124. Implement quicksort manually and compare with `qsort` on multiple distributions.
125. Implement binary search on sorted dynamic arrays with robust edge-case handling.
126. Implement stable merge sort on arrays of structs.
127. Detect integer overflow in arithmetic helper functions and return status codes.
128. Create a generic swap macro and discuss type-safety risks.
129. Implement a macro-based dynamic array for arbitrary element types.
130. Refactor the macro solution into a `void*` + element-size generic container.

131. Create a multi-file project with separate modules for I/O, algorithms, and data structures.
132. Write headers with include guards and clean public/private API boundaries.
133. Add a Makefile with debug/release targets and dependency tracking.
134. Build a small static library (`.a`) and link it into an application.
135. Introduce unit-style tests in plain C for each module function.
136. Add fuzz-like randomized tests for parsing and memory APIs.
137. Implement centralized error handling with enumerated error codes and messages.
138. Add logging macros with compile-time level control (`DEBUG`, `INFO`, `ERROR`).
139. Build with `-Wall -Wextra -Wpedantic` and eliminate all warnings.
140. Add sanitizers (`address`, `undefined`) and fix all reported issues.

141. Implement an event loop with callback registration and dispatch.
142. Simulate interrupt sources by setting event flags from timer-driven tasks.
143. Create a priority-based scheduler for cooperative tasks.
144. Implement a software timer wheel for periodic callbacks.
145. Build a finite-state machine framework and apply it to a protocol parser.
146. Implement lock-free single-producer/single-consumer ring buffer semantics (single-thread simulation allowed).
147. Build a command-line profiler that reports per-function timing percentages.
148. Implement reference counting for heap objects and detect leaks at shutdown.
149. Add a custom allocator debug mode that tracks allocation site and size.
150. Design and implement a miniature embedded-style application combining ISR-like event flags, timers, ring buffer logging, and modular C architecture.
