# CS61C Fall 2020 — Projects & Study Notes

> UC Berkeley **CS61C — Great Ideas in Computer Architecture, Fall 2020**
> 课程 Project 实现、实验记录与学习笔记。

---

## 项目简介

本仓库用于整理和保存 **UC Berkeley CS61C Fall 2020** 的 Project 实现、实验代码和学习记录。

整个仓库采用 **Monorepo** 的方式管理：

```text
一个课程
    ↓
一个 GitHub Repository
    ↓
每个 Project 一个独立目录
```

学习重点不仅是完成 Project，更重要的是理解背后的计算机系统知识，包括：

* C 语言
* Pointer、Array、Struct
* Stack / Heap
* `malloc` / `free`
* 文件 I/O
* Bit Manipulation
* RISC-V Assembly
* Calling Convention
* CPU Datapath
* Cache / Memory Hierarchy
* Parallelism
* Performance Optimization

---

## 官方 Starter Repository

首先创建一个用于保存 CS61C Project 的目录：

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

得到：

```text
project_cs61c/
├── fa20-proj1-starter/
├── fa20-proj2-starter/
├── fa20-proj3-starter/
└── fa20-proj4-starter/
```

---

## 创建自己的学习仓库

官方的每个 Starter Project 本身都是一个独立 Git Repository。

如果希望使用一个自己的 GitHub Repository 来统一管理所有 Project，可以把：

```text
project_cs61c/
```

作为父级 Git Repository。

### 1. 删除子项目中的 Git Metadata

因为每个目录都是通过 `git clone` 得到的，所以内部都会包含：

```text
.git/
```

如果要交给父目录统一管理，需要删除这些子仓库的 Git Metadata：

```bash
rm -rf fa20-proj1-starter/.git
rm -rf fa20-proj2-starter/.git
rm -rf fa20-proj3-starter/.git
rm -rf fa20-proj4-starter/.git
```

这只会删除 Git 历史和 remote 信息，**不会删除项目源码**。

---

### 2. 初始化父仓库

进入父目录：

```bash
cd ~/project_cs61c
```

初始化 Git：

```bash
git init
git branch -M main
```

最终结构类似：

```text
project_cs61c/
├── .git/
├── README.md
├── fa20-proj1-starter/
├── fa20-proj2-starter/
├── fa20-proj3-starter/
└── fa20-proj4-starter/
```

此时整个 `project_cs61c` 由一个 Git Repository 统一管理。

---

### 3. 连接自己的 GitHub Repository

先在 GitHub 创建一个空仓库，例如：

```text
cs61c-projects
```

然后连接：

```bash
git remote add origin https://github.com/<username>/cs61c-projects.git
```

检查：

```bash
git remote -v
```

应该类似：

```text
origin  https://github.com/<username>/cs61c-projects.git (fetch)
origin  https://github.com/<username>/cs61c-projects.git (push)
```

---

## 保留官方源码仓库

虽然已经删除了各个 Starter Project 内部的 `.git`，仍然可以把官方仓库作为 upstream remote 保存下来。

```bash
git remote add upstream-proj1 https://github.com/61c-teach/fa20-proj1-starter.git
git remote add upstream-proj2 https://github.com/61c-teach/fa20-proj2-starter.git
git remote add upstream-proj3 https://github.com/61c-teach/fa20-proj3-starter.git
git remote add upstream-proj4 https://github.com/61c-teach/fa20-proj4-starter.git
```

检查：

```bash
git remote -v
```

Remote 结构：

```text
origin
└── 自己的 CS61C GitHub Repository

upstream-proj1
└── 官方 Project 1 Starter Repository

upstream-proj2
└── 官方 Project 2 Starter Repository

upstream-proj3
└── 官方 Project 3 Starter Repository

upstream-proj4
└── 官方 Project 4 Starter Repository
```

其中：

```text
origin
```

主要用于：

```bash
git push
```

也就是上传自己的代码。

而：

```text
upstream-proj1
upstream-proj2
upstream-proj3
upstream-proj4
```

