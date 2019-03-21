# tsvtable
Takes a .tsv file and displays it as a table in the terminal.
## example
tsv_examples/animals.tsv
```
IQ RANK	animal	diet
25	squid	carnivore
24	spider	carnivore
23	ants	omnivore
22	baboons	carnivore
21	sea lion	carnivore
20	orangutans	omnivore
19	pigeons	omnivore
18	crows	omnivore
17	sheep	herbivore
16	raccoons	omnivore
15	horses	herbivore
14	rhesus monkeys	omnivore
13	falcons	carnivore
12	rats	omnivore
11	owls	carnivore
10	cats	carnivore
9	squirrels	omnivore
8	elephants	herbivore
7	octopus	carnivore
6	dogs	carnivore
5	whales	carnivore
4	parrots	omnivore
3	bottlenose dolphins	carnivores
2	pigs	omnivores
1	chimpanzees	omnivores
```
./tsv tsv_examples/animals.tsv
```
.--------------------------------------------,
| IQ RANK | animal              | diet       |
|--------------------------------------------|
| 25      | squid               | carnivore  |
|--------------------------------------------|
| 24      | spider              | carnivore  |
|--------------------------------------------|
| 23      | ants                | omnivore   |
|--------------------------------------------|
| 22      | baboons             | carnivore  |
|--------------------------------------------|
| 21      | sea lion            | carnivore  |
|--------------------------------------------|
| 20      | orangutans          | omnivore   |
|--------------------------------------------|
| 19      | pigeons             | omnivore   |
|--------------------------------------------|
| 18      | crows               | omnivore   |
|--------------------------------------------|
| 17      | sheep               | herbivore  |
|--------------------------------------------|
| 16      | raccoons            | omnivore   |
|--------------------------------------------|
| 15      | horses              | herbivore  |
|--------------------------------------------|
| 14      | rhesus monkeys      | omnivore   |
|--------------------------------------------|
| 13      | falcons             | carnivore  |
|--------------------------------------------|
| 12      | rats                | omnivore   |
|--------------------------------------------|
| 11      | owls                | carnivore  |
|--------------------------------------------|
| 10      | cats                | carnivore  |
|--------------------------------------------|
| 9       | squirrels           | omnivore   |
|--------------------------------------------|
| 8       | elephants           | herbivore  |
|--------------------------------------------|
| 7       | octopus             | carnivore  |
|--------------------------------------------|
| 6       | dogs                | carnivore  |
|--------------------------------------------|
| 5       | whales              | carnivore  |
|--------------------------------------------|
| 4       | parrots             | omnivore   |
|--------------------------------------------|
| 3       | bottlenose dolphins | carnivores |
|--------------------------------------------|
| 2       | pigs                | omnivores  |
|--------------------------------------------|
| 1       | chimpanzees         | omnivores  |
'--------------------------------------------'
```
## Issues
Will fail if your textfile contains any carriage returns (like when you get them from a Windows machine), or if the text contains any non-ASCII characters. Strings containing things like "→∞" or "ẟY/ẟX" will cause a problem. Might fix these later.

