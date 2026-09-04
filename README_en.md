CS61C Fall 2020 — Projects & Study Notes
Personal implementations, experiments, and study notes for
UC Berkeley CS61C — Great Ideas in Computer Architecture, Fall 2020

Overview

This repository contains my personal implementations and study notes for UC Berkeley CS61C Fall 2020.

The repository is organized as a monorepo, with each course project stored in a separate directory.

The main focus is not only to complete the assignments, but also to understand the underlying systems concepts:

C programming
pointers, arrays, and structs
stack and heap
dynamic memory allocation
bit manipulation
RISC-V assembly
calling conventions
CPU datapaths
caches and memory hierarchy
parallelism
performance optimization
Official Starter Repositories

Create a workspace:

mkdir -p ~/project_cs61c
cd ~/project_cs61c

Clone the official Fall 2020 starter repositories:

git clone https://github.com/61c-teach/fa20-proj1-starter.git
git clone https://github.com/61c-teach/fa20-proj2-starter.git
git clone https://github.com/61c-teach/fa20-proj3-starter.git
git clone https://github.com/61c-teach/fa20-proj4-starter.git

Directory structure:

project_cs61c/
├── fa20-proj1-starter/
├── fa20-proj2-starter/
├── fa20-proj3-starter/
└── fa20-proj4-starter/
Personal Monorepo Setup

Each starter project is originally an independent Git repository.

If you want to manage all CS61C projects in a single personal GitHub repository, remove the nested Git metadata first:

rm -rf fa20-proj1-starter/.git
rm -rf fa20-proj2-starter/.git
rm -rf fa20-proj3-starter/.git
rm -rf fa20-proj4-starter/.git

This removes only the nested Git metadata.
The source code remains unchanged.

Initialize the parent repository:

cd ~/project_cs61c

git init
git branch -M main

Create an empty GitHub repository, for example:

cs61c-projects

Connect the local repository:

git remote add origin https://github.com/<username>/cs61c-projects.git

Verify:

git remote -v
Keep Official Repositories as Upstreams

The official starter repositories can optionally be preserved as upstream remotes:

git remote add upstream-proj1 https://github.com/61c-teach/fa20-proj1-starter.git
git remote add upstream-proj2 https://github.com/61c-teach/fa20-proj2-starter.git
git remote add upstream-proj3 https://github.com/61c-teach/fa20-proj3-starter.git
git remote add upstream-proj4 https://github.com/61c-teach/fa20-proj4-starter.git

Remote layout:

origin
└── Personal CS61C repository

upstream-proj1
└── Official Project 1 starter

upstream-proj2
└── Official Project 2 starter

upstream-proj3
└── Official Project 3 starter

upstream-proj4
└── Official Project 4 starter

Check the configuration:

git remote -v
Repository Structure
cs61c-projects/
│
├── README.md
│
├── fa20-proj1-starter/
├── fa20-proj2-starter/
├── fa20-proj3-starter/
└── fa20-proj4-starter/

Each project remains logically independent while being version-controlled by the parent repository.

Git Workflow

Projects can still be committed independently.

For Project 1:

git add fa20-proj1-starter
git commit -m "Complete CS61C Project 1"
git push -u origin main

For Project 2:

git add fa20-proj2-starter
git commit -m "Add CS61C Project 2"
git push

For a specific file:

git add fa20-proj1-starter/gameoflife.c
git commit -m "Fix Game of Life implementation"
git push

Useful commands:

git status
git diff
git log --oneline
git remote -v
Project 1 Example

Project 1 focuses heavily on C programming, memory management, file I/O, and bit manipulation.

Main files:

imageloader.c
steganography.c
gameoflife.c

Typical data flow:

PPM File
   │
   ▼
readData()
   │
   ▼
Image in Heap
   │
   ├── steganography()
   │
   └── life()
   │
   ▼
writeData()
   │
   ▼
PPM Output

Build:

cd fa20-proj1-starter
make gameoflife

Run:

./gameOfLife testInputs/JohnConway.ppm 0x1808

Redirect output to a file:

./gameOfLife testInputs/JohnConway.ppm 0x1808 > output.ppm

Generate multiple frames:

./frames.csh glider 0x1808 10

Memory checking:

make gameoflifememcheck
Development Environment

Typical environment:

Windows
└── WSL
    └── Ubuntu
        ├── GCC
        ├── Make
        └── Git

Typical C build pipeline:

Source Code (.c)
      │
      ▼
Compiler
      │
      ▼
Object File (.o)
      │
      ▼
Linker
      │
      ▼
Executable

Example:

gcc -g -Wall -o gameOfLife gameoflife.o imageloader.o
Study Approach

The goal of this repository is to understand why the code works, rather than only passing the tests.

Examples:

malloc()
↓
Why does this object need heap lifetime?

Color **image
↓
What does each pointer level point to?

row * cols + col
↓
How is a 2D coordinate mapped into linear memory?

(value >> bit) & 1
↓
How do bit masks extract individual bits?

rule = 0x1808
↓
How can multiple Game of Life rules be encoded in one integer?

The broader learning path is:

C
↓
Memory
↓
Assembly
↓
CPU
↓
Cache / Memory Hierarchy
↓
Performance
Disclaimer

This repository is intended for personal study and archival purposes.

If you are currently enrolled in a course using similar assignments, follow your course's academic integrity policy and avoid copying solutions directly.
