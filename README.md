# hello_lib
Basic sample code to start working with different libraries

# Building (Windows)

- Clone the repository
- Inside the repository type: git submodule update --init --recursive
- Build each library in Release mode inside a build folder next to the source folder.
  - mkdir libs\glfw\build
  - cd libs\glfw\build
  - cmake ..\source\glfw\ .
  - Open the .sln
  - Build the solution in Release mode.
  - Code is linked to libs\glfw\build\Release\glfw.lib
- Repeat the same for other libraries.
- Build each example.
  - mkdir hello_opengl\build
  - cd hello_opengl\build
  - cmake ..\source\ .
  - open the .sln
  - Build the solution in Release or Debug mode.
  - Executable is generated at hello_opengl\build\Release\hello_opengl.exe

