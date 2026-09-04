# CS61C Projects

Course: **UC Berkeley CS61C — Fall 2020**

This repository is used to organize my implementations and notes for the CS61C Fall 2020 projects.

## Starter Repositories

Clone the official starter repositories:

```bash
cd ~/project_cs61c

git clone https://github.com/61c-teach/fa20-proj1-starter.git
git clone https://github.com/61c-teach/fa20-proj2-starter.git
git clone https://github.com/61c-teach/fa20-proj3-starter.git
git clone https://github.com/61c-teach/fa20-proj4-starter.git
```

Resulting directory structure:

```text
project_cs61c/
├── fa20-proj1-starter/
├── fa20-proj2-starter/
├── fa20-proj3-starter/
└── fa20-proj4-starter/
```

## Creating a Personal Study Repository

If you want to manage all CS61C projects in a single GitHub repository, use the parent directory as a monorepo.

### 1. Remove nested Git repositories

Each starter repository is originally its own Git repository. Remove the nested `.git` directories before managing them from the parent repository:

```bash
rm -rf fa20-proj1-starter/.git
rm -rf fa20-proj2-starter/.git
rm -rf fa20-proj3-starter/.git
rm -rf fa20-proj4-starter/.git
```

This removes only the Git metadata; the project source files are preserved.

### 2. Initialize the parent repository

```bash
cd ~/project_cs61c
git init
git branch -M main
```

### 3. Connect your GitHub repository

Create an empty repository on GitHub, for example:

```text
cs61c-projects
```

Then add it as the main remote:

```bash
git remote add origin https://github.com/<username>/cs61c-projects.git
```

Verify:

```bash
git remote -v
```

### 4. Optionally keep the official repositories as upstream remotes

```bash
git remote add upstream-proj1 https://github.com/61c-teach/fa20-proj1-starter.git
git remote add upstream-proj2 https://github.com/61c-teach/fa20-proj2-starter.git
git remote add upstream-proj3 https://github.com/61c-teach/fa20-proj3-starter.git
git remote add upstream-proj4 https://github.com/61c-teach/fa20-proj4-starter.git
```

This gives the repository a clear separation:

```text
origin          -> personal GitHub repository
upstream-proj1  -> official Project 1 starter
upstream-proj2  -> official Project 2 starter
upstream-proj3  -> official Project 3 starter
upstream-proj4  -> official Project 4 starter
```

### 5. Commit projects independently

Projects can still be committed one directory at a time:

```bash
git add fa20-proj1-starter
git commit -m "Complete CS61C Project 1"
git push -u origin main
```

For later projects:

```bash
git add fa20-proj2-starter
git commit -m "Add CS61C Project 2"
git push
```

The final repository structure becomes:

```text
cs61c-projects/
├── README.md
├── fa20-proj1-starter/
├── fa20-proj2-starter/
├── fa20-proj3-starter/
└── fa20-proj4-starter/
```

This keeps all CS61C work in one repository while preserving each project as a separate directory.