主要用于保留官方源码仓库地址，方便之后查看和对照 Starter Code。

---

## Git 工作流

虽然所有 Project 都放在同一个 Git Repository 中，但仍然可以按目录分别提交。

例如完成 Project 1：

```bash
git add fa20-proj1-starter
git commit -m "Complete CS61C Project 1"
git push -u origin main
```

开始 Project 2 后：

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

常用 Git 命令：

```bash
git status
git diff
git log --oneline
git remote -v
```

---

## 仓库结构

最终仓库大致如下：

```text
cs61c-projects/
│
├── README.md
├── README_EN.md
│
├── fa20-proj1-starter/
│   ├── imageloader.c
│   ├── imageloader.h
│   ├── steganography.c
│   ├── gameoflife.c
│   ├── Makefile
│   └── ...
│
├── fa20-proj2-starter/
│   └── ...
│
├── fa20-proj3-starter/
│   └── ...
│
└── fa20-proj4-starter/
    └── ...
```

---

## Project 1 — RGB Game of Life

Project 1 主要用于熟悉 C 语言、内存管理、文件 I/O 和位运算。

主要文件：

```text
imageloader.c
steganography.c
gameoflife.c
```

主要知识点：

* Pointer
* `Color **`
* Struct
* Stack / Heap
* `malloc`
* `free`
* Memory Leak
* File I/O
* PPM P3 Format
* Bit Manipulation
* Conway's Game of Life

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
新的 PPM 输出
```

---

## Project 1 编译与测试

进入目录：

```bash
cd fa20-proj1-starter
```

编译 Game of Life：

```bash
make gameoflife
```

运行：

```bash
./gameOfLife testInputs/JohnConway.ppm 0x1808
```

其中：

```text
testInputs/JohnConway.ppm
```

是输入图片。

```text
0x1808
```

是标准 Conway Game of Life 的规则编码。

如果不希望 PPM 数据直接打印到终端，可以重定向：

```bash
./gameOfLife testInputs/JohnConway.ppm 0x1808 > output.ppm
```

数据流：

```text
JohnConway.ppm
      │
      ▼
  gameOfLife
      │
      ▼
  writeData()
      │
      ▼
    stdout
      │
      ▼
      >
      │
      ▼
 output.ppm
```

连续生成多代：

```bash
./frames.csh glider 0x1808 10
```

检查内存泄漏：

```bash
make gameoflifememcheck
```

---

## 开发环境

学习环境：

```text
Windows
└── WSL
    └── Ubuntu
        ├── GCC
        ├── Make
        └── Git
```

典型 C 程序构建流程：

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

例如：

```bash
gcc -g -Wall -o gameOfLife gameoflife.o imageloader.o
```

其中：

```text
-g
```

加入调试信息。

```text
-Wall
```

开启常见编译警告。

```text
-o gameOfLife
```

指定生成的可执行文件名称。

---

## 学习方式

本仓库更关注：

> **为什么代码这样工作，而不仅仅是让测试通过。**

例如：

```text
Image *img = malloc(sizeof(Image))
↓
为什么这个对象需要放在 Heap？

Color **image
↓
两层 Pointer 分别指向什么？

newimage->image
↓
为什么它是 Color **？

newimage->image[i]
↓
为什么它又变成 Color *？

row * cols + col
↓
为什么二维坐标能够映射到一维内存？

(value >> bit) & 1
↓
为什么这样可以提取某一个 bit？

rule = 0x1808
↓
为什么一个整数能够编码 18 种 Game of Life 状态转移规则？
```

希望逐渐建立这条理解链：

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

也就是从：

```text
“代码怎么写”
```

逐渐深入到：

```text
“代码在内存中发生了什么”
```

再到：

```text
“CPU 最终是怎样执行这些代码的”
```

---

## Academic Integrity

本仓库主要用于个人学习、实验和知识归档。

如果你正在参加使用相同或类似 Project 的课程，请遵守课程的 Academic Integrity Policy，不要直接复制他人的实现。
