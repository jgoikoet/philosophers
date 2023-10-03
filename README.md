# philosophers
42 cursus philosophers

The mandatory part of the proyect works fine whih no data races, leaks..

The bonus part shows 2 data races when compiling whit -fsanitize=thread. There are two semaphores to avoid that so maybe it´s a sanitize problem???
