# CS61C Fall 2020 — Projects & Study Notes

> Personal implementations, experiments, and study notes for
> **UC Berkeley CS61C — Great Ideas in Computer Architecture, Fall 2020**

[English](#english) · [中文](#中文)

---

# English

## Overview

This repository contains my personal implementations and study notes for **UC Berkeley CS61C Fall 2020**.

The repository is organized as a **monorepo**, with each course project stored in a separate directory.

The main focus is not only to complete the assignments, but also to understand the underlying systems concepts:

* C programming
* pointers, arrays, and structs
* stack and heap
* dynamic memory allocation
* bit manipulation
* RISC-V assembly
* calling conventions
* CPU datapaths
* caches and memory hierarchy
* parallelism
* performance optimization

---

## Official Starter Repositories

Create a workspace:

```bash
mkdir -p ~/project_cs61c
cd ~/project_cs61c
```

Clone the official Fall 2020 starter repositories:

```bash
git clone https://github.com/61c-teach/fa20-proj1-starter.git
git clone https://github.com/61c-teach/fa20-proj2-starter.git
git clone https://github.com/61c-teach/fa20-proj3-starter.git
git clone https://github.com/61c-teach/fa20-proj4-starter.git
```

Directory structure:

```text
project_cs61c/
├── fa20-proj1-starter/
├── fa20-proj2-starter/
├── fa20-proj3-starter/
└── fa20-proj4-starter/
```

---

## Personal Monorepo Setup

Each starter project is originally an independent Git repository.

If you want to manage all CS61C projects in a single personal GitHub repository, remove the nested Git metadata first:

```bash
rm -rf fa20-proj1-starter/.git
rm -rf fa20-proj2-starter/.git
rm -rf fa20-proj3-starter/.git
rm -rf fa20-proj4-starter/.git
```

This removes only the nested Git metadata.
The source code remains unchanged.

Initialize the parent repository:

```bash
cd ~/project_cs61c

git init
git branch -M main
```

Create an empty GitHub repository, for example:

```text
cs61c-projects
```

Connect the local repository:

```bash
git remote add origin https://github.com/<username>/cs61c-projects.git
```

Verify:

```bash
git remote -v
```

---

## Keep Official Repositories as Upstreams

The official starter repositories can optionally be preserved as upstream remotes:

```bash
git remote add upstream-proj1 https://github.com/61c-teach/fa20-proj1-starter.git
git remote add upstream-proj2 https://github.com/61c-teach/fa20-proj2-starter.git
git remote add upstream-proj3 https://github.com/61c-teach/fa20-proj3-starter.git
git remote add upstream-proj4 https://github.com/61c-teach/fa20-proj4-starter.git
```

Remote layout:

```text
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
```

Check the configuration:

```bash
git remote -v
```

---

## Repository Structure

```text
cs61c-projects/
│
├── README.md
│
├── fa20-proj1-starter/
├── fa20-proj2-starter/
├── fa20-proj3-starter/
└── fa20-proj4-starter/
```

Each project remains logically independent while being version-controlled by the parent repository.

---

## Git Workflow

Projects can still be committed independently.

For Project 1:

```bash
git add fa20-proj1-starter
git commit -m "Complete CS61C Project 1"
git push -u origin main
```

For Project 2:

```bash
git add fa20-proj2-starter
git commit -m "Add CS61C Project 2"
git push
```

For a specific file:

```bash
git add fa20-proj1-starter/gameoflife.c
git commit -m "Fix Game of Life implementation"
git push
```

Useful commands:

```bash
git status
git diff
git log --oneline
git remote -v
```

---

## Project 1 Example

Project 1 focuses heavily on C programming, memory management, file I/O, and bit manipulation.

Main files:

```text
imageloader.c
steganography.c
gameoflife.c
```

Typical data flow:

```text
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
```

Build:

```bash
cd fa20-proj1-starter
make gameoflife
```

Run:

```bash
./gameOfLife testInputs/JohnConway.ppm 0x1808
```

Redirect output to a file:

```bash
./gameOfLife testInputs/JohnConway.ppm 0x1808 > output.ppm
```

Generate multiple frames:

```bash
./frames.csh glider 0x1808 10
```

Memory checking:

```bash
make gameoflifememcheck
```

---

## Development Environment

Typical environment:

```text
Windows
└── WSL
    └── Ubuntu
        ├── GCC
        ├── Make
        └── Git
```

Typical C build pipeline:

```text
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
```

Example:

```bash
gcc -g -Wall -o gameOfLife gameoflife.o imageloader.o
```

---

## Study Approach

The goal of this repository is to understand why the code works, rather than only passing the tests.

Examples:

```text
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
```

The broader learning path is:

```text
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
```

---

## Disclaimer

This repository is intended for personal study and archival purposes.

If you are currently enrolled in a course using similar assignments, follow your course's academic integrity policy and avoid copying solutions directly.

---

# 中文

## 项目简介

本仓库用于整理和保存：

**UC Berkeley CS61C — Great Ideas in Computer Architecture（Fall 2020）**

课程 Project 的个人实现、实验代码和学习记录。

整个仓库采用 **Monorepo** 的方式管理：

```text
一个课程
    ↓
一个 GitHub Repository
    ↓
每个 Project 一个独立目录
```

学习重点不仅是完成项目，也包括理解其背后的计算机系统知识：

* C 语言
* 指针、数组和结构体
* Stack / Heap
* `malloc` / `free`
* 位运算
* RISC-V 汇编
* Calling Convention
* CPU Datapath
* Cache
* Memory Hierarchy
* Parallelism
* Performance Optimization

---

## 获取官方 Starter Code

创建课程工作目录：

```bash
mkdir -p ~/project_cs61c
cd ~/project_cs61c
```

Clone Fall 2020 官方 Starter Repository：

```bash
git clone https://github.com/61c-teach/fa20-proj1-starter.git
git clone https://github.com/61c-teach/fa20-proj2-starter.git
git clone https://github.com/61c-teach/fa20-proj3-starter.git
git clone https://github.com/61c-teach/fa20-proj4-starter.git
```

目录结构：

```text
project_cs61c/
├── fa20-proj1-starter/
├── fa20-proj2-starter/
├── fa20-proj3-starter/
└── fa20-proj4-starter/
```

---

## 创建自己的 CS61C 学习仓库

每个 Starter Project 本身都是一个独立 Git Repository。

如果希望使用一个自己的 GitHub Repository 管理所有 Project，可以先删除子项目中的 `.git`：

```bash
rm -rf fa20-proj1-starter/.git
rm -rf fa20-proj2-starter/.git
rm -rf fa20-proj3-starter/.git
rm -rf fa20-proj4-starter/.git
```

这里只删除 Git metadata，不会删除源码。

然后在父目录初始化 Git：

```bash
cd ~/project_cs61c

git init
git branch -M main
```

在 GitHub 创建一个空仓库，例如：

```text
cs61c-projects
```

连接自己的远程仓库：

```bash
git remote add origin https://github.com/<username>/cs61c-projects.git
```

检查：

```bash
git remote -v
```

---

## 保留官方源码仓库

如果希望之后仍然可以方便地查看官方 Starter Repository，可以将它们保存为 upstream remote：

```bash
git remote add upstream-proj1 https://github.com/61c-teach/fa20-proj1-starter.git
git remote add upstream-proj2 https://github.com/61c-teach/fa20-proj2-starter.git
git remote add upstream-proj3 https://github.com/61c-teach/fa20-proj3-starter.git
git remote add upstream-proj4 https://github.com/61c-teach/fa20-proj4-starter.git
```

Remote 结构：

```text
origin
└── 自己的 CS61C GitHub Repository

upstream-proj1
└── 官方 Project 1 Starter

upstream-proj2
└── 官方 Project 2 Starter

upstream-proj3
└── 官方 Project 3 Starter

upstream-proj4
└── 官方 Project 4 Starter
```

检查：

```bash
git remote -v
```

---

## 仓库结构

```text
cs61c-projects/
│
├── README.md
│
├── fa20-proj1-starter/
├── fa20-proj2-starter/
├── fa20-proj3-starter/
└── fa20-proj4-starter/
```

虽然使用一个总仓库进行版本管理，但每个 Project 仍然保持独立目录。

---

## Git 工作流

可以按 Project 单独提交。

例如 Project 1：

```bash
git add fa20-proj1-starter
git commit -m "Complete CS61C Project 1"
git push -u origin main
```

Project 2：

```bash
git add fa20-proj2-starter
git commit -m "Add CS61C Project 2"
git push
```

如果只修改某一个文件：

```bash
git add fa20-proj1-starter/gameoflife.c
git commit -m "Fix Game of Life implementation"
git push
```

常用命令：

```bash
git status
git diff
git log --oneline
git remote -v
```

---

## Project 1 示例

Project 1 主要涉及：

* C Pointer
* Stack / Heap
* `malloc`
* `free`
* Struct
* 文件 I/O
* PPM 图片格式
* Bit Manipulation
* Game of Life
* Memory Leak

主要文件：

```text
imageloader.c
steganography.c
gameoflife.c
```

整体数据流：

```text
PPM 文件
   │
   ▼
readData()
   │
   ▼
Heap 中的 Image
   │
   ├── steganography()
   │
   └── life()
   │
   ▼
writeData()
   │
   ▼
新的 PPM
```

编译：

```bash
cd fa20-proj1-starter
make gameoflife
```

运行：

```bash
./gameOfLife testInputs/JohnConway.ppm 0x1808
```

输出到文件：

```bash
./gameOfLife testInputs/JohnConway.ppm 0x1808 > output.ppm
```

连续生成多代：

```bash
./frames.csh glider 0x1808 10
```

检查内存：

```bash
make gameoflifememcheck
```

---

## 开发环境

常见环境：

```text
Windows
└── WSL
    └── Ubuntu
        ├── GCC
        ├── Make
        └── Git
```

C 程序构建流程：

```text
.c 源文件
   │
   ▼
Compiler
   │
   ▼
.o Object File
   │
   ▼
Linker
   │
   ▼
Executable
```

例如：

```bash
gcc -g -Wall -o gameOfLife gameoflife.o imageloader.o
```

---

## 学习方式

这个仓库的目标不是单纯让测试通过，而是理解：

> **为什么代码要这样写。**

例如：

```text
malloc()
↓
为什么这个对象需要放在 Heap？

Color **image
↓
两层 pointer 分别指向什么？

row * cols + col
↓
为什么二维坐标可以映射到一维内存？

(value >> bit) & 1
↓
为什么这样可以取出一个 bit？

rule = 0x1808
↓
为什么一个整数能够编码多条 Game of Life 规则？
```

希望最终建立这条理解链：

```text
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
```

---

## Disclaimer

本仓库主要用于个人学习与知识归档。

如果你正在参加使用类似作业的课程，请遵守课程的 Academic Integrity Policy，不要直接复制他人的实现。
