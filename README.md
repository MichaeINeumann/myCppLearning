# C++ learning project: Calculator with CI and Catch2

![CI](https://github.com/MichaeINeumann/myCppLearning/actions/workflows/ci.yml/badge.svg)
![MIT License](https://img.shields.io/badge/license-MIT-blue.svg)


This is a learning project to deepen your knowledge of the **C++** language and the practical application of **modern development methods**:

- Object orientation
- Error handling with `std::optional
- Unit testing with **Catch2**
- Build system with **CMake**
- Automated tests with **GitHub Actions**
- Optional extension with **Qt6**

## Goal
Learn how to work professionally in C++ - with a complete GitHub workflow, clean code and automated quality assurance.

## Make a contribution

Would you like to join in or improve the code?

1. **Forke** the project
2. Create a branch:
    ```bash
    git checkout -b feature/was-auch-immer

3. Add your code and test locally:
    ```bash
    cmake -S . -B build -G Ninja
    cmake --build build
    ./build/runTests

4. Commit + Push:
    ```bash
    git commit -m "feat: cooles neues Feature"
    git push origin feature/was-auch-immer

5. Make a pull request
Each pull request is automatically tested by GitHub Actions. Only if all tests pass is it merged.

## Naming-Tipp für Branches
| Art         | Example                     |
| ----------- | --------------------------- |
| Feature     | `feature/pow-support`       |
| Bugfix      | `bugfix/pow-edgecase-nan`   |
| Refactoring | `refactor/calculate-method` |

## Lizenz
This project is under the [MIT-Lizenz](./LICENSE). 
This project may be used freely - **without guarantee**. Anyone who finds it useful is welcome to fork or extend it.


